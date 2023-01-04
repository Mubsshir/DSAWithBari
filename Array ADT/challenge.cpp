#include "array.h"

int main()
{
    struct Array arr = {{5, 6, 4, 8, 9, 11}, 20, 6};
    struct MinMax mm = FindMinMax(arr);
    std::cout << "Max " << mm.max;
    std::cout << "\nMin " << mm.min;

    return 0;
}