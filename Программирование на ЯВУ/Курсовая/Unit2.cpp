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
                                        ShowMessage("Не все узлы заполнены");
                                        return;
                                }
                                test_filled = test_filled->next;
                        }
                }
                editing_mode->Hide();
                select_in_mode->Hide();
                gb_am_city_connect->Hide();
                N7->Enabled=true;
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
        if(!select_in_mode->ItemIndex && N6->Caption=="Закончить ввод" && !editing_mode->ItemIndex)
        {
                /* Функция ввода города */
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
        if(select_in_mode->ItemIndex && N6->Caption=="Закончить ввод" && !editing_mode->ItemIndex)
        {
                static city *start_city;
                static int road_count;
                static int road_count_filled;
                /* Функция ввода дороги */
                if(!test_arrow)
                {
                        /* Выбор начального узла */
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
                        /* Выбор конечного узла*/
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
void __fastcall TForm2::N7Click(TObject *Sender)
{
        if(!all_cities)
        {
                ShowMessage("Введите граф");
                return;
        }
        else
        {
                
        }
}
//---------------------------------------------------------------------------

