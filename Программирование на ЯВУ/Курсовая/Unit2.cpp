//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <Windows.h>
#include "Unit1.h"
#include "Unit2.h"
#include "class_city.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
int X,Y;
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
        MessageBox(NULL, "���������� ������� ������ ��-41�\n\t������� ������.", "�����������", MB_OK | MB_ICONASTERISK);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::N6Click(TObject *Sender)
{
        if(N6->Caption=="����� �����")
        {
                RadioGroup1->Show();
                N6->Caption="��������� ����";

        }
        else
        {
                RadioGroup1->Hide();
                N6->Caption="����� �����";
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormCreate(TObject *Sender)
{
        RadioGroup1->Hide();
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

        if(!RadioGroup1->ItemIndex && N6->Caption=="��������� ����")

                Image1->Canvas->Ellipse(X-7,Y-7,X+7,Y+7);
        if(RadioGroup1->ItemIndex && N6->Caption=="��������� ����")
        {

        }
}
//---------------------------------------------------------------------------

