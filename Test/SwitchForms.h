#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"

/*
        SwitchForms *test = new SwitchForms();
        int n;;
        test->showForm(this,n);
*/

//------------------------------------------------------------------------------

class SwitchForms
{
        private:
               TForm *arrayForms[];
        public:
                SwitchForms();
                void showForm(TForm*,int);
};

//------------------------------------------------------------------------------

SwitchForms::SwitchForms()
{
        arrayForms[0] = Form1;
        arrayForms[1] = Form2;
        arrayForms[2] = Form3;
        arrayForms[3] = Form4;

}

//------------------------------------------------------------------------------

void SwitchForms::showForm(TForm *temp_form,int n)
{
       temp_form->Hide();
       arrayForms[n]->Show();
}

