//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "CSPIN.h"
#include <Grids.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TExercise2 : public TForm
{
__published:	// IDE-managed Components
        TButton *Exit;
        TLabel *Label1;
        TCSpinEdit *CSpinEdit1;
        TButton *Clear;
        TButton *Calculate;
        TButton *Enter;
        TPanel *Panel1;
        TStringGrid *Array1;
        TStringGrid *Array2;
        void __fastcall ExitClick(TObject *Sender);
        void __fastcall ClearClick(TObject *Sender);
        void __fastcall EnterClick(TObject *Sender);
        void __fastcall CalculateClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TExercise2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TExercise2 *Exercise2;
//---------------------------------------------------------------------------
#endif
