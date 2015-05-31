//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <ctime>
#include <vector.h>
#include <fstream.h>
#include <math.h>
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma resource "*.dfm"
TForm1 *Form1;
struct st
{
        int a;
        st *next,*prev;
};
st *p;
int _hash(int k);
void incr_vec(vector<st> *,int);
vector<st> source_mas;
vector<st> hash_tab;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        ifstream F;
        F.open("rand.txt");
        while(!F.eof())
        {
                int a;
                F >> (int)a;
                st *temp = new st;
                temp->a = a;
                source_mas.push_back(*temp);
        }
        F.close();
        for(unsigned int i=0;i<source_mas.size();i++)
        {
                unsigned int hash_sum = _hash(source_mas[i].a);
                if(hash_sum >= hash_tab.size())
                {
                        incr_vec(&hash_tab,hash_sum);
                        hash_tab[hash_sum]=source_mas.at(i);
                        continue;
                }
                if(hash_tab[hash_sum].a!=0)
                {
                        hash_tab[hash_sum].next=&source_mas[i];
                        continue;
                }
                else
                {
                        hash_tab[hash_sum]=source_mas[i];
                        continue;
                }
        }
        ofstream f1;
        f1.open("rand1.txt");
        for(unsigned int i=0;i<hash_tab.size();i++)
        {
                int r;
                r = hash_tab.at(i).a;
                f1 << r << '\n';
        }
        f1.close();
}
//---------------------------------------------------------------------------

int _hash(int k)
{
        double gold_sec = (1+sqrt(5))/2.0;
        double h = k*gold_sec;
        int m(0);
        while(k>0)
        {
                m++;
                k/=10;
        }
        int h1 =(int)h;
        h -=h1;
        for(int j=0;j<m;j++)
                h*=10;
        return (int)h;
}

//----------------------------------------------------------------------------

void incr_vec(vector<st> *a,int k)
{
        int r = k - a->size();
        if(!r)
        {
                st *t = new st;
                t->a = 0;
                a->push_back(*t);
                return;
        }
        for(int i=0;i<=r;i++)
        {
                st *t = new st;
                t->a=0;
                a->push_back(*t);
        }
}

//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
        if(hash_tab.size())
        {
                int n = CSpinEdit1->Value;
                int r = _hash(n);
                st out = hash_tab[r];
                for(;;)
                {
                        if(out.a == n)
                        {
                                ShowMessage("Число найдено");
                                break;
                        }
                        if(!out.a)
                        {
                                ShowMessage("Число не найдено");
                                break;
                        }
                        if(out.a!=n && out.a)
                        {
                                out=*out.next;
                        }
                }

        }
}
//---------------------------------------------------------------------------

