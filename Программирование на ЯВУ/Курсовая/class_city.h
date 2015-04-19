#include "Unit2.h"

//------------------------------------------------------------------------------

class city
{
        private:
                int number,amount,image_X,image_Y,**road;
        public:
                city *next;
                city(int,int,int,int);
                int get_number();
                int get_amount();
                void set_number(int);
                void set_amount(int);

};

//------------------------------------------------------------------------------

city::city(int num,int amt,int city_X,int city_Y)
{
        number = num;
        amount = amt;
        image_X = city_X;
        image_Y = city_X;
        road = new int *[amount];
        for(int i=0;i<amount;i++)
                road[i] = new int[4];

}

//------------------------------------------------------------------------------

int city::get_number()
{
        return(number);
}

//------------------------------------------------------------------------------

int city::get_amount()
{
        return(amount);
}

//------------------------------------------------------------------------------

void city::set_number(int temp_num)
{
        number = temp_num;
}

//------------------------------------------------------------------------------

void city::set_amount(int temp_amount)
{
        amount = temp_amount;
}

//------------------------------------------------------------------------------