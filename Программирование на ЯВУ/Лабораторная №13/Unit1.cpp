//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <fstream.h>
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        ifstream myf;
        myf.open("1234.txt");
        AnsiString buffer;
        char *buff=new char[255];
        int k(0);
        while(myf.getline(buff,256))
        {
                buffer +=(AnsiString)buff;
                buffer +='\n';
                k++;
        }
        delete buff;
        myf.close();
        if(CSpinEdit1->Value > k)
        {
                buffer += "00";
                for(int i=buffer.Length();i>2;i--)
                        buffer[i]=buffer[i-2];
                buffer[1]='\n';
                buffer[2]='\n';
        }
        else
        {
                AnsiString temp_buff=buffer;
                buffer ="";
                for(int i=0;i<k;i++)
                {
                        if(i!=CSpinEdit1->Value)
                        {
                                int m = temp_buff.Pos('\n');
                                buffer += temp_buff.SubString(1,m);
                                temp_buff.Delete(1,m);
                        }
                        else
                        {
                                int m = temp_buff.Pos('\n');
                                buffer += temp_buff.SubString(1,m);
                                buffer +='\n';
                                temp_buff.Delete(1,m);
                        }
                }
        }
        ofstream myf1;
        myf1.open("1234.txt");
        char *buff1 = new char[256];
        strcpy(buff1,buffer.c_str());
        myf1 << buff;
        myf1.close();
        delete buff1;
}
//---------------------------------------------------------------------------

