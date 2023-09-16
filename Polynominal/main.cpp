#include "polynominal.hpp"

int main()
{
    LinkedPoly exp;
    exp.InsertTerm(4,2);
    exp.InsertTerm(3,2);
    exp.InsertTerm(5,1);
    exp.InsertTerm(1,0);
    exp.DisplayExpression();
    cout<<endl<<exp.SolveExpression(2);
    return 0;
}