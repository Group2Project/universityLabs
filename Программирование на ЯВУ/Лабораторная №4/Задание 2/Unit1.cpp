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
int x=StrToInt(X->Text);
int n=StrToInt(N->Text);
int i;
int j;
int s=0;
int s1=0;
        for(i = 1;i <= n;i++)
        {
                for(j = n+1;j <= n+10;j++)
                {
                        s1+=(x-j+1)/(x+j) + n;
                }
                s+=s1+i;
        }

Label3->Caption=IntToStr(s);
}
//---------------------------------------------------------------------------
 