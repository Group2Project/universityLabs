//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------

class ArrayOb
{
        public:
                long index;
                int info;
};

class SparseOb : public ArrayOb
{
        public:
                SparseOb *next;
                SparseOb *prior;

                SparseOb()
                {
                        info = 0;
                        index = -1;
                        next = NULL;
                        prior = NULL;
                };
};

class SparseList : public SparseOb
{
        SparseOb *start, *end;
        public:
                SparseList()
                {
                        start = end = NULL;
                }
                ~SparseList();
                void store(long ix, int c);
                void remove(long ix);
                SparseOb *find(long ix);
};

SparseList :: ~SparseList()
{
        SparseOb *p,*p1;
        p=start;
        while(p)
        {
                p1=p1->next;
                delete p;
                p = p1;
        }
}

void SparseList :: store(long ix, int c)
{
        SparseOb *p;
        p = new SparseOb;
        if(!p)
        {
                ShowMessage("Ошибка выделения памяти");
                exit(1);
        }
        p->info = c;
        p->index = ix;
        if(start == NULL)
        {
                end = start = p;
        }
        else
        {
                p->prior = end;
                end->next = p;
                end = p;
        }
}

void SparseList :: remove(long ix)
{
        SparseOb *ob;
        ob = find(ix);
        if(!ob)
                return;
        if(ob->prior)
        {
                ob->prior->next = ob->next;
                if(ob->next)
                        ob->next->prior = ob->next;
                else
                        end = ob->prior;
        }
        else
        {
                if(ob->next){
                        ob->next->prior = NULL;
                        start = ob->next;
                }
                else
                        start = end = NULL;
        }
}

SparseOb *SparseList :: find(long ix)
{
        SparseOb *temp;
        temp = start;
        while(temp)
        {
                if(ix==temp->index)
                        return temp;
                temp = temp->next;
        }
        return NULL;
}

class SparseArray : public ArrayOb
{
        long length;
        ArrayOb *primary;
        SparseList *chains;
        int hash(long ix);

        public:
                SparseArray(long size);
                int &operator[](long i);
};

SparseArray::SparseArray(long size)
{
        long i;
        length = size;
        primary = new ArrayOb[hash(size+1)];
        if(!primary)
        {
                ShowMessage("Ошибка выделения памяти");
                exit(1);
        }
        for(i=0;i<(hash(size)+1);i++)
        {
                primary[i].index = -1;
                primary[i].info = 0;
        }
        chains = new SparseList[hash(size)+1];
}

int &SparseArray::operator [](long ix)
{
        if(ix<0 || ix > length-1)
        {
                ShowMessage("Выход за границы массива");
                exit(1);
        }
        if(ix == primary[hash(ix)].index)
                return primary[hash(ix)].info;
        if(primary[hash(ix)].index == -1)
        {
                primary[hash(ix)].index = ix;
                return primary[hash(ix)].info;
        }
        SparseOb *o;
        o = chains[hash(ix)].find(ix);
        if(!o)
        {
                chains[hash(ix)].store(ix,(int)o);
                o = chains[hash(ix)].find(ix);
        }
        return o->info;
}

int SparseArray :: hash(long ix)
{
        return ix/10;
}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
        

}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{
        SparseArray iob(30);
        int i;
        for(i = 0; i< 30;i++)
                iob[i] = i;
        for(i = 0; i < 30;i++)
                StringGrid1->Cells[i][0]=IntToStr(iob[i]);
        iob[2] = iob[3];
        

}
//---------------------------------------------------------------------------
