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

        Image2->Canvas->Pen->Color=clBlack;
        Image2->Canvas->Pen->Width=2;
        //Машина
        Image2->Canvas->MoveTo(12,41);
        Image2->Canvas->LineTo(60,42);
        Image2->Canvas->LineTo(90,0);
        Image2->Canvas->LineTo(180,0);
        Image2->Canvas->LineTo(230,42);
        Image2->Canvas->LineTo(300,42);
        Image2->Canvas->LineTo(300,100);
        Image2->Canvas->LineTo(280,100);
        Image2->Canvas->Arc(220,70,280,130,280,100,220,100);
        Image2->Canvas->MoveTo(220,100);
        Image2->Canvas->LineTo(100,100);
        Image2->Canvas->Arc(40,70,100,130,100,100,40,100);
        Image2->Canvas->MoveTo(40,100);
        Image2->Canvas->LineTo(12,100);
        Image2->Canvas->LineTo(12,41);      //Ellipse(ширина,высота
        Image2->Canvas->Brush->Color=clBlack;
        Image2->Canvas->Ellipse(230,80,270,120);
        Image2->Canvas->Ellipse(50,80,90,120);
        Image2->Canvas->Arc(310,50,280,80,300,80,300,50);
        Image2->Canvas->Brush->Color=clRed;
        Image2->Canvas->FloodFill(128,48,clBlack,fsBorder);
        Image2->Canvas->Brush->Color=clWhite;
        Image2->Canvas->FloodFill(1,1,clBlack,fsBorder);
        Image1->Canvas->FloodFill(128,48,clRed,fsBorder);

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
        Timer1->Interval=50;
        Timer1->Enabled=true;        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
        Image1->Left -= 10;
}
//---------------------------------------------------------------------------
