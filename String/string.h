#include <iostream>
using namespace std;

int Length(char *a)
{
    int i = 0;
    while (a[i] != '\0')
        i++;
    return i;
}

char *ToUpperCase(char *A)
{
    int length = Length(A);
    for (int i = 0; i < length; i++)
    {
        if (A[i] <= 90 && A[i] >= 65) // because we only need to change lower case letters which are b/w 97 and 122;
        {
            continue;
        }
        else if (A[i] <= 122 && A[i] >= 97) // if character is lower case make is uppercase
        {
            A[i] = A[i] - 32;
        }
        else // if there is special charactor
        {
            continue;
        }
    }
    return A;
}
char *ToLowerCase(char *A)
{
    int length = Length(A);
    for (int i = 0; i < length; i++)
    {
        if (A[i] <= 90 && A[i] >= 65) // because we only need to change upper case letters which are b/w 97 and 122;
        {
            A[i] = A[i] + 32;
        }
        else if (A[i] <= 122 && A[i] >= 97) // if character is upper case make is lowercase
        {
            continue;
        }
        else // if there is special charactor
        {
            continue;
        }
    }
    return A;
}

char *ToTitleCase(char *A)
{
    int length = Length(A);
    for (int i = 0; i < length; i++)
    {
        if (i == 0 && A[i] <= 122 && A[i] >= 97)
        {
            A[i] = A[i] - 32;
        }
        else if (i != 0)
        {
            if (A[i] <= 122 && A[i] >= 97)
            {
                continue;
            }
            else if (A[i] <= 90 && A[i] >= 65)
            {
                A[i] = A[i] + 32;
            }
            else
            {
                continue;
            }
        }
    }
    return A;
}

int CountVowelAndConsonent(char *a)
{
    int vowel = 0;
    int consonent = 0;
    for (int i = 0; a[i] != '\0'; i++)
    {
        if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u' || a[i] == 'A' || a[i] == 'E' || a[i] == 'I' || a[i] == 'O' || a[i] == 'U')
        {
            vowel++;
        }
        else if ((a[i] <= 90 && a[i] >= 65) || (a[i] <= 122 && a[i] >= 97))
        {
            consonent++;
        }
    }
    printf("No of Consonent  : %d\n", consonent);
    printf("No of Vowel  : %d\n", vowel);
    return 0;
}

int CountWords(char *a)
{
    int count = 1;
    for (int i = 0; a[i] != '\0'; i++)
    {
        if (a[i] == ' ' && a[i - 1] != ' ')
        {
            count++;
        }
    }
    return count;
}

void FindDuplicateInString(char *a)
{
    char Hash[26] = {0};
    for (int i = 0; a[i] != '\0'; i++)
    {
        Hash[a[i] - 97]++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (Hash[i] > 1)
        {
            printf("Duplicate : %c \n", i + 97);
            printf("Occure %d time\n", Hash[i]);
        }
    }
}

void FindDuplicateInStringBitwise(char *a)
{
    std::cout << "I run";
    long int H = 0, x = 0;
    for (int i = 0; a[i] != '\0'; i++)
    {
        x = 1;
        x = x << a[i] - 97;
        if (x & H > 0)
        {
            printf("%c is duplicate", a[i]);
        }
        else
        {
            H = x | H;
        }
    }
}

bool IsAnagram(char *a, char *b)
{
    if (Length(a) != Length(b))
    {
        return false;
    }
    int H[26] = {}, i = 0;
    for (i = 0; a[i] != '\0'; i++)
    {
        H[a[i] - 97]++;
    }
    for (i = 0; b[i] != '\0'; i++)
    {
        H[b[i] - 97]--;
        if (H[b[i] - 97] < 0)
        {
            return false;
        }
    }
    if (b[i] == '\0')
    {
        return true;
    }
    return NULL;
}

void Perm(char *a, int k)
{
    static char flag[10] = {0};
    static char result[10];
    int i;
    if (a[k] == '\0')
    {
        result[k] = '\0';
        printf("%s\n", result);
    }
    for (i = 0; a[i] != '\0'; i++)
    {
        if (flag[i] == 0)
        {
            result[k] = a[i];
            flag[i] = 1;
            Perm(a, k + 1);
            flag[i] = 0;
        }
    }
}
void Swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}
void PermBySwap(char *s, int l, int h)
{
    int i;
    if (l == h)
    {
        printf("%s \n", s);
    }
    else
    {
        for (i = l; i <= h; i++)
        {
            Swap(&s[i], &s[l]);
            PermBySwap(s, l + 1, h);
            Swap(&s[i], &s[l]);
        }
    }
}