#include "Unit2.h"
#include <math.h>
#include <vector.h>
//------------------------------------------------------------------------------

class city
{
        private:
                int number,amount,road_filled,**road,image_X,image_Y;
                bool filled;
        public:
                city(int,int,int,int);
                ~city();
                int get_number();
                int get_amount();
                int get_image_X();
                int get_image_Y();
                int get_road(int,int);
                int get_road_filled();
                int find_road(int);
                bool get_filled();
                bool test_connect(int);
                void rebuild_road(int);
                void set_road_filled(signed int);
                void set_road(int);
                void set_number(int);
                void set_amount(int);
                void enter_road(int,int,int,int,int);
                void set_filled(bool);
};

//------------------------------------------------------------------------------

city::city(int num,int amt,int city_X,int city_Y)
{

        number = num;
        amount = amt;
        road_filled = 0;
        image_X = city_X;
        image_Y = city_Y;
        if(!amt)
                filled = true;
        else
        {
                road = new int *[amount];
                for(int i=0;i<amount;i++)
                        road[i] = new int[4];
                filled = false;
        }
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

//------------------------------------------------------------------------------

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

inline bool city::test_connect(int k)
{
        for(int i=0;i<this->amount;i++)
                if(this->road[i][0]==k)
                        return true;
        return false;
}

//------------------------------------------------------------------------------

inline void city::set_road_filled(signed int i)
{
        road_filled+=i;
}

//------------------------------------------------------------------------------

inline int city::get_road_filled()
{
        return road_filled;
}

//------------------------------------------------------------------------------

void city::rebuild_road(int k)
{
        if(amount==0)
        {
                for(int i=0;i<amount+1;i++)
                        delete[] road[i];
                delete[] road;
                return;
        }
        if(road_filled==0)
                return;
        int **temp_road;
        temp_road = new int *[amount+1];
        for(int i=0;i<amount+1;i++)
                temp_road[i]=new int[4];
        for(int i=0;i<amount+1;i++)
                for(int j=0;j<4;j++)
                        temp_road[i][j]=road[i][j];
        for(int i=k;i<amount;i++)
                for(int j=0;j<4;j++)
                        temp_road[i][j]=temp_road[i+1][j];
        for(int i=0;i<amount+1;i++)
               delete[] road[i];
        delete[] road;
        road = new int*[amount];
        for(int i=0;i<amount;i++)
                road[i]=new int[4];
        for(int i=0;i<road_filled;i++)
                for(int j=0;j<4;j++)
                        road[i][j]=temp_road[i][j];

}
//------------------------------------------------------------------------------

int city::find_road(int k)
{
        if(amount == 0)
                return -1;
        for(int i=0;i<amount;i++)
                if(road[i][0]==k)
                        return i;
        return -1;
}

//------------------------------------------------------------------------------

void city::set_road(int k)
{
        for(int i=0;i<road_filled;i++)
                if(road[i][0]>k)
                        road[i][0]--;
}

//------------------------------------------------------------------------------

city::~city()
{
}

//------------------------------------------------------------------------------

extern vector<city> sp_city;
//------------------------------------------------------------------------------
void arrow(TImage *Image1,int start_i,int end_i)
{
        int x1=sp_city.at(start_i).get_image_X();
        int y1=sp_city.at(start_i).get_image_Y();
        int x2=sp_city.at(end_i).get_image_X();
        int y2=sp_city.at(end_i).get_image_Y();
        Image1->Canvas->Pen->Width=2;
        Image1->Canvas->MoveTo(x1,y1);
        Image1->Canvas->LineTo(x2,y2);
        Image1->Canvas->Pen->Width=1.5;
        Image1->Canvas->Ellipse(sp_city[start_i].get_image_X()-8,sp_city[start_i].get_image_Y()-8,sp_city[start_i].get_image_X()+8,sp_city[start_i].get_image_Y()+8);
        if(!sp_city[end_i].get_filled())
                        Image1->Canvas->Brush->Color=clBlue;
        else
                        Image1->Canvas->Brush->Color=clRed;
        Image1->Canvas->Ellipse(sp_city.at(end_i).get_image_X()-8,sp_city.at(end_i).get_image_Y()-8,sp_city.at(end_i).get_image_X()+8,sp_city.at(end_i).get_image_Y()+8);

}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
int test_circle(int test_X,int test_Y)
{
        int k(0);
        for(unsigned int i=0;i<sp_city.size();i++)
        {
                k = pow((test_X - sp_city.at(i).get_image_X()),2) + pow((test_Y - sp_city.at(i).get_image_Y()),2);
                if(k <= 64)
                {
                        return sp_city[i].get_number();
                }
        }
        return -1;
}

//------------------------------------------------------------------------------


void del_unit(int del_i,TImage *Image1)
{
        for(unsigned int i=0;i<sp_city.size();i++)
        {
                int k = sp_city[i].find_road(del_i);
                if(k!=-1)
                {
                        sp_city[i].set_amount(sp_city[i].get_amount()-1);
                        sp_city[i].set_road_filled(-1);
                        sp_city[i].rebuild_road(k);
                        if(sp_city[i].get_amount()==0)
                                sp_city[i].set_filled(true);
                }
                sp_city[i].set_road(del_i);
        }
}

//------------------------------------------------------------------------------

void rebuild_map(TImage *Image1)
{
        Image1->Canvas->Brush->Color=clWhite;
        Image1->Canvas->Rectangle(0,0,633,737);
        for(unsigned int i=0;i<sp_city.size();i++)
        {
                if(sp_city.at(i).get_road_filled() < sp_city.at(i).get_amount())
                        Image1->Canvas->Brush->Color=clBlue;
                if(sp_city.at(i).get_road_filled() == sp_city.at(i).get_amount())
                        Image1->Canvas->Brush->Color=clRed;
                Image1->Canvas->Ellipse(sp_city.at(i).get_image_X()+8,sp_city.at(i).get_image_Y()+8,sp_city.at(i).get_image_X()-8,sp_city.at(i).get_image_Y()-8);
        }
        for(unsigned int i=0;i<sp_city.size();i++)
        {
                if(sp_city[i].get_amount()!=0 && sp_city[i].get_road_filled()!=0)
                        for(int j=0;j<sp_city[i].get_road_filled();j++)
                                arrow(Image1,i,sp_city.at(i).get_road(j,0));
        }

}

//-----------------------------------------------------------------------------

void rebuild_sp_city(int del_i)
{
        for(unsigned int i=del_i;i<sp_city.size()-1;i++)
        {
                sp_city[i]=sp_city[i+1];
                sp_city[i].set_number(sp_city[i].get_number()-1);
        }
        sp_city.pop_back();
}

//-----------------------------------------------------------------------------

void search_euler(int k,int **ms,vector<int> &path)
{
        path.push_back(k);
        for (unsigned int i=0; i < sp_city.size(); ++i)
                if (ms[k][i])
                {
                        ms[k][i] = 0;
                        search_euler (i, ms, path);
                }
}

//-----------------------------------------------------------------------------

bool test_str_connect(int **ms)
{
        for(unsigned int i=0;i<sp_city.size()-1;i++)
                for(unsigned int j=i+1;j<sp_city.size();i++)
                        if(ms[i][j]==ms[j][i])
                                return true;
        return false;
}

//-----------------------------------------------------------------------------

bool test_degree()
{
        vector<int> degree(sp_city.size(),0);
        for(unsigned int i=0;i<sp_city.size();i++)
        {
                degree[i]=sp_city[i].get_amount();
                for(unsigned int j=0;j<sp_city.size();j++)
                        if(sp_city[j].find_road(sp_city[i].get_number())!=-1)
                                degree[i]+=1;
        }
        for(unsigned int i=0;i<sp_city.size();i++)
                if(degree[i]%2!=0)
                {
                        return false;
                }
        return true;
}

//-----------------------------------------------------------------------------


