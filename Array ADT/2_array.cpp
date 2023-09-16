#include <iostream>
#include "array.h"

int FindMax(struct Array arr)
{
    int max = arr.A[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] > max)
        {
            max = arr.A[i];
        }
    }
    return max;
}
int FindMin(struct Array arr)
{
    int min = arr.A[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] < min)
        {
            min = arr.A[i];
        }
    }
    return min;
}
int Sum(int a[], int n)
{
    if (n < 0)
    {
        return 0;
    }
    return Sum(a, n - 1) + a[n];
}

int Avg(int a[], int n)
{
    return Sum(a, n - 1) / (n - 1);
}

int main()
{
    struct Array arr = {{10, 10, 10, 15, 12}, 10, 5};
    Display(arr);
    printf("\nMax value in array is %d", FindMax(arr));
    printf("\nAvg of all the element is %d", Avg(arr.A, arr.length));
    return 0;
}