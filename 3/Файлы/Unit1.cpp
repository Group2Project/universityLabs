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
        AnsiString buffer;  //Основное буффер
        AnsiString demo_buffer;
        char *buff=new char[255];   //Временный буфер для заполнения основного
        int k(0);  //Количество строк
        while(myf.getline(buff,256))
        {
                if(k < 3)
                {
                        demo_buffer +=(AnsiString)buff;
                        demo_buffer +='\n';
                }
                buffer +=(AnsiString)buff;
                buffer +='\n';
                k++;
        }
        if(CSpinEdit1->Value < k)
        {
                ShowMessage("Ошибка");
                return;
        }
        delete buff;
        myf.close();
        int r = demo_buffer.Length();
        buffer.Delete(1,r);
        for(int i=0;i<CSpinEdit1->Value;i++)
        {
                int t = buffer.Pos('\n');
                buffer.Delete(1,t);
        }
        demo_buffer +=buffer;
        ofstream myf1;
        myf1.open("1234.txt");
        char *buff1 = new char[256];
        strcpy(buff1,demo_buffer.c_str());
        myf1 << buff;
        myf1.close();
        delete buff1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
        Memo1->Clear();        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
        Memo1->Clear();
        ifstream myf;
        myf.open("1234.txt");
        char *buff=new char[255];   //Временный буфер для заполнения основного
        while(myf.getline(buff,256))
        {
                Memo1->Lines->Add((AnsiString)buff);
        }
        delete buff;
        myf.close();
}
//---------------------------------------------------------------------------
