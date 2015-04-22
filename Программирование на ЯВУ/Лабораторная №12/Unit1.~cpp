//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <stdio.h>
#include <string.h>
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
        if(Edit8->Text=="" && Edit1->Text=="" || Edit2->Text=="" || Edit3->Text=="" || Edit4->Text=="" || Edit5->Text=="" || Edit6->Text==""){
                ShowMessage("Необходимо заполнить все поля");
                return;
        }
        FILE *myf = new FILE;
        myf=fopen(Edit8->Text.c_str(),"a");
        char *temp1 = new char;
        temp1 = (Edit1->Text + " " + Edit2->Text + " " + Edit3->Text + " " + Edit4->Text + " " + Edit5->Text + " " + Edit6->Text).c_str();
        fprintf(myf,"%s\n",temp1);
        fclose(myf);

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
        Memo1->Clear();
        FILE *myf = new FILE;
        myf = fopen(Edit11->Text.c_str(),"r");
        if(!myf)
        {
                ShowMessage("Файл отсутствует");
                return;
        }
        char *out_string=new char[256];
        while(fgets(out_string,255,myf))
        {
                Memo1->Lines->Add((AnsiString)out_string);
        }
        delete out_string;
        fclose(myf);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
        Memo1->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
        Memo1->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
        FILE *add_file;
        add_file=fopen(Edit7->Text.c_str(),"w");
        fclose(add_file);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
        Memo1->Clear();
        FILE *search_file;
        bool search(false);
        search_file=fopen(Edit10->Text.c_str(),"r");
        if(!search_file)
        {
                ShowMessage("Файл не найден");
                return;
        }
        if(Edit9->Text=="")
        {
                ShowMessage("Отсутствует ключевое слово");
                return;
        }
        char *key_word=new char;
        strcpy(key_word,Edit9->Text.c_str());
        char *temp_string=new char[256];
        while(fgets(temp_string,255,search_file))
        {
                if(strstr(temp_string,key_word))
                {
                        Memo1->Lines->Add((AnsiString)temp_string);
                        search=true;
                }
        }
        if(!search)
                ShowMessage("Совпадений нет");
        delete temp_string;
        fclose(search_file);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
        Close();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button7Click(TObject *Sender)
{
        Memo1->Clear();
        FILE *delete_file;
        delete_file=fopen(Edit12->Text.c_str(),"r");
        if(!delete_file)
        {
                ShowMessage("Файл не найден");
                return;
        }
        if(CSpinEdit1->Value < 0)
        {
                ShowMessage("Введите номер удаляемой строки");
                return;
        }
        int n(0);
        while (fgetc(delete_file) != EOF)
                n++;
        rewind(delete_file);
        char *temp_buff = new char[n];
        AnsiString *buff = new AnsiString;
        AnsiString *temp_buff_2 = new AnsiString;
        int k(0);
        while(fgets(temp_buff,n,delete_file))
        {
                *buff += temp_buff;
                k++;
        }
        fclose(delete_file);
        delete temp_buff;
        *temp_buff_2 = *buff;
        AnsiString temp_str="";
        for(int i=0;i<k;i++)
        {
                if(i!=CSpinEdit1->Value)
                {
                        int m = temp_buff_2->Pos('\n');
                        temp_buff_2->Delete(1,m);
                }
                else
                {
                        int m = temp_buff_2->Pos('\n');
                        temp_str=temp_buff_2->SubString(1,m);
                        break;
                }
        }
        delete temp_buff_2;
        int m = temp_str.Length();
        k = buff->Pos(temp_str);
        buff->Delete(k,m);
        delete_file = fopen(Edit12->Text.c_str(),"w");
        fprintf(delete_file,"%s\n",buff->c_str());
        delete buff;
        fclose(delete_file);
}
//---------------------------------------------------------------------------


