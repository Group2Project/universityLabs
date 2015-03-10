//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <math.h>
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
 float xc=StrToFloat(X->Text);
 float d=StrToFloat(D->Text);
 float x=xc;
 float s=0;
 int i;
 for(i = 1;i <= 20;i++)
 {
        x+=d*xc;
        s+=x*x;
 }
 Label3->Caption=FloatToStr(s);
}
//---------------------------------------------------------------------------
