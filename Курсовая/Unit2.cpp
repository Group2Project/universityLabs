//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <Windows.h>
#include "Unit1.h"
#include "Unit2.h"
#include <queue.h>
#include <vector.h>
#include <fstream.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma resource "*.dfm"
TForm2 *Form2;
int X,Y,start_i,end_i;
vector<city> sp_city;
vector<int> path;
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
        GroupBox2->Hide();
        if(N6->Caption=="����� �����")
        {
                editing_mode->Show();
                N6->Caption="��������� ����";
                N7->Enabled=false;
                select_in_mode->ItemIndex=-1;
                editing_mode->ItemIndex=-1;

        }
        else
        {
                if(sp_city.size())
                {
                        for(unsigned int i=0;i<sp_city.size();i++)
                                if(!sp_city[i].get_filled())
                                {
                                        ShowMessage("��������� ����");
                                        return;
                                }
                }
                Button1->Hide();
                editing_mode->Hide();
                select_in_mode->Hide();
                gb_am_city_connect->Hide();
                N7->Enabled=true;
                N6->Caption="����� �����";
                Button4->Hide();
                gb_del_road->Hide();
                select_in_mode->ItemIndex=-1;
                editing_mode->ItemIndex=-1;

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
        DoubleBuffered = true;
        gb_del_road->Hide();
        GroupBox2->Hide();
        Button4->Hide();
}

//---------------------------------------------------------------------------

void __fastcall TForm2::select_in_modeClick(TObject *Sender)
{
        CSpinEdit1->Value = 0;
        gb_am_city_connect->Show();
        if(!select_in_mode->ItemIndex && select_in_mode->Visible && !editing_mode->ItemIndex)
        {
                gb_am_city_connect->Caption="���������� �����";
                Button1->Hide();
                test_arrow=false;
                gb_del_road->Hide();
                Button4->Hide();

        }
        if(select_in_mode->ItemIndex && select_in_mode->Visible && !editing_mode->ItemIndex)
        {
                gb_am_city_connect->Caption="�������������";
                Button1->Show();
                test_arrow=false;
                Button4->Hide();
                gb_del_road->Hide();
        }
        if(editing_mode->ItemIndex && !select_in_mode->ItemIndex)
        {
                gb_am_city_connect->Hide();
                Button4->Show();
                gb_del_road->Hide();
                Button1->Hide();
                test_arrow=false;
        }
        if(editing_mode->ItemIndex && select_in_mode->ItemIndex)
        {
                gb_am_city_connect->Hide();
                gb_del_road->Show();
                Button1->Hide();
                Button4->Show();
                test_arrow=false;
        }

}
//---------------------------------------------------------------------------

