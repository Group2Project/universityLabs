//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <Windows.h>
#include "Unit1.h"
#include "Unit2.h"
#include "class_city.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma resource "*.dfm"
TForm2 *Form2;
int X,Y,all_cities(0);
city *head,*last_added;

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
                select_in_mode->Show();
                N6->Caption="Закончить ввод";

        }
        else
        {
                select_in_mode->Hide();
                gb_am_city_connect->Hide();
                N6->Caption="Режим ввода";
        }
        if(!select_in_mode->ItemIndex && select_in_mode->Visible)
                gb_am_city_connect->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormCreate(TObject *Sender)
{
        select_in_mode->Hide();
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

        if(!select_in_mode->ItemIndex && N6->Caption=="Закончить ввод")
        {
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
        if(select_in_mode->ItemIndex && N6->Caption=="Закончить ввод")
        {

        }
        test_label->Caption=IntToStr(all_cities);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::select_in_modeClick(TObject *Sender)
{
        if(!select_in_mode->ItemIndex && select_in_mode->Visible)
        {
                gb_am_city_connect->Caption="Количество дорог";
        }
        if(select_in_mode->ItemIndex)
        {
                gb_am_city_connect->Caption="Протяженность";
        }
}
//---------------------------------------------------------------------------


