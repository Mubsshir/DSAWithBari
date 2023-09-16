#include "sparse.h"

int main()
{
    Sparse sp(4, 5, 5), sp2(4, 5, 5);
    sp.SetElement(1, 3, 7);
    sp.SetElement(2, 1, 2);
    sp.SetElement(2, 5, 1);
    sp.SetElement(3, 1, 3);
    sp.SetElement(4, 3, 1);
    sp.Display();

    sp2.SetElement(1, 3, 7);
    sp2.SetElement(1, 4, 2);
    sp2.SetElement(2, 5, 1);
    sp2.SetElement(3, 1, 3);
    sp2.SetElement(4, 3, 1);
    printf("----------------\n");
    sp2.Display();
    Sparse sp3(4, 5, 12);
    sp3 = AddSparse(sp, sp2);
    printf("----------------\n");
    sp3.Display();
    return 0;
}