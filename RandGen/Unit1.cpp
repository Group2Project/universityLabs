//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <ctime>
#include "Unit1.h"
#include <fstream.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma resource "*.dfm"
TForm1 *Form1;
int N;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        N = CSpinEdit1->Value;
        srand(time(NULL));
        int *a = new int[N];
        a[0]=rand()%10000;
        bool t(false);
        for(int i=1;i<N;i++)
        {
                a[i]=rand()%10000;
                t=false;
                for(int j=0;j<i;j++)
                {
                        if(a[i]==a[j])
                        {
                                a[i]=rand();
                                t=true;
                        }
                }
                if(t)
                        i--;
        }
        ofstream F;
        F.open("rand.txt");
        for(int i=0;i<N;i++)
                F << a[i] << '\n';
        F.close();
        
}
//---------------------------------------------------------------------------
 