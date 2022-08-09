#include <iostream>
void Swap(int a, int b)
{
    printf("Values before swap operation a=%d b=%d", a, b);
    a = a * b; //a=10*20=200
    b = a / b;//b=200/20=10
    a = a / b;//a=200/10=20
    printf("\nValues after swap  operation a=%d b=%d", a, b);
}
int main()
{
    int k = 1;

    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 7; j++)
        {
            if (j >= 5 - i && j <= 3 + i)
            {
                printf("%d", k);
                j < 4 ? k++ : k--;
            }
            else
            {
                printf(" ");
            }
        }
        k = 1;
        printf("\n");
    }
    return 0;
}