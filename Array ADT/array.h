#include <iostream>
using namespace std;
struct Array
{
    /* data */
    int A[20];
    int size;
    int length;
};
struct MinMax
{
    int min;
    int max;
};
void Display(struct Array *arr)
{
    // Function for displying element of an array
    printf("\nElements are :\n");
    for (int i = 0; i < arr->length; i++)
    {
        printf("%d ", arr->A[i]);
    }
    printf("\n_______________");
}

void Display(int A[], int length)
{
    // Function for displying element of an array
    printf("\nElements are :\n");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n_______________");
}

int FindMax(struct Array arr)
{
    int max = arr.A[0];
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.A[i] > max)
        {
            max = arr.A[i];
        }
    }
    return max;
};
int FindMin(struct Array arr)
{
    int min = arr.A[0];
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.A[i] < min)
        {
            min = arr.A[i];
        }
    }
    return min;
};
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
bool LinearSearch(struct Array *arr, int valueToSearch)
{
    for (int i = 0; i < arr->length; i++)
    {
        if (arr->A[i] == valueToSearch)
        {
            printf("\n%d Found at index %d ", valueToSearch, i);
            Swap(&arr->A[i], &arr->A[0]);
            return true;
        }
    }
    return false;
}
// use only for sorted array
bool BinarySearch(struct Array *arr, int valueTosearch)
{
    int low = 0;
    int high = arr->length - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr->A[mid] == valueTosearch)
        {
            return true;
        }
        else if (arr->A[mid] > valueTosearch)
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

void Reverse(struct Array *arr, int length)
{
    int temp[length];
    int j = 0;
    for (int i = length - 1; i >= 0; i--)
    {
        temp[j] = arr->A[i];
        j++;
    }
    for (int i = 0; i <= length - 1; i++)
    {
        arr->A[i] = temp[i];
    }
}
void ReverseByInterchange(struct Array *arr, int length)
{
    int j = length - 1;
    for (int i = 0; i < j; i++)
    {
        Swap(&arr->A[i], &arr->A[j]);
        j--;
    }
}

void LefthiftArray(struct Array *arr, int length)
{
    int temp = arr->A[0];
    for (int i = 0; i < length; i++)
    {
        arr->A[i] = arr->A[i + 1];
    }
    arr->A[length - 1] = temp;
}

// function for inserting an element at sorted array
void InsertInSortedArray(struct Array *arr, int element)
{
    int i = arr->length - 1;

    while (element < arr->A[i])
    {
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = element;
}
// funtion to check if array is sorted
bool IsArraySorted(struct Array arr)
{
    for (int i = 0; i < arr.length - 1; i++)
    {
        if (arr.A[i] > arr.A[i + 1])
        {
            return false;
        }
    }
    return true;
}
// function to move negative elements on left and positive on right side
void SortingArrayNegToPos(struct Array *arr)
{
    int i = 0;
    int j = arr->length - 1;
    while (i < j)
    {
        while (arr->A[i] < 0)
        {
            i++;
        }
        while (arr->A[j] >= 0)
        {
            /* code */
            j--;
        }
        if (i < j)
        {
            Swap(&arr->A[i], &arr->A[j]);
        }
    }
}

// function for mergin two arrays
Array Merge(struct Array arr1, struct Array arr2)
{
    struct Array newArray;
    newArray.length = arr1.length + arr2.length;
    newArray.size = newArray.length;
    int i = 0, j = 0, k = 0;
    while (i < arr1.length && j < arr2.length)
    {
        if (arr1.A[i] < arr2.A[j])
        {
            newArray.A[k++] = arr1.A[i++];
        }
        else
        {
            newArray.A[k++] = arr2.A[j++];
        }
    }
    for (i; i < arr1.length; i++)
    {
        newArray.A[k++] = arr1.A[i];
    }
    for (j; j < arr2.length; j++)
    {
        newArray.A[k++] = arr2.A[j];
    }
    return newArray;
}

// union of two set
Array UnionOfSortedArray(struct Array arr1, struct Array arr2)
{
    struct Array unionArray;

    unionArray.size = unionArray.length;
    int i = 0, j = 0, k = 0;
    while (i < arr1.length && j < arr2.length)
    {
        if (arr1.A[i] < arr2.A[j])
        {
            unionArray.A[k++] = arr1.A[i++];
        }
        else if (arr1.A[i] == arr2.A[j])
        {
            unionArray.A[k++] = arr1.A[i++];
            j++;
        }
        else
        {
            unionArray.A[k++] = arr2.A[j++];
        }
    }
    for (i; i < arr1.length; i++)
    {
        unionArray.A[k++] = arr1.A[i];
    }
    for (j; j < arr2.length; j++)
    {
        unionArray.A[k++] = arr2.A[j];
    }

    unionArray.length = k;
    return unionArray;
}
// union of unsorted arrays
struct Array *unionOfUnsorted(struct Array *arr1, struct Array *arr2)
{
    struct Array *arr3;
    arr3 = (struct Array *)malloc(sizeof(struct Array));
    int k = 0, i = 0;
    for (i = 0; i < arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i];
    }
    for (i = 0; i < arr2->length - 1; i++)
    {
        if (!LinearSearch(arr1, arr2->A[i]))
        {
            arr3->A[k++] = arr2->A[i];
        }
    }
    arr3->length = k;
    return arr3;
}

// intersection of 2 unsorted sets

struct Array *Intersection(struct Array *arr1, struct Array *arr2)
{
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    int i = 0, k = 0;
    for (i; i < arr1->length; i++)
    {
        if (LinearSearch(arr2, arr1->A[i]))
        {
            arr3->A[k++] = arr1->A[i];
        }
    }
    arr3->length = k;
    return arr3;
}

