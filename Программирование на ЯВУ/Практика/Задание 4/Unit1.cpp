//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <math.h>
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma resource "*.dfm"
TForm1 *Form1;
bool test_line(int,int,int,int,int,int);
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        int n = CSpinEdit1->Value;
        StringGrid1->ColCount = n;
        StringGrid2->ColCount = n;
        GroupBox1->Hide();
        StringGrid1->Show();
        StringGrid2->Show();
        Button3->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
        StringGrid1->Hide();
        StringGrid2->Hide();
        Button3->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
        StringGrid1->Hide();
        StringGrid2->Hide();
        GroupBox1->Show();
        Button3->Hide();
        for(int i=0;i<CSpinEdit1->Value;i++)
        {
                StringGrid1->Cells[i][0]="";
                StringGrid2->Cells[i][0]="";
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
        int n = CSpinEdit1->Value;
        int *mas_X = new int[n];
        int *mas_Y = new int[n];
        for(int i=0;i<n;i++)
        {
                mas_X[i]=StrToInt(StringGrid1->Cells[i][0]);
                mas_Y[i]=StrToInt(StringGrid2->Cells[i][0]);
        }
        if(test_line(1,1,2,2,8,4))
                ShowMessage("�����");
        else
                ShowMessage("no");

}
//---------------------------------------------------------------------------

bool test_line(int X1,int Y1,int X2,int Y2,int X3,int Y3)
{
        double a[3];
        a[0]=sqrt(pow((X2-X1),2)+pow((Y2-Y1),2));
        a[1]=sqrt(pow((X3-X1),2)+pow((Y3-Y1),2));
        a[2]=sqrt(pow((X3-X2),2)+pow((Y3-Y2),2));
        for(int i=0;i<2;i++)
                for(int j=i;j<3;j++)
                        if(a[i]>a[j])
                        {
                                int temp = a[i];
                                a[i]=a[j];
                                a[j]=temp;
                        }
        if(fabs((a[0]+a[1])-a[3]) < 0,00000000000001)
                return true;
        else
                return false;
}
