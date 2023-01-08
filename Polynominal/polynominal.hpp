#include <iostream>
using namespace std;

struct Term
{
    int cofficient;
    int exponent;
};

class Polynominal
{
private:
    int n;
    struct Term *term;
    int idx = 0;

public:
    Polynominal()
    {
        this->n = 1;
        this->term = new Term[n];
    }
    Polynominal(int n)
    {
        this->n = n;
        this->term = new Term[n];
    }
    ~Polynominal()
    {
        delete[] term;
    }
    void SetPoly(int c, int e);
    string GetPoly();
};

void Polynominal::SetPoly(int c, int e)
{
    if (idx < this->n)
    {
        term[idx].cofficient = c;
        term[idx].exponent = e;
        idx++;
    }
}

string Polynominal::GetPoly()
{
    string rep = "";
    for (int i = 0; i < n; i++)
    {
        if (i != n - 1)
        {
            rep += ("%dx^%d + ", term[i].cofficient, term[i].exponent);
        }
        else
        {
            rep += ("%d ", term[i].cofficient);
        }
    }
    return rep;
}