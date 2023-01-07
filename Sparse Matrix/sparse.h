#include <iostream>
using namespace std;

struct Element
{
    int i, j, x;
};

class Sparse
{
private:
    int m, n, num;
    struct Element *ele;

public:
    static int index;
    Sparse()
    {
        m = 5;
        n = 6;
        num = 2;
        ele = new Element[num];
    }
    Sparse(int m, int n, int num)
    {
        this->m = m;
        this->n = n;
        this->num = num;
        ele = new Element[num];
    }
    ~Sparse()
    {
        delete[] ele;
    }
    void CreateSparse();
    void SetElement(int i, int j, int x);
    int GetElement(int idx);
    void Display();
    int GetElemets(int i, int j);
};

int Sparse::index = 0;

void Sparse::SetElement(int i, int j, int x)
{
    if (this->index < num)
    {
        ele[this->index].i = i;
        ele[this->index].j = j;
        ele[this->index].x = x;
        this->index++;
    }
}

int Sparse::GetElement(int idx)
{
    return ele[idx - 1].x;
}

int Sparse::GetElemets(int i, int j)
{
    for (int a = 0; a < num; a++)
    {
        if (ele[a].i == i && ele[a].j == j)
        {
            return ele[a].x;
        }
    }
    return 0;
}

void Sparse::Display()
{
    for (int a = 1; a <= m; a++)
    {
        for (int b = 1; b <= n; b++)
        {
            printf("%02d ", GetElemets(a, b));
        }
        printf("\n");
    }
}