//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TEdit *Side1;
        TEdit *Side2;
        TEdit *Angle;
        TEdit *Side3;
        TButton *Calculate;
        TButton *Reset;
        TButton *Exit;
        TEdit *Area;
        TLabel *Label1;
        TLabel *Label3;
        TLabel *Label5;
        TLabel *Label4;
        TLabel *Label2;
        void __fastcall CalculateClick(TObject *Sender);
        void __fastcall ResetClick(TObject *Sender);
        void __fastcall ExitClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
