//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <Windows.h>
#include "Unit1.h"
#include "Unit2.h"
#include <queue.h>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma resource "*.dfm"
TForm2 *Form2;
int X,Y,all_cities(0),start_X,start_Y,end_X,end_Y;
city *head,*last_added;
bool test_arrow(false);


//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action)
{
        Form1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N5Click(TObject *Sender)
{
        Form1->Close();        
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N4Click(TObject *Sender)
{
        MessageBox(NULL, "���������� ������� ������ ��-41�\n\t������� ������.", "�����������", MB_OK | MB_ICONASTERISK);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N6Click(TObject *Sender)
{
        if(N6->Caption=="����� �����")
        {
                editing_mode->Show();
                N6->Caption="��������� ����";
                gb_am_city_connect->Show();
                N7->Enabled=false;
                
        }
        else
        {
                if(all_cities)
                {
                        city *test_filled = head;
                        while(test_filled!=last_added->next)
                        {
                                if(!test_filled->get_filled())
                                {
                                        ShowMessage("�� ��� ���� ���������");
                                        return;
                                }
                                test_filled = test_filled->next;
                        }
                }
                editing_mode->Hide();
                select_in_mode->Hide();
                gb_am_city_connect->Hide();
                N7->Enabled=true;
                N6->Caption="����� �����";
        }
        if(!editing_mode->ItemIndex && editing_mode->Visible)
                select_in_mode->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormCreate(TObject *Sender)
{
        select_in_mode->Hide();
        editing_mode->Hide();
        gb_am_city_connect->Hide();
        Image1->Canvas->Brush->Color=clBlack;
        DoubleBuffered = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Image1MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
        ::X=X;
        ::Y=Y;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Image1Click(TObject *Sender)
{
        if(!select_in_mode->ItemIndex && N6->Caption=="��������� ����" && !editing_mode->ItemIndex)
        {
                /* ������� ����� ������ */
                Image1->Canvas->Ellipse(X-7,Y-7,X+7,Y+7);
                city *add_city = new city(all_cities,CSpinEdit1->Value,X,Y);
                if(head)
                {
                        last_added->next=add_city;
                        last_added=add_city;
                }
                else
                        last_added=head=add_city;
                all_cities++;
        }
        if(select_in_mode->ItemIndex && N6->Caption=="��������� ����" && !editing_mode->ItemIndex)
        {
                static city *start_city;
                static int road_count;
                static int road_count_filled;
                /* ������� ����� ������ */
                if(!test_arrow)
                {
                        /* ����� ���������� ���� */
                        start_X = X;
                        start_Y = Y;
                        int m = test_circle(start_X,start_Y);
                        start_city = head;
                        while(start_city!=last_added->next)
                        {
                                if(start_city->get_number() == m)
                                {
                                        break;
                                }
                                start_city=start_city->next;
                        }
                        if(start_city->get_filled())
                                return;
                        road_count = start_city->get_amount();
                        road_count_filled = 0;
                        if(m!=-1 && start_city->get_amount())
                        {
                                test_arrow = true;
                        }
                }
                else
                {
                        /* ����� ��������� ����*/
                                end_X = X;
                                end_Y = Y;
                                int m = test_circle(end_X,end_Y);
                                /*city *end_city = head;
                                while(end_city!=last_added->next)
                                {
                                        if(end_city->get_number() == m)
                                        {
                                                break;
                                        }
                                        end_city=end_city->next;
                                }
                                */
                                if(m!=-1)
                                {
                                        arrow(Image1,start_X,start_Y,end_X,end_Y);
                                        road_count_filled++;
                                        start_city->enter_road(road_count_filled,m,end_X,end_Y,CSpinEdit1->Value);
                                        if(road_count_filled == road_count)
                                        {
                                                test_arrow = false;
                                                start_city->set_filled(true);
                                        }
                                }
                }

        }
        test_label->Caption=IntToStr(all_cities);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::select_in_modeClick(TObject *Sender)
{
        if(!select_in_mode->ItemIndex && select_in_mode->Visible && !editing_mode->ItemIndex)
        {
                gb_am_city_connect->Show();
                gb_am_city_connect->Caption="���������� �����";

        }
        if(select_in_mode->ItemIndex && select_in_mode->Visible && !editing_mode->ItemIndex)
        {
                gb_am_city_connect->Show();
                gb_am_city_connect->Caption="�������������";
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::editing_modeClick(TObject *Sender)
{
        if(!editing_mode->ItemIndex && editing_mode->Visible)
        {
                select_in_mode->Show();
                select_in_mode->Caption=("����");
                gb_am_city_connect->Show();
        }
        if(editing_mode->ItemIndex && editing_mode->Visible)
        {
                select_in_mode->Caption=("��������");
                gb_am_city_connect->Hide();
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::N7Click(TObject *Sender)
{
        if(!all_cities)
        {
                ShowMessage("������� ����");
                return;
        }
        else
        {
                const int INF = 0;
                queue<int> turn;
                city *find = head;
                int unit = CSpinEdit2->Value;
                bool *flag = new bool[all_cities];
                int **A = new int *[all_cities];     //������� ���������
                for(int i=0;i<all_cities;i++)
                        A[i] = new int[all_cities];
                for(int i=0;i<all_cities;i++)
                {
                        for(int j=0;j<all_cities;j++)
                                A[i][j]=INF;
                        flag[i] = false;   //1 ����
                }
                int r=0;
                while(find!=last_added->next)
                {
                        for(int i=0;i<find->get_amount();i++)
                        {
                                int dd = find->get_road(i,0);
                                A[r][dd] = find->get_road(i,3);
                        }
                        r++;
                        find=find->next;
                }
                int start_unit = unit;
                turn.push(start_unit);   //2 ����
                flag[start_unit]=true;
                while(!turn.empty())
                {
                        for(int i=0;i<all_cities;i++)
                                if(A[unit][i] && flag[i])
                                {
                                        turn.push(i);
                                        flag[i]=true;
                                }
                        turn.pop();
                        unit=turn.front();
                }




                /*
                int *predok=new int[all_cities]; //���������� ����
                int *D=new int[all_cities];    //���������� ���������� �� ������

                for(int i=0;i<all_cities;i++)
                {
                        predok[i]=nach;
                        flag[i]=false;
                        D[i]=A[nach][i];
                }
                flag[nach]=true;
                predok[nach]=0;
                for(int i=0;i<all_cities;i++)
                {
                        int k=0;
                        int minras = INF;
                        for(int j=0;j<all_cities;j++)
                        {
                                if(!flag[j]&&minras > D[i])
                                {
                                        minras=D[j];
                                        k = j;
                                }
                        }
                        flag[k]=true;
                        for(int j=0;j<all_cities;j++)
                        {
                                if(!flag[j]&&D[j]>D[k]+A[k][j])
                                {
                                        D[j]=D[k]+A[k][j];
                                        predok[j]=k;
                                }
                        }
                }
                for(int i=0;i<all_cities;i++)
                        StringGrid1->Cells[i][0]=IntToStr(D[i]); */

        }
}
//---------------------------------------------------------------------------

