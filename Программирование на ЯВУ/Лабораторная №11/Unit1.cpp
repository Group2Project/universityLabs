//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma resource "*.dfm"
TForm1 *Form1;

struct data
{
        AnsiString family;
        int age;
        bool army;

        data *next;
};
int n(0);
data *head,*p;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
        data *add_collab = new data;
        if(Edit1->Text!="")
                add_collab->family=Edit1->Text;
        else
        {
                ShowMessage("������� �������.");
                return;
        }

        if(CSpinEdit1->Value)
                add_collab->age=CSpinEdit1->Value;
        else
        {
                ShowMessage("������� �������");
                return;
        }

        if(RadioGroup1->ItemIndex)
                add_collab->army=false;
        else
                add_collab->army=true;

        if(!head)
                p=head=add_collab;
        else
        {
                p->next=add_collab;
                p=add_collab;
        }
        n++;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
        Memo1->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
        Close();        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
        Memo1->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
        data *temp=head;
        int min_age;
        bool test_army(false);
        if(n)
        {
                while(temp!=p->next)
                {
                        if(!temp->army)
                        {
                                test_army=true;
                                min_age=temp->age;
                                break;
                        }
                        temp=temp->next;
                }
                if(!test_army)
                {
                        ShowMessage("��� ���������� ���������������");
                        return;
                }
                temp=head;
                while(temp!=p->next)
                {
                        if(!temp->army && temp->age < min_age)
                                min_age = temp->age;
                        temp=temp->next;
                }
                temp=head;
                while(temp!=p->next)
                {
                        if(!temp->army && temp->age == min_age)
                                Memo1->Lines->Add(temp->family);
                        temp=temp->next;
                }
                for(int i=0;i<Memo1->Lines->Count-1;i++)
                        for(int j=0;j<Memo1->Lines->Count-1-i;j++)
                                if(Memo1->Lines->Strings[j] > Memo1->Lines->Strings[j+1])
                                {
                                        AnsiString temp_str = Memo1->Lines->Strings[j];
                                        Memo1->Lines->Strings[j] = Memo1->Lines->Strings[j+1];
                                        Memo1->Lines->Strings[j+1] = temp_str;
                                }
                for(int i=0;i<Memo1->Lines->Count;i++)
                        if(Memo1->Lines->Strings[i] == Memo1->Lines->Strings[i+1])
                        {
                                Memo1->Lines->Delete(i);
                                i-=2;
                        }
        }
        else
                ShowMessage("������ ����");        
}
//---------------------------------------------------------------------------
