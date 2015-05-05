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
        StringGrid1->Cells[0][0]="9";
        StringGrid1->Cells[1][0]="8";
        StringGrid1->Cells[2][0]="7";
        StringGrid1->Cells[3][0]="6";
        StringGrid1->Cells[4][0]="5";
        StringGrid1->Cells[5][0]="4";
        StringGrid1->Cells[6][0]="3";
        StringGrid1->Cells[7][0]="2";
        StringGrid1->Cells[8][0]="1";
        StringGrid1->Cells[9][0]="0";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        int n = 10;
        int *a = new int[n];
        for(int i=0;i<n;i++)
                a[i]=StrToInt(StringGrid1->Cells[i][0]);
        int mid = n/2;
        if(n%2==1)
                mid++;
        int h = 1;
        int *c;
        int step;
        c = (int*)malloc(n*sizeof(int));
        while(h < n) {
                step = h;
                int i = 0;
                int j = mid;
                int k = 0;
                while(step <= mid) {
                        while((i<step) && (j<n) && (j<(mid+step))) {
                                if(a[i] < a[j]) {
                                        c[k] = a[i];
                                        i++;
                                        k++;
                                }
                                else {
                                        c[k] = a[j];
                                        j++;
                                        k++;
                                }
                        }
                        while(i<step) {
                                c[k] = a[i];
                                i++;
                                k++;
                        }
                        while((j < (mid+step)) && (j<n)) {
                                c[k] = a[j];
                                j++;
                                k++;
                        }
                        step = step + h;
                }
                h = h * 2;
                for(i=0;i<n;i++)
                        a[i]=c[i];
        }
        for(int i=0;i<n;i++)
                StringGrid2->Cells[i][0]=IntToStr(c[i]);
  }
//---------------------------------------------------------------------------
