#include <stdio.h>
#include "Matrices.h"

int main()
{
    SymMatrix LMat(4);
    LMat.SetRow(1, 1, 1);
    LMat.SetRow(2, 1, 2);
    LMat.SetRow(2, 2, 3);
    LMat.SetRow(3, 1, 4);
    LMat.SetRow(3, 2, 5);
    LMat.SetRow(3, 3, 6);
    LMat.SetRow(4, 1, 7);
    LMat.SetRow(4, 2, 8);
    LMat.SetRow(4, 3, 9);
    LMat.SetRow(4, 4, 10);
    LMat.DisplayRow();
    return 0;
}