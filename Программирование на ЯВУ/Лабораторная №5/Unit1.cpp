//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ExitClick(TObject *Sender)
{
        Close();        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::exercise1Click(TObject *Sender)
{
        Exercise1->Show();
        Form1->Visible=False;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::exercise2Click(TObject *Sender)
{
        Exercise2->Show();
}
//---------------------------------------------------------------------------
