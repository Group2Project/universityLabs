//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
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

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        int x = StrToInt(Edit1->Text);
        if (x/10<=5 && x%10<=5 && x>=0)
        {
                switch (x/10)
                {
                        case 0:
                                Label4->Caption=("Zero");
                                break;
                        case 1:
                                Label4->Caption=("One");
                                break;
                        case 2:
                                Label4->Caption=("Two");
                                break;
                        case 3:
                                Label4->Caption=("Three");
                                break;
                        case 4:
                                Label4->Caption=("Four");
                                break;
                        case 5:
                                Label4->Caption=("Five");
                                break;
                }
                switch (x%10)
                {
                        case 0:
                                Label5->Caption=("Zero");
                                break;
                        case 1:
                                Label5->Caption=("One");
                                break;
                        case 2:
                                Label5->Caption=("Two");
                                break;
                        case 3:
                                Label5->Caption=("Three");
                                break;
                        case 4:
                                Label5->Caption=("Four");
                                break;
                        case 5:
                                Label5->Caption=("Five");
                                break;
                }
        }
        else
                ShowMessage("Неправильное число");

}
//---------------------------------------------------------------------------


