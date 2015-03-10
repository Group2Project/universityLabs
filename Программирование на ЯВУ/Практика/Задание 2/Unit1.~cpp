//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma resource "*.dfm"
TForm1 *Form1;
int n,m;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
        Close();        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
        for(int i=0;i<n;i++)
                for(int j=0;j<m;j++)
                        StringGrid1->Cells[j][i]="";
        StringGrid1->Hide();
        CSpinEdit1->Value = 0;
        CSpinEdit2->Value = 0;
        Panel2->Hide();
        Panel1->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
        n = CSpinEdit1->Value;
        m = CSpinEdit2->Value;
        StringGrid1->ColCount=m;
        StringGrid1->RowCount=n;
        Panel1->Hide();
        Panel2->Show();
        StringGrid1->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
        Panel2->Hide();
        StringGrid1->Hide();        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
        float **matrix = new float *[n];
        for(int i = 0;i<n;i++)
                matrix[i] = new float[m];
        for(int i = 0;i<n;i++)
                for(int j = 0;j<m;j++)
                        matrix[i][j] = StrToInt(StringGrid1->Cells[j][i]);
}
//---------------------------------------------------------------------------
