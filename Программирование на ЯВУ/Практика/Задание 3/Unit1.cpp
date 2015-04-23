//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma resource "*.dfm"
TForm1 *Form1;
void sort(int *,int);
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        StringGrid1->ColCount=CSpinEdit1->Value;
        StringGrid1->Show();
        Button1->Hide();
        Button2->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
        int N = CSpinEdit1->Value;
        int *a = new int[N];
        for(int i=0;i<N;i++)
                a[i]=StrToInt(StringGrid1->Cells[i][0]);
        sort(a,N);
        bool test(true);
        for(int i=0;i<N-1;i++)
                if(a[i+1]-a[i]!=1)
                {
                        test=false;
                        break;
                }
        if(test)
                ShowMessage("True!");
        else
                ShowMessage("False!");
}
//---------------------------------------------------------------------------

void sort(int *mas,int K)
{
        for(int step= K/2;step>0;step/=2)
        {
                for(int i = 0;i<K-step;i++)
                {
                        for(int j=i;j>=0 && mas[j] > mas[j+step];j--)
                        {
                                int temp = mas[j];
                                mas[j]=mas[j+step];
                                mas[j+step]=temp;
                        }
                }
        }
}

//----------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
        StringGrid1->Hide();
        Button2->Hide();        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
        for(int i=0;i<CSpinEdit1->Value;i++)
                StringGrid1->Cells[i][0]="";
        StringGrid1->Hide();
        Button2->Hide();
        Button1->Show();
}
//---------------------------------------------------------------------------

