//-------------------------------------------------------------------------
class Book
{
        private:
                AnsiString author;
                AnsiString name;
                float cost;
        public:
                Book();
                Book(AnsiString,AnsiString,float);
                void setAuthor(AnsiString);
                void setName(AnsiString);
                void setCost(float);
                AnsiString getAuthor();
                AnsiString getName();
                float getCost();
};

//--------------------------------------------------------------------------
Book::Book()
{
        author = "Автор";
        name = "Название";
        cost = 700.25;
}

//--------------------------------------------------------------------------
Book::Book(AnsiString author,AnsiString name,float cost)
{
        this->author = author;
        this->name = name;
        this->cost = cost;
}
//---------------------------------------------------------------------------

void Book::setName(AnsiString name)
{
        this->name = name;
}

//---------------------------------------------------------------------------

inline void Book::setAuthor(AnsiString author)
{
        this->author=author;
}

//----------------------------------------------------------------------------

inline void Book::setCost(float cost)
{
        this->cost = cost;
}

//----------------------------------------------------------------------------

inline AnsiString Book::getName()
{
        return name;
}

//----------------------------------------------------------------------------

inline AnsiString Book::getAuthor()
{
        return author;
}

//----------------------------------------------------------------------------

inline float Book::getCost()
{
        return cost;
}

//----------------------------------------------------------------------------