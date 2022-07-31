#include <iostream>

struct Array
{
    /* data */
    int A[20];
    int size;
    int length;
};

void Display(struct Array arr)
{
    // Function for displying element of an array
    printf("\nElements are :\n");
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
}

void Append(struct Array *arr, int value)
{
    // Funtion for appending a value in array
    if (arr->length < arr->size)
    {
        arr->A[arr->length++] = value;
    }
}
void Insert(struct Array *arr, int index, int value)
{
    if (index >= 0 && index <= arr->length)
    {
        for (int i = arr->length; i > index; i--)
            arr->A[i] = arr->A[i - 1];

        arr->A[index] = value;
        arr->length++;
    }
}
void Delete(struct Array *arr, int index)
{
    if (index >= 0 && index <= arr->length)
    {
        for (int i = index; i <= arr->length - 1; i++)
            arr->A[i] = arr->A[i + 1];
        arr->length--;
    }
}

void Swap(int *x, int *y)
{
    // swaping function
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void LinearSearch(struct Array *arr, int valueToSearch)
{
    for (int i = 0; i < arr->length; i++)
    {
        if (arr->A[i] == valueToSearch)
        {
            printf("\n%d Found at index %d ", valueToSearch, i);
            Swap(&arr->A[i], &arr->A[0]);
            return;
        }
    }
    printf("\nnot found");
}

void BinarySearch(struct Array arr, int valueTosearch)
{
    int low = 0;
    int high = arr.length - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr.A[mid] == valueTosearch)
        {
            printf("\nValue found at index %d", mid);
            return;
        }
        else if (arr.A[mid] > valueTosearch)
        {
            high = mid - 1;
        }
        else
        {

            low = mid + 1;
        }
    }
    printf("\nValue not found");
}
void BinarySearch_recurssive(int a[], int low, int length, int valueTosearch)
{
    if (low <= length - 1)
    {
        int mid = (low + length - 1) / 2;
        if (a[mid] == valueTosearch)
        {
            printf("\nValue found at index %d", mid);
            return;
        }
        else if (a[mid] < valueTosearch)
        {
            low = mid + 1;
            return BinarySearch_recurssive(a, low, length, valueTosearch);
        }
        else
        {
            length = mid - 2;
            return BinarySearch_recurssive(a, low, length, valueTosearch);
        }
    }
    printf("Value Not Found");
}