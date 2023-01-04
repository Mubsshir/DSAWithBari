#include <iostream>

class Array
{
private:
    int *A;
    int size;
    int length;
    void Swap(int *x, int *y);

public:
    Array()
    {
        size = 10;
        length = 0;
        A = new int[size];
    }
    Array(int sz)
    {
        size = sz;
        length = 0;
        A = new int[size];
    }
    ~Array()
    {
        delete[] A;
    }
    void InsertArray(int *list[], int lengthOfArray);
    void Display();
    bool LinearSearch(int key);
    bool BinarySearch(int key);
    Array *Merge(Array *arr2);
};

void Array::InsertArray(int *array[], int lengthOfArray)
{
    for (int i = 0; i < lengthOfArray; i++)
    {
        A[i] = *array[i];
    }
}
void Array::Display()
{
    // Function for displying element of an array
    printf("\nElements are :\n");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", A[i]);
    }
}

void Array::Swap(int *x, int *y)
{
    // swaping function
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
bool Array::LinearSearch(int key)
{
    for (int i = 0; i < length; i++)
    {
        if (A[i] == key)
        {
            printf("\n%d Found at index %d ", key, i);
            Swap(&A[i], &A[0]);
            return true;
        }
    }
    return false;
}
// use only for sorted array
bool Array::BinarySearch(int key)
{
    int low = 0;
    int high = length - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (A[mid] == key)
        {
            return true;
        }
        else if (A[mid] > key)
        {
            high = mid - 1;
        }
        else
        {

            low = mid + 1;
        }
    }
    return false;
}
// function for mergin two arrays
Array *Array::Merge(Array *arr2)
{
    Array *newArray = new Array(length + arr2->length);
    int i = 0, j = 0, k = 0;
    while (i < length && j < arr2->length)
    {
        if (A[i] < arr2->A[j])
        {
            newArray->A[k++] = A[i++];
        }
        else
        {
            newArray->A[k++] = arr2->A[j++];
        }
    }
    for (i; i < length; i++)
    {
        newArray->A[k++] = A[i];
    }
    for (j; j < arr2->length; j++)
    {
        newArray->A[k++] = arr2->A[j];
    }
    newArray->length = k;
    return newArray;
}
