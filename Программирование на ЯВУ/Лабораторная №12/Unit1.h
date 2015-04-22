//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "CSPIN.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox1;
        TEdit *Edit1;
        TEdit *Edit2;
        TEdit *Edit3;
        TEdit *Edit4;
        TEdit *Edit5;
        TEdit *Edit6;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TButton *Button1;
        TGroupBox *GroupBox2;
        TButton *Button2;
        TMemo *Memo1;
        TButton *Button3;
        TEdit *Edit8;
        TLabel *Label6;
        TLabel *Label8;
        TGroupBox *GroupBox3;
        TLabel *Label7;
        TEdit *Edit7;
        TButton *Button4;
        TGroupBox *GroupBox4;
        TLabel *Label9;
        TEdit *Edit9;
        TButton *Button5;
        TEdit *Edit10;
        TLabel *Label10;
        TButton *Button6;
        TLabel *Label11;
        TEdit *Edit11;
        TGroupBox *GroupBox5;
        TLabel *Label12;
        TLabel *Label13;
        TButton *Button7;
        TEdit *Edit12;
        TCSpinEdit *CSpinEdit1;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall Button7Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