void __fastcall TForm2::editing_modeClick(TObject *Sender)
{
        if(!editing_mode->ItemIndex && editing_mode->Visible)
        {
                select_in_mode->Show();
                select_in_mode->Caption=("����");
                select_in_mode->ItemIndex=0;
                gb_am_city_connect->Show();
                Button4->Hide();
                gb_del_road->Hide();
        }
        if(editing_mode->ItemIndex && editing_mode->Visible)
        {
                select_in_mode->Caption=("��������");
                gb_am_city_connect->Hide();
                select_in_mode->ItemIndex=0;
                select_in_mode->Show();
                Button1->Hide();
                Button4->Show();
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::N7Click(TObject *Sender)
{
        if(!sp_city.size())
        {
                ShowMessage("������� ����");
                return;
        }
        else
        {
                GroupBox2->Show();
        }
}

//----------------------------------------------------------------------------

void __fastcall TForm2::Image1MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
        ::X=X;
        ::Y=Y;
        int select_unit = test_circle(X,Y);
        Image1->ShowHint = false;
        if(select_unit!=-1)
        {
                Image1->ShowHint=true;
                Image1->Hint=(IntToStr(sp_city[select_unit].get_number()) + " ��������� " + IntToStr(sp_city[select_unit].get_road_filled()) + " ����� �� " + IntToStr(sp_city[select_unit].get_amount()));
        }
}
//---------------------------------------------------------------------------


void __fastcall TForm2::Button1Click(TObject *Sender)
{
        if(test_arrow)
        {
                test_arrow = false;
                Image1->Canvas->Brush->Color=clBlue;
                Image1->Canvas->Ellipse(sp_city.at(start_i).get_image_X()-8,sp_city.at(start_i).get_image_Y()-8,sp_city.at(start_i).get_image_X()+8,sp_city.at(start_i).get_image_Y()+8);
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Image1Click(TObject *Sender)
{
        if(!select_in_mode->ItemIndex && N6->Caption=="��������� ����" && !editing_mode->ItemIndex)
        {
                /* ������� ����� ������ */
                if(!CSpinEdit1->Value)
                        Image1->Canvas->Brush->Color=clRed;
                else
                        Image1->Canvas->Brush->Color=clBlue;
                Image1->Canvas->Pen->Color=clBlack;
                Image1->Canvas->Pen->Width=1,5;
                Image1->Canvas->Ellipse(X-8,Y-8,X+8,Y+8);
                city *add_city = new city(sp_city.size(),CSpinEdit1->Value,X,Y);
                sp_city.push_back(*add_city);
        }
        if(select_in_mode->ItemIndex && N6->Caption=="��������� ����" && !editing_mode->ItemIndex)
        {
                /* ������� ����� ������ */
                if(!test_arrow)
                {
                        /* ����� ���������� ���� */
                        start_i = test_circle(X,Y);
                        if(sp_city.at(start_i).get_filled() && start_i!=-1)
                                return;
                        if(start_i!=-1)
                        {
                                test_arrow = true;
                                Image1->Canvas->Brush->Color=clYellow;
                                Image1->Canvas->FloodFill(sp_city.at(start_i).get_image_X(),sp_city.at(start_i).get_image_Y(),clBlack,fsBorder);
                        }
                }
                else
                {
                        /* ����� ��������� ����*/
                        if(CSpinEdit1->Value)
                        {
                                end_i = test_circle(X,Y);
                                if(end_i!=-1 && end_i!=start_i)
                                {
                                        Image1->Canvas->Brush->Color=clYellow;
                                        arrow(Image1,start_i,end_i);
                                        sp_city[start_i].set_road_filled(1);
                                        sp_city[start_i].enter_road(sp_city.at(start_i).get_road_filled(),end_i,sp_city.at(end_i).get_image_X(),sp_city.at(end_i).get_image_Y(),CSpinEdit1->Value);
                                        if(sp_city.at(start_i).get_road_filled() == sp_city.at(start_i).get_amount())
                                        {

                                                Image1->Canvas->Brush->Color=clRed;
                                                Image1->Canvas->Ellipse(sp_city.at(start_i).get_image_X()-8,sp_city.at(start_i).get_image_Y()-8,sp_city.at(start_i).get_image_X()+8,sp_city.at(start_i).get_image_Y()+8);
                                                test_arrow = false;
                                                sp_city.at(start_i).set_filled(true);
                                        }
                                        CSpinEdit1->Value=0;
                                }
                        }
                        else
                        {
                                ShowMessage("������� ������ ������");
                        }
                }
        }
        if(editing_mode->ItemIndex && N6->Caption=="��������� ����")
        {
                /* �������� ������ */
                if(!select_in_mode->ItemIndex)
                {
                        int del_i = test_circle(X,Y);
                        if(del_i!=-1)
                        {
                                rebuild_sp_city(del_i);
                                del_unit(del_i,Image1);
                                rebuild_map(Image1);
                        }
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button2Click(TObject *Sender)
{
        start_i = CSpinEdit3->Value;
        if(!sp_city[start_i].get_amount() && !sp_city[start_i].get_road_filled())
                return;
        end_i = CSpinEdit4->Value;
        int k = sp_city[start_i].find_road(end_i);
        if(k!=-1)
        {
                sp_city[start_i].set_amount(sp_city[start_i].get_amount()-1);
                sp_city[start_i].set_road_filled(-1);
                sp_city[start_i].rebuild_road(k);
                if(sp_city[start_i].get_amount()==0)
                                sp_city[start_i].set_filled(true);
        }
        rebuild_map(Image1);
}
//---------------------------------------------------------------------------



void __fastcall TForm2::Button3Click(TObject *Sender)
{
                int all_dist(0);
                for(unsigned int i=0;i<sp_city.size();i++)
                        for(int j=0;j<sp_city[i].get_amount();j++)
                                all_dist+=sp_city[i].get_road(j,3);
                if(all_dist > 100)
                {
                        ShowMessage("���� �� ������ #1");
                        return;
                }
                if(!test_degree())
                {
                        ShowMessage("���� �� ������ #2");
                        return;
                }
                int **ms = new int *[sp_city.size()];
                for(unsigned int i=0;i<sp_city.size();i++)
                {
                        ms[i]=new int[sp_city.size()];
                        for(unsigned int j=0;j<sp_city.size();j++)
                                ms[i][j]=0;
                }
                for(unsigned int i=0;i<sp_city.size();i++)
                        for(int j=0;j<sp_city[i].get_amount();j++)
                                ms[i][sp_city[i].get_road(j,0)] = 1;
                path.clear();
                int start = CSpinEdit2->Value;
                search_euler (start, ms, path);
                ofstream f1;
                f1.open("rand1.txt");
                for(unsigned int i=0;i<path.size();i++)
                {
                        int r;
                        r = path[i];
                        f1 << r << '\n';
                }
                f1.close();
                
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button4Click(TObject *Sender)
{
        sp_city.clear();
        rebuild_map(Image1);
}
//---------------------------------------------------------------------------



