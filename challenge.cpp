// find missing element in a array
#include <iostream>
#include "array.h"
int main()
{
    struct Array arr = {{4, 5, 6, 8, 9, 10, 11, 12, 15}, 10, 9};
    Display(&arr);
    FindMissing2(arr);
    return 0;
}