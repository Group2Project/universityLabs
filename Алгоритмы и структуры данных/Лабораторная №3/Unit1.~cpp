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

        //----Проверка введенных данных----------------------------------//
        if(!CSpinEdit1->Value && Edit1->Text != "")                      //
        {                                                                //
                ShowMessage("Пустой узел не может иметь связей.");       //
                return;                                                  //
        }                                                                //
        if(CSpinEdit1->Value && Edit1->Text == "")                       //
        {                                                                //
                ShowMessage("Введите с какими узлами связан.");          //
                return;                                                  //
        }                                                                //
        //---------------------------------------------------------------//

        //----Заполнение узла----------------------------------------------------------//
        unit *temp_unit = new unit;                                                    //
        temp_unit->amount = CSpinEdit1->Value;                                         //
        temp_unit->mas = new int[temp_unit->amount];                                   //
        AnsiString unit_str = Edit1->Text;                                             //
        if(!unit_str.Pos(";") && CSpinEdit1->Value)                                    //
        {                                                                              //
                ShowMessage("Узлы необходимо вводить через ';'");                      //
                return;                                                                //
        }                                                                              //
        for(int i=0;i<temp_unit->amount;i++)                                           //
        {                                                                              //
                if(!unit_str.Pos(";"))                                                 //
                        return;                                                        //
                temp_unit->mas[i]=StrToInt(unit_str.SubString(1,unit_str.Pos(";")-1)); //
                unit_str.Delete(1,unit_str.Pos(";"));                                  //
        }                                                                              //
        temp_unit->num = n++;                                                          //
        //-----------------------------------------------------------------------------//

        //----Добавление узла в граф--//
        if(!head)                     //
                p=head=temp_unit;     //
        else                          //
        {                             //
                p->next=temp_unit;    //
                p=temp_unit;          //
        }                             //
        //----------------------------//


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
        Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
        for(int i=0;i<n+1;i++)
                for(int j=0;j<n+1;j++)
                        StringGrid1->Cells[j][i]="";
        StringGrid1->ColCount=0;
        StringGrid1->RowCount=0;
        CSpinEdit1->Value=0;
        Edit1->Text="";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
        StringGrid1->ColCount=n+1;
        StringGrid1->RowCount=n+1;
        for(int i=0;i<n;i++)
        {
                        StringGrid1->Cells[0][i+1]=i;
                        StringGrid1->Cells[i+1][0]=i;
        }
        unit *out_unit = head;
        for(;out_unit!=p->next;out_unit=out_unit->next)
                for(int i=0;i<out_unit->amount;i++)
                {
                        StringGrid1->Cells[out_unit->num+1][out_unit->mas[i]+1]="+";
                        StringGrid1->Cells[out_unit->mas[i]+1][out_unit->num+1]="+";
                }
        for(int i=0;i<n+1;i++)
                for(int j=0;j<n+1;j++)
                        if(StringGrid1->Cells[j][i]=="")
                                StringGrid1->Cells[j][i]="-";
        for(int i=0;i<n+1;i++)
                         StringGrid1->Cells[i][i]="";
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button5Click(TObject *Sender)
{
        unit *del_unit;
        //----Удаление узла из списка-------------------//
        if(CSpinEdit2->Value)                           //
        {                                               //
                unit *del_unit2=head;                   //
                for(int i=0;i<CSpinEdit2->Value-1;i++)  //
                        del_unit2=del_unit2->next;      //
                del_unit=del_unit2->next;               //
                del_unit2->next=del_unit->next;         //
                delete del_unit->mas;                   //
                delete del_unit;                        //
        }                                               //
        else                                            //
        {                                               //
                del_unit=head;                          //
                head->next=del_unit->next;              //
                delete del_unit;                        //
        }                                               //
        //----------------------------------------------//
        n--;

        del_unit = head;
        while(del_unit!=p->next)
        {
                bool check(false);
                for(int i=0;i<del_unit->amount;i++)
                        if(del_unit->mas[i] == CSpinEdit2->Value)
                        {
                                check = true;
                                break;
                        }
                if(check)
                {

                        if(del_unit->amount)
                        {
                                int *mas_new = new int[del_unit->amount-1];
                                for(int i=0;i<del_unit->amount-1;i++)
                                        if(del_unit->mas[i] != CSpinEdit2->Value)
                                                mas_new[i] = del_unit->mas[i];
                                        else
                                        {
                                                for(int j=i;j<del_unit->amount-1;j++)
                                                        del_unit->mas[j]=del_unit->mas[j+1];
                                                i--;
                                        }
                                delete del_unit->mas;
                                del_unit->mas = mas_new;
                        }
                        else
                                delete del_unit->mas;
                        del_unit->amount--;
                }
                for(int i=0;i<del_unit->amount;i++)
                        if(del_unit->mas[i] > CSpinEdit2->Value)
                                del_unit->mas[i]--;
                if(del_unit->num > CSpinEdit2->Value)
                        del_unit->num--;

                del_unit=del_unit->next;


        }
}
//---------------------------------------------------------------------------




