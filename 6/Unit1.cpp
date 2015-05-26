//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <iostream>
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma resource "*.dfm"
int N;
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void find(int **A,int st)
{
        int *distance=new int[N];
        int index,i,j;
        bool *visited=new bool[N];
        for(i=0;i<N;i++)
        {
                distance[i]=INT_MAX;
                visited[i]=false;
        }
        distance[st]=0;
        for(i=0;i<N-1;i++)
        {
                int min = INT_MAX;
                for(j=0;j<N;j++)
                       if(!visited[j] && distance[j]<=min)
                        {
                                min=distance[j];
                                index=j;
                        }
                visited[index]=true;
                for(j=0;j<N;j++)
                        if(!visited[j] && A[index][j] && distance[index]!=INT_MAX && distance[index]+A[index][j]<distance[j])
                                distance[j]=distance[index]+A[index][j];
        }
        ShowMessage("Кратчайший путь: " +IntToStr(distance[Form1->CSpinEdit3->Value]));
}

//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
        GroupBox2->Show();
        StringGrid1->ColCount=CSpinEdit1->Value;
        StringGrid1->RowCount=CSpinEdit1->Value;
        GroupBox1->Hide();
        StringGrid1->Show();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button2Click(TObject *Sender)
{
        N=CSpinEdit1->Value;
        int **A = new int*[N];
        for(int i=0;i<N;i++)
                A[i]=new int[N];
        for(int i=0;i<N;i++)
                for(int j=0;j<N;j++)
                        A[i][j]=StrToInt(StringGrid1->Cells[j][i]);
        int start = CSpinEdit2->Value;
        find(A,start);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
        GroupBox1->Show();
        GroupBox2->Hide();
        StringGrid1->Hide();        
}
//---------------------------------------------------------------------------

