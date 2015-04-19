#include "Unit2.h"

//------------------------------------------------------------------------------

class city
{
        private:
                int number,amount,image_X,image_Y,**road;
        public:
                city *next;
                city(int,int,int,int);

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