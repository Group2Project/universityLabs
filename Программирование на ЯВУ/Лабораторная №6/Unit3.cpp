//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit3.h"
#include "Unit1.h"
#include <ctime>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma resource "*.dfm"
TForm3 *Form3;
float **matrix;
float *matrix2;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm3::ExitClick(TObject *Sender)
{
        Form1->Visible=true;
        Close();        
}
//---------------------------------------------------------------------------

void __fastcall TForm3::EnterClick(TObject *Sender)
{
        StringGrid1->ColCount=Column->Value;
        StringGrid1->RowCount=String->Value;
        Panel1->Hide();
        Panel2->Visible=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::ClearClick(TObject *Sender)
{
        int n=String->Value;
        int m=Column->Value;
        for(int i=0;i<n;i++){
                for(int j=0;j<m;j++)
                        StringGrid1->Cells[j][i]="";
        }
        Column->Value=0;
        String->Value=0;
        Panel1->Show();
        Panel2->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::CalculateClick(TObject *Sender)
{
        int n=String->Value; //Строка
        int m=Column->Value; //Столбец
        matrix2=new float [n];
        matrix=new float *[n];
        int r;
        for(int i=0;i<n;i++)           //Ввод 2-мерного массива
                matrix[i]=new float[m];
        for(int i=0;i<n;i++)           //Заполнение 2-мерного массива
                for(int j=0;j<m;j++)
                        matrix[i][j]=StrToFloat(StringGrid1->Cells[j][i]);
        for(int i=0;i<n;i++){          //Нахождение наибольших элементов
                matrix2[i]=matrix[i][0]; //Заполнение 1-мерного массива
                for(int j=0;j<m;j++)
                        if(matrix[i][j]>matrix2[i])
                                matrix2[i]=matrix[i][j];
        }
        for(int i=0;i<n-1;i++)
                for(int j=0;j<n-i-1;j++)
                        if(matrix2[j]>matrix2[j+1]){
                                for(int k=0;k<m;k++){
                                        r=matrix[j][k];
                                        matrix[j][k]=matrix[j+1][k];
                                        matrix[j+1][k]=r;
                                }
                                r=matrix2[j];
                                matrix2[j]=matrix2[j+1];
                                matrix2[j+1]=r;
                        }
        for(int i=0;i<n;i++)
                for(int j=0;j<m;j++)
                        StringGrid1->Cells[j][i]=FloatToStr(matrix[i][j]);
}
//---------------------------------------------------------------------------


