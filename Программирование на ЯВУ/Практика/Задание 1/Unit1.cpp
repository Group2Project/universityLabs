//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
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
        int num = CSpinEdit1->Value;
        int i=2;
        AnsiString mnog;
        while(i<=num)
        {
                if(num%i==0)
                {
                        mnog+=IntToStr(i);
                        num /= i;
                        if(num > 1)
                                mnog+="*";
                }
                else
                        i++;
        }
        Edit2->Text=mnog;
}
//---------------------------------------------------------------------------