// intersection of 2 sorted Array

struct Array *IntersectionSorted(struct Array *arr1, struct Array *arr2)
{
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    int i = 0, j = 0, k = 0;
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
        {
            i++;
        }
        else if (arr1->A[i] > arr2->A[j])
        {
            j++;
        }
        else
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    arr3->length = k;
    return arr3;
}

// difference of 2 unsorted array

struct Array *UDiffrence(struct Array *arr1, struct Array *arr2)
{
    struct Array *arr3;
    arr3 = (struct Array *)malloc(sizeof(struct Array));
    int i = 0, k = 0;
    for (i; i < arr1->length; i++)
    {
        if (!LinearSearch(arr2, arr1->A[i]))
        {
            arr3->A[k++] = arr1->A[i];
        }
    }
    arr3->length = k;
    return arr3;
}

struct Array *Diffrence(struct Array *arr1, struct Array *arr2)
{
    struct Array *arr3;
    arr3 = (struct Array *)malloc(sizeof(struct Array));
    int i = 0, j = 0, k = 0;
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
        }
        else if (arr1->A[i] > arr2->A[j])
        {
            j++;
        }
        else
        {
            i++;
            j++;
        }
    }
    for (i; i < arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i];
    }
    arr3->length = k;
    return arr3;
}

// find missing element in a sorted array of n natural numbers

int FindMissing(struct Array arr)
{
    int n = arr.length;
    int sum = 0;
    for (int i = 0; i < arr.length - 1; i++)
    {
        sum += arr.A[i];
    }
    int S = (n * (n + 1)) / 2;
    int missingNumber = S - sum;
    return missingNumber;
}
void FindMissing2(struct Array arr)
{
    int l = arr.A[0];
    int n = arr.length;
    int diff = l - 0;
    for (int i = 0; i < n; i++)
    {
        if (arr.A[i] - i != diff)
        {
            while (diff < arr.A[i] - i)
            {
                printf(" \nmissing =%d ", diff + i);
                diff++;
            }
        }
    }
}

void FindMissing3(struct Array arr)
{

    int max = FindMax(arr);
    int min = FindMin(arr);
    int HashTable[max + 1] = {0};
    for (int i = 0; i < arr.length; i++)
    {
        HashTable[arr.A[i]]++;
    }
    Display(HashTable, max);
    for (int i = min; i < max; i++)
    {
        if (HashTable[i] != 1)
        {
            printf("\nMissing: %d", i);
        }
    }
}
// FInd Duplicate in sorted array
void FindDuplicate(struct Array arr)
{
    int duplicate = 0;
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.A[i] == arr.A[i + 1] && arr.A[i + 1] != duplicate)
        {
            printf("\nFound duplicate: %d", arr.A[i]);
            duplicate = arr.A[i];
        }
    }
}

void FindDuplicate2(struct Array arr)
{
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.A[i] == arr.A[i + 1])
        {
            int j = i + 1;
            while (arr.A[j] == arr.A[i])
                j++;
            printf("\n\n%d is appearing %d time", arr.A[i], j - i);
            i = j - 1;
        }
    }
}
// FInd Duplicate in unsorted array
// Time complexity is O{n^2}
void FindDuplicate3(struct Array arr)
{
    for (int i = 0; i < arr.length; i++)
    {
        int count = 1;
        if (arr.A[i] != -1)
        {
            for (int j = i + 1; j < arr.length; j++)
            {
                if (arr.A[j] == arr.A[i])
                {
                    count++;
                    arr.A[j] = -1;
                }
            }
        }
        if (count > 1)
            printf("\n%d is appearing %d time", arr.A[i], count);
    }
}

// FInd Duplicate in unsorted array using hash table
void FindDuplicate4(struct Array arr)
{
    int max = FindMax(arr);
    int min = FindMin(arr);
    int HashTable[max + 1] = {0};
    for (int i = 0; i < arr.length; i++)
    {
        HashTable[arr.A[i]]++;
    }
    for (int i = min; i < max; i++)
    {
        if (HashTable[i] > 1)
        {
            printf("\n %d is appeared %d times", i, HashTable[i]);
        }
    }
}

void PairWithSumK(struct Array arr, int k)
{
    for (int i = 0; i < arr.length; i++)
    {
        for (int j = i + 1; j < arr.length; j++)
        {
            if (arr.A[i] + arr.A[j] == k)
            {
                printf("\npair<%d, %d>", arr.A[i], arr.A[j]);
            }
        }
    }
}
// using hashmap
void HPairWithSumK(struct Array arr, int k)
{
    int max = FindMax(arr);
    int HashMap[max + 1] = {0};
    for (int i = 0; i < arr.length; i++)
    {
        if (HashMap[k - arr.A[i]] != 0)
        {
            printf("\npair<%d, %d>", arr.A[i], k - arr.A[i]);
        }
        HashMap[arr.A[i]]++;
    }
}

// in sorted array
void SPairWithSumK(struct Array arr, int k)
{
    int i = 0, j = arr.length - 1;
    while (i < j)
    {
        if (arr.A[i] + arr.A[j] == k)
        {
            printf("\n%d + %d = %d", arr.A[i], arr.A[j], k);
            i++;
            j--;
        }
        else if (arr.A[i] + arr.A[j] > k)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
}

// find max and min on a single scan

MinMax FindMinMax(struct Array arr)
{
    struct MinMax mm;
    mm.min = arr.A[0];
    mm.max = arr.A[0];

    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] > mm.max)
        {
            mm.max = arr.A[i];
        }
        else
        {
            mm.min = arr.A[i];
        }
    }
    return mm;
}