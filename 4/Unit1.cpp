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

bool test(int ia,int na,int ib,int nb,int ic,int nc,int id,int nd)
{
        bool x1,x2,x3,x4;
        if(ia < na)
                x1=true;
        else
                x1=false;
        if(ib < nb)
                x2=true;
        else
                x2=false;
        if(ic < nc)
                x3=true;
        else
                x3=false;
        if(id < nd)
                x4=true;
        else
                x4=false;
        if((x1||x2||x3)&&(x2||x3||x4)&&(x3||x4||x1)&&(x1||x2||x3||x4))
                return true;
        else
                return false;
}
//----------------------------------------------------------------------------
void Merge(int *A, int nA,int *B, int nB,int *C,int nC,int *D,int nD,int *F,int r)
{
    int min_i;
    int min;
    int temp[4];
    int ia(0),ib(0),ic(0),id(0); //Номера текущих элементов в массивах A и B
    while(ia+ib+ic+id<nA+nB+nC+nD) //Пока остались элементы в массивах
    {
        while(test(ia,nA,ib,nB,ic,nC,id,nD))
        {

                if(ia!=nA)
                        temp[0]=A[ia];
                else
                        temp[0]=100000000;
                if(ib!=nB)
                        temp[1]=B[ib];
                else
                        temp[1]=100000000;
                if(ic!=nC)
                        temp[2]=C[ic];
                else
                        temp[2]=100000000;
                if(id!=nD)
                        temp[3]=D[id];
                else
                        temp[3]=100000000;
                min_i = 0;
                min = temp[0];
                for(int i=0;i<4;i++)
                        if(temp[i]<min)
                        {
                                min=temp[i];
                                min_i=i;
                        }
                switch (min_i)
                {
                        case 0:
                                F[ia+ib+ic+id]=A[ia];
                                if(ia<nA)
                                {
                                        increment_k(r);
                                        ia++;
                                }
                                break;
                        case 1:
                                F[ia+ib+ic+id]=B[ib];
                                if(ib<nB)
                                {
                                        increment_k(r);
                                        ib++;
                                }
                                break;
                        case 2:
                                F[ia+ib+ic+id]=C[ic];
                                if(ic<nC)
                                {
                                        increment_k(r);
                                        ic++;
                                }
                                break;
                        case 3:
                                F[ia+ib+ic+id]=D[id];
                                if(id<nD)
                                {
                                        increment_k(r);
                                        id++;
                                }
                                break;
                }
           }
        while(ia<nA)
        {
                F[ia+ib+ic+id]=A[ia];
                increment_k(r);
                ia++;
        }
        while(ib<nB)
        {
                F[ia+ib+ic+id]=B[ib];
                increment_k(r);
                ib++;
        }
        while(ic<nC)
        {
                F[ia+ib+ic+id]=C[ic];
                increment_k(r);
                ic++;
        }
        while(id<nD)
        {
                F[ia+ib+ic+id]=D[id];
                increment_k(r);
                id++;
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
                int start2,end2;
                int start3,end3;
                int start4(-1),end4(-1);
                while(true)
                {
                        start1 = end4+1;
                        end1 = start1;
                        while( (end1<N-1) && (A[end1]<=A[end1+1]))
                                end1++;
                        if( end1 == N-1 )
                                break;
                        start2 = end1+1;
                        end2 = start2;
                        while((end2<N-1) && (A[end2]<=A[end2+1]))
                                end2++;
                        start3 = end2 + 1;
                        end3 = start3;
                        while((end3<N-1) && (A[end3]<=A[end3+1]))
                                end3++;
                        start4 = end3 + 1;
                        end4 = start4;
                        while((end4<N-1) && (A[end4]<=A[end4+1]))
                                end4++;
                        int na = end1-start1+1;
                        int nb = end2-start2+1;
                        int nc;
                        int nd;
                        if(start3>=N)
                                nc=0;
                        else
                                nc=end3-start3+1;
                        if(start4>=N)
                                nd=0;
                        else
                                nd=end4-start4+1;
                        Merge(A+start1,na,A+start2,nb,A+start3,nc,A+start4,nd,B+start1,r);
                        if( end2 == N-1 )
                                break;
                        if( end3 == N-1)
                                break;
                        if( end4 == N-1)
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

