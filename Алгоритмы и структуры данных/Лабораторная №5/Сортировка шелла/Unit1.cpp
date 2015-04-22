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
        int a[10];
        for(int i=0;i<10;i++)
                a[i]=StrToInt(StringGrid1->Cells[i][0]);
        int N=10;
        for(int step= N/2;step>0;step/=2)
        {
                for(int i = 0;i<N-step;i++)
                {
                        for(int j=i;j>=0 && a[j] > a[j+step];j--)
                        {
                                int temp = a[j];
                                a[j]=a[j+step];
                                a[j+step]=temp;
                        }
                }
        }
        for(int i=0;i<N;i++)
                StringGrid1->Cells[i][0]=IntToStr(a[i]);
}
//---------------------------------------------------------------------------
