//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <stdio.h>
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormCreate(TObject *Sender)
{
        Memo1->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{

        if(Edit1->Text=="" || Edit2->Text=="" || Edit3->Text=="" || Edit4->Text=="" || Edit5->Text=="" || Edit6->Text==""){
                ShowMessage("Необходимо заполнить все поля");
                return;
        }
        FILE *myf = new FILE;
        myf=fopen("cinema.txt","a");
        char *temp = (Edit1->Text + " " + Edit2->Text + " " + Edit3->Text + " " + Edit4->Text + " " + Edit5->Text + " " + Edit6->Text).c_str();
        fprintf(myf,"%s\n",temp);
        fclose(myf);

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
        FILE *myf = new FILE;
        myf = fopen("cinema.txt","r");
        char ch;
        int i(0);
        bool test;
        while(ch!=EOF)
        {

                ch=fgetc(myf);
                if(ch=='\0'){
                        test = true;
                        continue;
                }
                else
                        test = false;
                if(!test)
                        Memo1->Lines->Strings[i] = Memo1->Lines->Strings[i] + (AnsiString)ch;
                else
                        Memo1->Lines->Add((AnsiString)ch);

        }
        fclose(myf);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
        Memo1->Clear();
}
//---------------------------------------------------------------------------

