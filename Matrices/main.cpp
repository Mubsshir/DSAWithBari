#include <stdio.h>
#include "Matrices.h"

int main()
{
    TopLitzMatrix top(5);
    top.setMatrix(1, 1, 5);
    top.setMatrix(1, 2, 6);
    top.setMatrix(1, 3, 7);
    top.setMatrix(1, 4, 8);
    top.setMatrix(1, 5, 9);
    top.setMatrix(2, 1, 1);
    top.setMatrix(3, 1, 2);
    top.setMatrix(4, 1, 3);
    top.setMatrix(5, 1, 4);
    top.Display();
    return 0;
}