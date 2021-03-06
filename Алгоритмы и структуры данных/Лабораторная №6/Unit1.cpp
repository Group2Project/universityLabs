//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <ctime>
#include <vector.h>
#include <fstream.h>
#include <math.h>
#include "Unit1.h"
vector<int> hash_tab;
vector<int> source_mas;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma resource "*.dfm"
TForm1 *Form1;
int _hash(int,int);
void incr_vec(vector<int> *,int);
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
                source_mas.push_back(a);
        }
        F.close();
        int l = 0;
        for(unsigned int i=0;i<source_mas.size();i++)
        {
                unsigned int hash_sum = _hash(source_mas[i],l);
                if(hash_sum >= hash_tab.size())
                {
                        incr_vec(&hash_tab,hash_sum);
                        hash_tab.at(hash_sum)=source_mas.at(i);
                        continue;
                }
                if(hash_tab[hash_sum]!=NULL)
                {
                        l++;
                        i--;
                        continue;
                }
                else
                {
                        hash_tab.at(hash_sum)=source_mas.at(i);
                        l=0;
                        continue;
                }
        }
        ofstream f1;
        f1.open("rand1.txt");
        for(unsigned int i=0;i<hash_tab.size();i++)
        {
                int r;
                r = hash_tab[i];
                f1 << r << '\n';
        }
        f1.close();
}
//---------------------------------------------------------------------------

int _hash(int k,int i)
{
        double gold_sec = (1+sqrt(5))/2.0;
        double h = k*gold_sec + 3*i + 5*i*i;
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

void incr_vec(vector<int> *a,int k)
{
        int r = k - a->size();
        if(!r)
        {
                a->push_back(NULL);
                return;
        }
        for(int i=0;i<=r;i++)
                a->push_back(NULL);
}

//---------------------------------------------------------------------------


void __fastcall TForm1::Button2Click(TObject *Sender)
{
        if(hash_tab.size())
        {
                int n = CSpinEdit1->Value;
                int l=0;
                int r = _hash(n,l);
                int m = hash_tab[r];
                for(;;)
                {
                        if(hash_tab[r] && hash_tab[r]==n)
                        {
                                ShowMessage("����� �������");
                                return;
                        }
                        if(hash_tab[r] && hash_tab[r]!=n)
                        {
                                l++;
                                r = _hash(n,l);
                        }
                        if(!hash_tab[r])
                        {
                                ShowMessage("���������� �� �������");
                                return;
                        }
                }
        }
}
//---------------------------------------------------------------------------

