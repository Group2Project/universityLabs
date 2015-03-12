//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
int n1(0),n2(0);
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button2Click(TObject *Sender)
{
        Form2->Hide();        
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button1Click(TObject *Sender)
{
        n1++;
        FIFO *spisok = new FIFO;
        spisok->family=Edit1->Text;
        spisok->code=Edit2->Text;
        if(head1){
                p1->next=spisok;
                p1=spisok;
        }
        else
               p1=head1=spisok;

}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button3Click(TObject *Sender)
{
        n2++;
        FIFO *spisok = new FIFO;
        spisok->family=Edit3->Text;
        spisok->code=Edit4->Text;
        if(head2){
                p2->next=spisok;
                p2=spisok;
        }
        else
               p2=head2=spisok;
}
//---------------------------------------------------------------------------

