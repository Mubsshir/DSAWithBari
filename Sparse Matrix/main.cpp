#include "sparse.h"

int main()
{
    Sparse sp(4, 5, 5);
    sp.SetElement(1, 3, 7);
    sp.SetElement(2, 1, 2);
    sp.SetElement(2, 5, 1);
    sp.SetElement(3, 1, 3);
    sp.SetElement(4, 3, 1);
    return 0;
}