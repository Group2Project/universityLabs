//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "Unit2.h"
extern int n1,n2;
struct FIFO
{
        AnsiString family;
        AnsiString code;
        FIFO *next;
};

extern FIFO *head1,*head2,*head3,*p1,*p2,*p3,*p1_d,*p2_d,*p3_d;
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TButton *Button2;
        TButton *Button3;
        TButton *Button4;
        TMemo *Memo1;
        TButton *Button5;
        TButton *Button1;
        TMemo *Memo2;
        TMemo *Memo3;
        TButton *Button6;
        TButton *Button7;
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
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
