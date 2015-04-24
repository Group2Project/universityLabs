//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <Windows.h>
#include "Unit1.h"
#include "Unit2.h"

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
        MessageBox(NULL, "Разработал студент группы ПО-41б\n\tАлябьев Сергей.", "Разработчик", MB_OK | MB_ICONASTERISK);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N6Click(TObject *Sender)
{
        if(N6->Caption=="Режим ввода")
        {
                editing_mode->Show();
                N6->Caption="Закончить ввод";
                gb_am_city_connect->Show();
        }
        else
        {
                editing_mode->Hide();
                select_in_mode->Hide();
                gb_am_city_connect->Hide();
                N6->Caption="Режим ввода";
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
        static int road_count;
        static int road_count_filled;
        if(!select_in_mode->ItemIndex && N6->Caption=="Закончить ввод" && !editing_mode->ItemIndex)
        {
                road_count = CSpinEdit1->Value;
                Image1->Canvas->Ellipse(X-7,Y-7,X+7,Y+7);
                city *add_city = new city(all_cities,road_count,X,Y);
                if(head)
                {
                        last_added->next=add_city;
                        last_added=add_city;
                }
                else
                        last_added=head=add_city;
                all_cities++;
        }
        if(select_in_mode->ItemIndex && N6->Caption=="Закончить ввод" && !editing_mode->ItemIndex)
        {
                if(!test_arrow)
                {
                        start_X = X;
                        start_Y = Y;
                        int m = test_circle(start_X,start_Y);
                        if(m!=-1)
                        {
                                test_arrow = true;
                        }
                }
                else
                {
                        if
                                end_X = X;
                                end_Y = Y;
                                int m = test_circle(end_X,end_Y);
                                city *add_city = head;
                                while(add_city!=last_added->next)
                                {
                                        if(add_city->get_number() == m)
                                        {
                                                break;
                                        }
                                        add_city=add_city->next;
                                }
                                if(add_city->test_filled())
                                {
                                        test_arrow = false;
                                        return;
                                }
                                if(m!=-1)
                                {

                                        arrow(Image1,start_X,start_Y,X,Y);
                                        test_arrow = false;
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
                gb_am_city_connect->Caption="Количество дорог";

        }
        if(select_in_mode->ItemIndex && select_in_mode->Visible && !editing_mode->ItemIndex)
        {
                gb_am_city_connect->Show();
                gb_am_city_connect->Caption="Протяженность";
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::editing_modeClick(TObject *Sender)
{
        if(!editing_mode->ItemIndex && editing_mode->Visible)
        {
                select_in_mode->Show();
                select_in_mode->Caption=("Ввод");
                gb_am_city_connect->Show();
        }
        if(editing_mode->ItemIndex && editing_mode->Visible)
        {
                select_in_mode->Caption=("Удаление");
                gb_am_city_connect->Hide();
        }
}
//---------------------------------------------------------------------------
