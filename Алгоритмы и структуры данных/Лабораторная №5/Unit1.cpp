//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
int time_mas0(0),time_mas1(0),time_mas2(0);
int step_mas0(0),step_mas1(0),step_mas2(0);
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
#define N 100
#include <ctime>
void sort(int *mas,int num);
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
        srand(time(NULL));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        time_mas0=0;
        time_mas1=0;
        time_mas2=0;
        step_mas0=0;
        step_mas1=0;
        step_mas2=0;
        int mas0[N]; //��������������� ������
        int mas1[N]; //��������������� � �������� �������
        int mas2[N]; //��������������� ��������
        for(int i=0;i<N;i++)
                mas0[i]=i;
        for(int i=N-1;i>=0;i--)
                mas1[i]=N-i;
        for(int i=0;i<N;i++)
                mas2[i]=rand()% 600;

        sort(mas0,0);
        sort(mas1,1);
        sort(mas2,2);

        Series1->Clear();
        Series1->Add(step_mas0,"������������ 1",clRed);
        Series1->Add(step_mas1,"������������ 2",clBlue);
        Series1->Add(step_mas2,"������������ 3",clYellow);

        Series2->Clear();
        Series2->Add(time_mas0,"����� 1",clRed);
        Series2->Add(time_mas1,"����� 2",clBlue);
        Series2->Add(time_mas2,"����� 3",clYellow);

        

}
//---------------------------------------------------------------------------

void sort(int *mas,int num)
{
        for(int step = N/2;step>0;step/=2)
                for(int i=0;i<N-step;i++)
                {
                        for(int j=i;j>=0 && mas[j] > mas[j+step];j--)
                        {
                                int temp = mas[j];
                                mas[j]=mas[j+step];
                                mas[j+step]=temp;
                                if(num==0)
                                        step_mas0++;
                                if(num==1)
                                        step_mas1++;
                                if(num==2)
                                        step_mas2++;
                        }
                }
}

//----------------------------------------------------------------------------