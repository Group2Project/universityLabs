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

void __fastcall TForm1::FormCreate(TObject *Sender)
{
Image1->Canvas->Brush->Color=clRed;
        Image1->Canvas->Pen->Color=clBlack;
        Image1->Canvas->Pen->Width=2;
        //Машина
        Image1->Canvas->MoveTo(11,111);
        Image1->Canvas->LineTo(60,112);
        Image1->Canvas->LineTo(90,70);
        Image1->Canvas->LineTo(180,70);
        Image1->Canvas->LineTo(230,112);
        Image1->Canvas->LineTo(300,112);
        Image1->Canvas->LineTo(300,170);
        Image1->Canvas->LineTo(280,170);
        Image1->Canvas->Arc(220,140,280,200,280,170,220,170);
        Image1->Canvas->MoveTo(220,170);
        Image1->Canvas->LineTo(100,170);
        Image1->Canvas->Arc(40,140,100,200,100,170,40,170);
        Image1->Canvas->MoveTo(40,170);
        Image1->Canvas->LineTo(12,170);
        Image1->Canvas->LineTo(12,111);      //Ellipse(ширина,высота
        Image1->Canvas->Brush->Color=clBlack;
        Image1->Canvas->Ellipse(230,150,270,190);
        Image1->Canvas->Ellipse(50,150,90,190);
        Image1->Canvas->Arc(310,120,280,150,300,150,300,120);        
}
//---------------------------------------------------------------------------
 