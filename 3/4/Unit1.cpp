//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#define N 85000
#include <ctime>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int NaturalSort(int*,int);
int k1,k2,k3;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{
        k1 = 0;
        k2 = 0;
        k3 = 0;
        srand(time(NULL));
        int *mas1 = new int[N];
        int *mas2 = new int[N];
        int *mas3 = new int[N];
        for(int i=0;i<N;i++)
        {
                mas1[i]=i;
                mas2[N-i-1] = i;
                mas3[i]=rand();
        }
        int time1 = NaturalSort(mas1,1);
        int time2 = NaturalSort(mas2,2);
        int time3 = NaturalSort(mas3,3);

        Series1->Clear();
        Series1->Add(k1,"Перестановок 1",clRed);
        Series1->Add(k2,"Перестановок 2",clBlue);
        Series1->Add(k3,"Перестановок 3",clYellow);

        Series2->Clear();
        Series2->Add(time1,"Время 1",clRed);
        Series2->Add(time2,"Время 2",clBlue);
        Series2->Add(time3,"Время 3",clYellow);
}
//----------------------------------------------------------------------------

void increment_k(int r)
{
        switch (r)
        {
                case 1:
                        k1++;
                        break;
                case 2:
                        k2++;
                        break;
                case 3:
                        k3++;
                        break;
        }
}
//----------------------------------------------------------------------------
void Merge(int *A, int nA,int *B, int nB,int *C,int r)
{
    int ia(0), ib(0); //Номера текущих элементов в массивах A и B
    while( ia+ib < nA+nB ) //Пока остались элементы в массивах
    {
        if( (ib>=nB) || ( (ia<nA) && (A[ia]<=B[ib]) ) )
        { //Копирую элемент из массива A
            C[ia+ib] = A[ia];
            ia++;
            increment_k(r);
        }
        else
        { //Копирую элемент из массива B
            C[ia+ib] = B[ib];
            ib++;
            increment_k(r);
        }
    }
}
//---------------------------------------------------------------------------
int NaturalSort(int *A,int r)
{
        unsigned int start_time = GetTickCount();
        int *B=new int[N];
        while(true)
        {
                int start1,end1;
                int start2(-1),end2(-1);
                while(true)
                {
                        start1 = end2+1;
                        end1 = start1;
                         while( (end1<N-1) && (A[end1]<=A[end1+1]))
                                end1++;
                        if( end1 == N-1 )
                                break;
                        start2 = end1+1;
                        end2 = start2;
                        while( (end2<N-1) && (A[end2]<=A[end2+1]))
                                end2++;
                        Merge(A+start1, end1-start1+1,A+start2,end2-start2+1,B+start1,r);
                        if( end2 == N-1 )
                                break;
                }
                if( (start1==0) && (end1==N-1))
                        break;
                if( end1 == N-1 )
                {
                        for(;start1<N;start1++)
                                B[start1]=A[start1];
                }
                memcpy(A,B,sizeof(int)*N);
        }
        delete[] B;
        unsigned int end_time = GetTickCount();
        unsigned int result = end_time - start_time;
        return (result);
}

//--------------------------------------------------------------------------
