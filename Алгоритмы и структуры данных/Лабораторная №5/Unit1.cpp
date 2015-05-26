//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
int step_mas0(0),step_mas1(0),step_mas2(0);
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma resource "*.dfm"
TForm1 *Form1;
#include <ctime>
#include <windows.h>
int sort(int *mas,int num);
#define N 85000
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
        srand(time(NULL));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{

        step_mas0=0;
        step_mas1=0;
        step_mas2=0;
        int mas0[N]; //Отсортированный массив
        int mas1[N]; //Остортированный в обратном порядке
        int mas2[N]; //Отсортированный рандомно
        for(int i=0;i<N;i++)
                mas0[i]=i;
        for(int i=N-1;i>=0;i--)
                mas1[i]=N-i;
        for(int i=0;i<N;i++)
                mas2[i]=rand()% 600;

        unsigned int time_mas0=sort(mas0,0);
        unsigned int time_mas1=sort(mas1,1);
        unsigned int time_mas2=sort(mas2,2);

        Series1->Clear();
        Series1->Add(step_mas0,"Перестановок 1",clRed);
        Series1->Add(step_mas1,"Перестановок 2",clBlue);
        Series1->Add(step_mas2,"Перестановок 3",clYellow);

        Series2->Clear();
        Series2->Add(time_mas0,"Время 1",clRed);
        Series2->Add(time_mas1,"Время 2",clBlue);
        Series2->Add(time_mas2,"Время 3",clYellow);

        

}
//---------------------------------------------------------------------------

int sort(int *mas,int num)
{
        unsigned int start_time = GetTickCount();
        int x,gap;
        int a[5];
        a[0]=9;
        a[1]=5;
        a[2]=3;
        a[3]=2;
        a[4]=1;
        int i,j,k;
        for(k=0;k<5;k++)
        {
                gap=a[k];
                for(i=gap;i<N;i++)
                {
                        x=mas[i];
                        for(j=i-gap;x<mas[j] && j>=0;j=j-gap)
                        {
                                mas[j+gap]=mas[j];
                                if(num==0)
                                        step_mas0++;
                                if(num==1)
                                        step_mas1++;
                                if(num==2)
                                        step_mas2++;
                        }
                        mas[j+gap]=x;
                }
        }
        unsigned int end_time = GetTickCount();
        unsigned int result = end_time - start_time;
        return (result);
}

//----------------------------------------------------------------------------