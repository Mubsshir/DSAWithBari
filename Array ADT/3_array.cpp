#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <iostream>
#include "array.h"

int main()
{
    struct Array arr = {{5, 6, 78, 9, 56, 16}, 20, 6};
    Display(arr);
    printf("\nArray after reversing\n");

    while (true)
    {
        Sleep(500);
        system("cls");
        LefthiftArray(&arr, arr.length);
        Display(arr);
    }
}