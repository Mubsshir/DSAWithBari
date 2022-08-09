// find missing element in a array
#include <iostream>
#include "array.h"

int main()
{
    struct Array arr = {{4, 5, 6, 9, 9, 11, 11, 11, 15}, 10, 9};
    Display(&arr);
    FindDuplicate(arr);
    return 0;
}
