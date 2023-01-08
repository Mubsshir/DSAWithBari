#include "polynominal.hpp"

int main()
{
    Polynominal p(3);
    p.SetPoly(3, 2);
    p.SetPoly(4, 1);
    p.SetPoly(1, 0);
    cout << p.GetPoly();
    return 0;
}