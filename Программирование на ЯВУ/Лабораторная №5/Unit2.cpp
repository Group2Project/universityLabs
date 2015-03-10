//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TExercise1 *Exercise1;
//---------------------------------------------------------------------------
__fastcall TExercise1::TExercise1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TExercise1::ExitClick(TObject *Sender)
{
        Exercise1->Close();
        Form1->Visible=True;
}
//---------------------------------------------------------------------------
void __fastcall TExercise1::CalculateClick(TObject *Sender)
{
        int minP,maxP;
        int result = 1;
        int a[10];
        for (int i=0;i<10;i++)
                a[i]=StrToInt(StringGrid1->Cells[i][0]);
        int min=a[0];
        int max=a[0];
        bool f=false;
        for (int i=0;i<9;i++)
                for (int j=1;j<10;j++)
                        if ((a[i]==a[j]) && (i!=j)){
                                f=true;
                                break;
                        }
        if (f==false){
                for (int i=1;i<10;i++){
                        if (min>a[i]){
                                min=a[i];
                                minP=i;
                        }
                        if (max<a[i]){
                                max=a[i];
                                maxP=i;
                        }
                }
                if (minP>maxP)
                        for (maxP;maxP<=minP;maxP++)
                                result*=a[maxP];
                else
                        for (minP;minP<=maxP;minP++)
                                result*=a[minP];
                Result->Caption=IntToStr(result);
          }
          else
                Result->Caption=("Числа должны различаться.");

}
//---------------------------------------------------------------------------
void __fastcall TExercise1::ClearClick(TObject *Sender)
{
        for (int i=0;i<10;i++)
                StringGrid1->Cells[i][0]="";
        Result->Caption=" ";        
}
//---------------------------------------------------------------------------


