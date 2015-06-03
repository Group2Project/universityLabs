#include "Unit2.h"
#include <math.h>
//------------------------------------------------------------------------------
enum mode{NOTHING,IN_CITY,IN_ROAD,DEL_CITY,DEL_ROAD};
extern int current_mode(NOTHING);
//------------------------------------------------------------------------------

class city
{
        private:
                int number,amount,image_X,image_Y,**road;
                bool filled;
        public:
                city *next;
                city(int,int,int,int);
                int get_number();
                int get_amount();
                int get_image_X();
                int get_image_Y();
                int get_road(int,int);
                bool get_filled();
                void set_number(int);
                void set_amount(int);
                void enter_road(int,int,int,int,int);
                void set_filled(bool);
};

//------------------------------------------------------------------------------

city::city(int number,int amount,int image_X,int image_Y)
{

        this->number = number;
        this->amount = amount;
        this->image_X = image_X;
        this->image_Y = image_Y;
        road = new int *[amount];
        if(!amount)
                filled = true;
        else
                filled = false;
        for(int i=0;i<amount;i++)
                road[i] = new int[4];

}

//------------------------------------------------------------------------------

inline int city::get_number()
{
        return(number);
}

//------------------------------------------------------------------------------

inline bool city::get_filled()
{
        return(filled);
}

//------------------------------------------------------------------------------

inline void city::set_filled(bool b)
{
        filled = b;
}

//

inline int city::get_amount()
{
        return(amount);
}

//------------------------------------------------------------------------------

inline void city::set_number(int temp_num)
{
        number = temp_num;
}

//------------------------------------------------------------------------------

inline int city::get_image_Y()
{
        return(image_Y);
}

//------------------------------------------------------------------------------

inline int city::get_image_X()
{
        return(image_X);
}

//------------------------------------------------------------------------------

inline void city::set_amount(int temp_amount)
{
        amount = temp_amount;
}

//------------------------------------------------------------------------------

void city::enter_road(int n,int num,int x,int y,int dist)
{
        road[n-1][0] = num;
        road[n-1][1] = x;
        road[n-1][2] = y;
        road[n-1][3] = dist;
}

//------------------------------------------------------------------------------

inline int city::get_road(int i, int j)
{
        return road[i][j];
}

//------------------------------------------------------------------------------

inline void arrow(TImage *temp_image,int x1,int y1,int x2,int y2)
{
        temp_image->Canvas->Pen->Width=2;
        temp_image->Canvas->MoveTo(x1,y1);
        temp_image->Canvas->LineTo(x2,y2);
        //temp_image->Canvas->LineTo(x2-2,y2-10);
        //temp_image->Canvas->MoveTo(x2,y2);
        //temp_image->Canvas->LineTo(x2-10,y2-2);
}

//------------------------------------------------------------------------------

extern city *head,*last_added;

//------------------------------------------------------------------------------
int test_circle(int test_X,int test_Y)
{
        bool test(false);
        city *temp_city = head;
        int k(0);

        while(temp_city!=last_added->next)
        {
                k = pow((test_X - temp_city->get_image_X()),2) + pow((test_Y - temp_city->get_image_Y()),2);
                if(k <= 64)
                {
                        test = true;
                        break;
                }
                temp_city=temp_city->next;
        }
        if(test)
                return temp_city->get_number();
        else
                return -1;
}

//------------------------------------------------------------------------------
