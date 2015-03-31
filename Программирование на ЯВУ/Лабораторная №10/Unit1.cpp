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
        DoubleBuffered = true;
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
        Image2->Canvas->LineTo(12,41);

        Image2->Canvas->Brush->Color=clWhite;
        Image2->Canvas->MoveTo(150,8);
        Image2->Canvas->LineTo(180,8);
        Image2->Canvas->LineTo(220,42);
        Image2->Canvas->LineTo(150,42);
        Image2->Canvas->LineTo(150,8);
        Image2->Canvas->FloodFill(151,9,clBlack,fsBorder);
        Image2->Canvas->Pen->Color=clBlack;

        Image2->Canvas->Brush->Color=clBlack;
        Image2->Canvas->Ellipse(230,80,270,120);
        Image2->Canvas->Ellipse(50,80,90,120);
        Image2->Canvas->Arc(310,50,280,80,300,80,300,50);
        Image2->Canvas->Brush->Color=clRed;
        Image2->Canvas->FloodFill(128,48,clBlack,fsBorder);
        Image2->Canvas->Brush->Color=clWhite;
        Image2->Canvas->FloodFill(1,1,clBlack,fsBorder);

        // Окружение
        Image1->Canvas->Pen->Color=clBlack;
        Image1->Canvas->Pen->Width=2;
        //----Асфальт(Верх)----------------//
        Image1->Canvas->MoveTo(0,280);     //
        Image1->Canvas->LineTo(1249,280);  //
        //---------------------------------//

        //----Асфальт(Низ)----------------//
        Image1->Canvas->MoveTo(0,486);    //
        Image1->Canvas->LineTo(1249,486); //
        //--------------------------------//

        //----Закраска-асфальта----------------------------//
        Image1->Canvas->Brush->Color=RGB(128,128,128);     //
        Image1->Canvas->FloodFill(9,358,clBlack,fsBorder); //
        //-------------------------------------------------//

        //----Разметка--------------------------------------------------//
        Image1->Canvas->Pen->Color=clWhite;                             //
        Image1->Canvas->Brush->Color=clWhite;                           //
        for(int i(0),x1(0),x2(48);i<20;i++)                             //
        {                                                               //
                Image1->Canvas->Rectangle(x1+i*100,375,x2+i*100,391);   //
        }                                                               //
        //--------------------------------------------------------------//

        //----Горизонт-----------------------------//
        Image1->Canvas->Pen->Color=clBlack;        //
        Image1->Canvas->Pen->Width=1;              //
        Image1->Canvas->MoveTo(0,120);             //
        Image1->Canvas->LineTo(Image1->Width,120); //
        //-----------------------------------------//

        //----Трава-и-небо---------------------------------//
        Image1->Canvas->Brush->Color=clLime;               //
        Image1->Canvas->FloodFill(1,121,clBlack,fsBorder); //
        Image1->Canvas->Brush->Color=clHighlight;          //
        Image1->Canvas->FloodFill(0,0,clBlack,fsBorder);   //
        //-------------------------------------------------//

        //----Солнце----------------------------//
        Image1->Canvas->Brush->Color=clYellow;  //
        Image1->Canvas->Ellipse(680,16,760,96); //
        //--------------------------------------//

        Image1->Canvas->Pen->Color=clBlack;
        Image1->Canvas->Brush->Color=clWhite;
        for(int i(0),x1(8),x2(28);i<10;i++)
                Image1->Canvas->Rectangle(x1+i*100,280,x2+i*100,200);





}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
                Image2->Left += 10;
}
//---------------------------------------------------------------------------



void __fastcall TForm1::FormClick(TObject *Sender)
{
        Image2->Left=0;
        Image2->Top=352;
        Timer1->Interval=20;
        Timer1->Enabled=true;
}
//---------------------------------------------------------------------------

