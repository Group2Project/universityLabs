//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <Windows.h>
#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include <queue.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma resource "*.dfm"
TForm2 *Form2;
int X,Y,all_cities(0);
city *head,*last_added;
bool test_arrow(false);
void input_city();
void input_road();
void delete_city();
void delete_road();
enum mode{NOTHING,IN_CITY,IN_ROAD,DEL_CITY,DEL_ROAD};
int current_mode;

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


void __fastcall TForm2::FormCreate(TObject *Sender)
{
        select_in_mode->Hide();
        editing_mode->Hide();
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


void __fastcall TForm2::select_in_modeClick(TObject *Sender)
{
        if(!editing_mode->ItemIndex && !select_in_mode->ItemIndex)
                current_mode = IN_CITY;
        if(!editing_mode->ItemIndex && select_in_mode->ItemIndex)
                current_mode = IN_ROAD;
        if(editing_mode->ItemIndex && !select_in_mode->ItemIndex)
                current_mode = DEL_CITY;
        if(editing_mode->ItemIndex && select_in_mode->ItemIndex)
                current_mode = DEL_ROAD;
        test_label->Caption = IntToStr(current_mode);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::editing_modeClick(TObject *Sender)
{
        select_in_mode->Show();
        if(!editing_mode->ItemIndex)
                select_in_mode->Caption=("Ввод");
        else
                select_in_mode->Caption=("Удаление");
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N6Click(TObject *Sender)
{
        if(N6->Caption=="Закончить ввод")
        {
                N6->Caption=("Режим ввода");
                editing_mode->Hide();
                select_in_mode->Hide();
                editing_mode->ItemIndex=-1;
                select_in_mode->ItemIndex=-1;
                current_mode=NOTHING;
        }
        else
        {
                N6->Caption=("Закончить ввод");
                editing_mode->Show();
        }
}
//---------------------------------------------------------------------------

void input_city()
{

}

//---------------------------------------------------------------------------

void input_road()
{

}

//----------------------------------------------------------------------------

void delete_city()
{

}

//----------------------------------------------------------------------------

void delete_road()
{

}

//---------------------------------------------------------------------------
void __fastcall TForm2::Image1Click(TObject *Sender)
{
        switch(current_mode)
        {
                case IN_CITY:
                        input_city();
                        break;
                case IN_ROAD:
                        input_road();
                        break;
                case DEL_CITY:
                        delete_city();
                        break;
                case DEL_ROAD:
                        delete_road();
                        break;
                default:
                        break;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button1Click(TObject *Sender)
{
        Form3->Show();
}
//---------------------------------------------------------------------------

