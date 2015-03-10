//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
int n=0;
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
        n++;
        FIFO *spisok = new FIFO;
        spisok->family=Edit1->Text;
        spisok->code=Edit2->Text;
        if(head){
                p->next=spisok;
                p=spisok;
        }
        else {
                p=head=spisok;
                //p->next=NULL;
        }
}
//---------------------------------------------------------------------------
