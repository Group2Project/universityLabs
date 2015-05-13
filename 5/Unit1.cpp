//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Fridge.h"
#include "Unit1.h"
#include <vector.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma resource "*.dfm"
TForm1 *Form1;
vector<Fridge> fridge;
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
                int height = StrToInt(Edit2->Text);
                float cost = StrToFloat(Edit3->Text);
                Fridge *new_fridge = new Fridge(name,height,cost);
                fridge.push_back(*new_fridge);
        }
        else
        {
                Fridge *new_fridge = new Fridge();
                fridge.push_back(*new_fridge);
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
        unsigned int n = CSpinEdit1->Value;
        if(n<fridge.size())
        {
                Memo1->Lines->Add(fridge[n].getName());
                Memo1->Lines->Add(IntToStr(fridge[n].getHeight()));
                Memo1->Lines->Add(FloatToStr(fridge[n].getCost()));
                Memo1->Lines->Add(' ');
        }
        else
                ShowMessage("������������ �����");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
        unsigned int n = CSpinEdit2->Value;
        if(n>=fridge.size())
        {
                ShowMessage("������������ �����");
                return;
        }
        if(Edit5->Text!="")
                fridge[n].setName(Edit5->Text);
        if(Edit6->Text!="")
                fridge[n].setHeight(StrToInt(Edit6->Text));
        if(Edit7->Text!="")
                fridge[n].setCost(StrToFloat(Edit7->Text));
}
//---------------------------------------------------------------------------
