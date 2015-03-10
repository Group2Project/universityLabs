//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma resource "*.dfm"
int m;
float *mas;
void num_elem(float *a,int n,int nmin,int nmax);
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        m=CSpinEdit1->Value;
        StringGrid1->ColCount=m;
        Panel1->Hide();
        StringGrid1->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
        Close();        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
        for(int i=0;i<m;i++)
                StringGrid1->Cells[i][0]="";
        Panel1->Show();
        StringGrid1->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
        mas=new float[m];
        for(int i=0;i<m;i++)
                mas[i]=StrToFloat(StringGrid1->Cells[i][0]);
        num_elem(mas,m,0,0);
}
//---------------------------------------------------------------------------
void num_elem(float *a,int n,int nmin,int nmax)
{
        int min=a[0];
        int max=a[0];
        for(int i=0;i<n;i++){
                if(a[i]<min){
                        min=a[i];
                        nmin=i;
                }
                if(a[i]>max){
                        max=a[i];
                        nmax=i;
                }
        }
        ShowMessage("Позиция минимального числа " +FloatToStr(nmin) + "\n" + "Позиция максимального числа " +FloatToStr(nmax));
        
}
