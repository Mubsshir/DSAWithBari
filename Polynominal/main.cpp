#include "polynominal.hpp"

int main()
{
    Polynomial p(5);
    p.SetPoly(5, 4);
    p.SetPoly(9, 3);
    p.SetPoly(3, 2);
    p.SetPoly(4, 1);
    p.SetPoly(1, 0);
    p.Display();
    Polynomial q(5);
    q.SetPoly(5, 4);
    q.SetPoly(9, 3);
    q.SetPoly(3, 2);
    q.SetPoly(4, 1);
    q.SetPoly(1, 0);
    cout << "\n--------------------\n";
    q.Display();
    cout << "\n--------------------\n";
    Polynomial r = Polynomial ::AddPolynomial(p, q);
    r.Display();
    return 0;
}