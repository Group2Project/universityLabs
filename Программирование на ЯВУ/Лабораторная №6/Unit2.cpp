//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm2::ExitClick(TObject *Sender)
{
        Form1->Visible=true;
        Close();        
}
//---------------------------------------------------------------------------

void __fastcall TForm2::EnterClick(TObject *Sender)
{
         int matrix[5][5];
         int up,down, i_up(0),j_up(1),i_down(1),j_down(0);
         for(int i=0;i<5;i++)
                for(int j=0;j<5;j++)
                        matrix[i][j]=StrToInt(StringGrid1->Cells[j][i]);
         down=matrix[1][0];
         up=matrix[0][1];
         for(int i=1;i<5;i++)
                for(int j=0;j<i;j++)
                        if(down<matrix[i][j]){
                                down=matrix[i][j];
                                j_down=j;
                                i_down=i;
                        }
         for(int i=0;i<4;i++)
                for(int j=4;j>i;j--)
                        if(up<matrix[i][j]){
                                up=matrix[i][j];
                                i_up=i;
                                j_up=j;
                        }
         StringGrid1->Cells[j_down][i_down]=IntToStr(up);
         StringGrid1->Cells[j_up][i_up]=IntToStr(down);

}
//---------------------------------------------------------------------------
void __fastcall TForm2::ClearClick(TObject *Sender)
{
        for(int i=0;i<5;i++)
                for(int j=0;j<5;j++)
                        StringGrid1->Cells[j][i]="";
}
//---------------------------------------------------------------------------

