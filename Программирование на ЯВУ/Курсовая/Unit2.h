//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <ExtCtrls.hpp>
#include "CSPIN.h"
#include "class_city.h"
#include <Grids.hpp>

//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TMenuItem *N1;
        TMenuItem *N2;
        TMenuItem *N3;
        TMenuItem *N4;
        TMenuItem *N5;
        TGroupBox *GroupBox1;
        TImage *Image1;
        TMenuItem *N6;
        TRadioGroup *select_in_mode;
        TGroupBox *gb_am_city_connect;
        TCSpinEdit *CSpinEdit1;
        TRadioGroup *editing_mode;
        TMenuItem *N7;
        TCSpinEdit *CSpinEdit2;
        TButton *Button1;
        TButton *Button2;
        TCSpinEdit *CSpinEdit3;
        TCSpinEdit *CSpinEdit4;
        TGroupBox *gb_del_road;
        TLabel *Label2;
        TLabel *Label3;
        TGroupBox *GroupBox2;
        TLabel *Label1;
        TButton *Button3;
        TButton *Button4;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall N5Click(TObject *Sender);
        void __fastcall N4Click(TObject *Sender);
        void __fastcall N6Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall select_in_modeClick(TObject *Sender);
        void __fastcall editing_modeClick(TObject *Sender);
        void __fastcall N7Click(TObject *Sender);
        void __fastcall Image1MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Image1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
