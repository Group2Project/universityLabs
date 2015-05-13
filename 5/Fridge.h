//-------------------------------------------------------------------------
class Fridge
{
        private:
                AnsiString name;
                int height;
                float cost;
        public:
                Fridge();
                Fridge(AnsiString,int,float);
                void setName(AnsiString);
                void setHeight(int);
                void setCost(float);
                AnsiString getName();
                int getHeight();
                float getCost();
};

//--------------------------------------------------------------------------
Fridge::Fridge()
{
        name = "���";
        height = 2;
        cost = 3000.25;
}

//--------------------------------------------------------------------------
Fridge::Fridge(AnsiString name,int height,float cost)
{
        this->name = name;
        this->height = height;
        this->cost = cost;
}
//---------------------------------------------------------------------------

void Fridge::setName(AnsiString name)
{
        this->name = name;
}

//---------------------------------------------------------------------------

inline void Fridge::setHeight(int height)
{
        this->height=height;
}

//----------------------------------------------------------------------------

inline void Fridge::setCost(float cost)
{
        this->cost = cost;
}

//----------------------------------------------------------------------------

inline AnsiString Fridge::getName()
{
        return name;
}

//----------------------------------------------------------------------------

inline int Fridge::getHeight()
{
        return height;
}

//----------------------------------------------------------------------------

inline float Fridge::getCost()
{
        return cost;
}

//----------------------------------------------------------------------------