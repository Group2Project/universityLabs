//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma resource "*.dfm"
TExercise2 *Exercise2;
int n, *a, *b;
//---------------------------------------------------------------------------
__fastcall TExercise2::TExercise2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TExercise2::ExitClick(TObject *Sender)
{
        Exercise2->Close();
        Form1->Visible=True;
}
//---------------------------------------------------------------------------

void __fastcall TExercise2::ClearClick(TObject *Sender)
{

        for (int i=0;i<n;i++)
                Array1->Cells[i][0]="";
        for (int i=0;i<n;i++)
                Array2->Cells[i][0]="";
        CSpinEdit1->Value=0;
        Array1->Enabled=false;
        Array1->ColCount=1;
        Array2->ColCount=1;
        Panel1->Show();
        Array2->Visible=false;

}
//---------------------------------------------------------------------------


void __fastcall TExercise2::EnterClick(TObject *Sender)
{
        n=CSpinEdit1->Value;
        Array1->ColCount=n;
        Array1->Enabled=true;
        Panel1->Hide();
}
//---------------------------------------------------------------------------



void __fastcall TExercise2::CalculateClick(TObject *Sender)
{
        a=new int[n];
        for(int i=0;i<n;i++)
                a[i]=StrToInt(Array1->Cells[i][0]);
        b=new int[n];
        int i;
        int j=1;
        int m=a[0];
        int z;
        bool c;
        b[0]=a[0];
        for(i=1;i<n;i++)
                if(m!=a[i]){
                        c=false;
                        for(z=0;z<=j;z++)
                                if(b[z]==a[i])
                                        c=true;
                        if(c==false){
                                b[j]=a[i];
                                j++;
                                m=a[i];
                        }
                }
        Array2->ColCount=j;
        for(i=0;i<j;i++)
                Array2->Cells[i][0]=IntToStr(b[i]);
        Array2->Visible=true;
        delete []a;
        delete []b;
}
//---------------------------------------------------------------------------


