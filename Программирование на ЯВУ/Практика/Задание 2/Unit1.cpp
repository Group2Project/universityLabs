//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
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
        StringGrid1->Show();
        StringGrid1->RowCount=CSpinEdit1->Value;
        StringGrid1->ColCount=CSpinEdit2->Value;
        GroupBox1->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
        int **matrix;
        int n = CSpinEdit1->Value;
        int m = CSpinEdit2->Value;
        matrix = new int *[n];
        for(int i=0;i<n;i++)
                matrix[i]=new int[m];
        for(int i=0;i<n;i++)
                for(int j=0;j<m;j++)
                        matrix[i][j]=StrToInt(StringGrid1->Cells[j][i]);
        int min_j;
        int min_i;
        bool test(true);
        for(int i=0;i<n;i++)
        {
                int min = matrix[i][0];
                min_j = 0;
                min_i = 0;
                for(int j=1;j<m;j++)
                        if(matrix[i][j] < min)
                        {
                                min = matrix[i][j];
                                min_j = j;
                                min_i = i;
                        }

                for(int j=0;j<n;j++)
                        if(matrix[i][min_j] < matrix[j][min_j])
                        {
                                test=false;
                                break;
                        }
                if(test)
                        break;
        }
        if(test)
                ShowMessage("Седловая точка имеет координаты:"+IntToStr(min_i) +":"+IntToStr(min_j));

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
        GroupBox1->Show();
        StringGrid1->Hide();
        for(int i=0;i<CSpinEdit1->Value;i++)
                for(int j=0;j<CSpinEdit2->Value;j++)
                        StringGrid1->Cells[j][i] = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
        Close();        
}
//---------------------------------------------------------------------------
