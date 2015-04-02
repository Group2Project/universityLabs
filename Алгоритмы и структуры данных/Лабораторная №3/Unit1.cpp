//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma resource "*.dfm"
TForm1 *Form1;
int n(0);
struct unit
{
        int amount,num,*mas;
        unit *next;
};
unit *head,*p;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{

        //----�������� ��������� ������----------------------------------//
        if(!CSpinEdit1->Value && Edit1->Text != "")                      //
        {                                                                //
                ShowMessage("������ ���� �� ����� ���� ����� ������.");  //
                return;                                                  //
        }                                                                //
        if(CSpinEdit1->Value && Edit1->Text == "")                       //
        {                                                                //
                ShowMessage("������� � ������ ������ ������.");          //
                return;                                                  //
        }                                                                //
        //---------------------------------------------------------------//

        //----���������� ����--------------------------------------------//
        unit *temp_unit = new unit;                                      //
        temp_unit->amount = CSpinEdit1->Value;                           //
        temp_unit->mas = new int[temp_unit->amount];                     //
        AnsiString unit_str = Edit1->Text;                               //
        if(!unit_str.Pos(";"))                                           //
        {                                                                //
                ShowMessage("���� ���������� ������� ����� ';'");        //
                return;                                                  //
        }                                                                //
        for(int i=0;i<temp_unit->amount;i++)                             //
        {                                                                //
                int t = unit_str.Pos(";");                               //
                if(!t)                                                   //
                {                                                        //
                        ShowMessage("�������� ����� �����");             //
                        return;                                          //
                }                                                        //
                temp_unit->mas[i]=StrToInt(unit_str.SubString(1,t-1));   //
                unit_str.Delete(1,t);                                    //
        }                                                                //
        temp_unit->num = n++;                                            //
        //---------------------------------------------------------------//

        //----���������� ���� � ����--//
        if(!head)                     //
                p=head=temp_unit;     //
        else                          //
        {                             //
                p->next=temp_unit;    //
                p=temp_unit;          //
        }                             //
        //----------------------------//

        //----���������� ���� � ������� ���������---
        StringGrid1->ColCount=n+1;
        StringGrid1->RowCount=n+1;
        StringGrid1->Cells[n][0]=IntToStr(temp_unit->num);
        StringGrid1->Cells[0][n]=IntToStr(temp_unit->num);
}
//---------------------------------------------------------------------------

