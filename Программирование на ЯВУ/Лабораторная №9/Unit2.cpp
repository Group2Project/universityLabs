//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <String.h>
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
char LowCaseRus(char *str);
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
        char *s = Edit1->Text.c_str();
        *s = LowCaseRus(s);
        Edit1->Text=(AnsiString)s;
}
//---------------------------------------------------------------------------

char LowCaseRus(char *str)
{
        for(int i=0;i<strlen(str);i++)
                if((signed int)str[i] >= -64 && (signed int)str[i] <=-33)
                        str[i] = str[i] + ' ';
        return *str;
}



