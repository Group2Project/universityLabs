//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Book.h"
#include "Unit1.h"
#include <vector.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma resource "*.dfm"
TForm1 *Form1;
vector<Book> book;
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

        if(Edit1->Text!="" && Edit2->Text!="" && Edit3->Text!="")
        {
                AnsiString name = Edit1->Text;
                AnsiString author = Edit2->Text;
                float cost = StrToFloat(Edit3->Text);
                Book *new_book = new Book(name,author,cost);
                book.push_back(*new_book);
        }
        else
        {
                Book *new_book = new Book();
                book.push_back(*new_book);
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
        unsigned int n = CSpinEdit1->Value;
        if(n<book.size())
        {
                Memo1->Lines->Add(book[n].getAuthor());
                Memo1->Lines->Add(book[n].getName());
                Memo1->Lines->Add(FloatToStr(book[n].getCost()));
                Memo1->Lines->Add(' ');
        }
        else
                ShowMessage("Некорректный номер");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
        unsigned int n = CSpinEdit2->Value;
        if(n>=book.size())
        {
                ShowMessage("Некорректный номер");
                return;
        }
        if(Edit5->Text!="")
                book[n].setAuthor(Edit5->Text);
        if(Edit6->Text!="")
                book[n].setName(Edit6->Text);
        if(Edit7->Text!="")
                book[n].setCost(StrToFloat(Edit7->Text));
}
//---------------------------------------------------------------------------
