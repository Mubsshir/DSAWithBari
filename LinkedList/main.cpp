#include "linked.hpp"

void Swap(int *x, int *y)
{
    // swaping function
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void sortEvenOdd(int arr[], int n)
{
    int left = 0, right = n - 1;
    // move odd integer on right side and even to left side
    while (left < right)
    {
        while (arr[left] % 2 == 0)
        {
            left++;
        }
        while (arr[right] % 2 != 0)
        {
            right--;
        }
        if (left < right)
        {
            Swap(&arr[left], &arr[right]);
        }
    }

    // sort even integer in ascending order
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 != 0)
        {
            break;
        }
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] % 2 == 0 && arr[j] % 2 == 0)
            {
                if (arr[i] > arr[j])
                {
                    Swap(&arr[i], &arr[j]);
                }
                continue;
            }
            break;
        }
    }

    // sort odd integer in descending order
    for (int i = n - 1; i > 0; i--)
    {
        if (arr[i] % 2 == 0)
        {
            break;
        }
        for (int j = i - 1; j > 0; j--)
        {
            if (arr[i] % 2 != 0 && arr[j] % 2 != 0)
            {
                if (arr[i] > arr[j])
                {
                    Swap(&arr[i], &arr[j]);
                }
            }
        }
    }
}

int main()
{
    int a[9] = {2, 8, 3, 9, 6, 4, 1, 5, 7};
    int n = sizeof(a) / sizeof(int);
    sortEvenOdd(a, n);

    // display
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
