//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
struct grf
{
        int num;
        grf *next,*mas;
};
grf *p,*head;
int n(0);
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
























        //n++;
        //grf *unit = new grf;
        //unit->num=n;
        //if(head)
        //{
        //        int *mas_p = new int[StrToInt(Edit1->Text)];
        //        AnsiString units = Edit2->Text;
        //        units.Delete(units.Length(),1);
        //        units.Insert(",",units.Length()+1);
        //        while(units.Pos(","))
        //        {
        //                mas_pStrToInt(units.SubString(1,units.Pos(",")-1));
        //                units.Delete(1,units.Pos(","));
        //
        //
        //        }
        //}
        //else


}
//---------------------------------------------------------------------------
