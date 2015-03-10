//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <math.h>
#include "Unit1.h"
#define PI 3.14159265
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

void __fastcall TForm1::CalculateClick(TObject *Sender)
{

        float side1=StrToFloat(Side1->Text);
        float side2=StrToFloat(Side2->Text);
        float angle=StrToFloat(Angle->Text);
        float area=side1*side2*0.5*sin(angle*PI/180);
        float side3=sqrt(pow(side1,2)+pow(side2,2)-2*side1*side2*cos(angle*PI/180));
        Area->Text=FloatToStr(area);
        Side3->Text=FloatToStr(side3);

}
//----------------------------------------------------------------------------

void __fastcall TForm1::ResetClick(TObject *Sender)
{
        Side1->Text="";
        Side2->Text="";
        Side3->Text="";
        Angle->Text="";
        Area->Text="";        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ExitClick(TObject *Sender)
{
        Close();        
}
//---------------------------------------------------------------------------
