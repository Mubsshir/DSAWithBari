#include <iostream>
using namespace std;

struct Element
{
    int i, j, x;
};

class Sparse
{
public:
    int m, n, num;
    struct Element *ele;
    int index;
    Sparse()
    {
        m = 5;
        n = 6;
        num = 2;
        ele = new Element[num];
        index = 0;
    }
    Sparse(int m, int n, int num)
    {
        this->m = m;
        this->n = n;
        this->num = num;
        ele = new Element[num];
        index = 0;
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

Sparse AddSparse(Sparse a, Sparse b)
{
    if (a.m != b.m || a.n != b.n)
    {
        cerr << "Only matrices with same dimensions can be added" << endl;
        return Sparse();
    }
    Sparse sp(a.m, a.n, a.num + b.num);

    int i = 0, j = 0;
    while (i < a.num && j < b.num)
    {
        if (a.ele[i].i == b.ele[j].i && a.ele[i].j == b.ele[j].j)
        {
            sp.SetElement(a.ele[i].i, a.ele[i].j, a.ele[i].x + b.ele[j].x);
            i++;
            j++;
        }
        else if (a.ele[i].i < b.ele[j].i || (a.ele[i].i == b.ele[j].i && a.ele[i].j < b.ele[j].j))
        {
            sp.SetElement(a.ele[i].i, a.ele[i].j, a.ele[i].x);
            i++;
        }
        else
        {
            sp.SetElement(b.ele[j].i, b.ele[j].j, b.ele[j].x);
            j++;
        }
    }
    while (i < a.num)
    {
        sp.SetElement(a.ele[i].i, a.ele[i].j, a.ele[i].x);
        i++;
    }
    while (j < b.num)
    {
        sp.SetElement(b.ele[j].i, b.ele[j].j, b.ele[j].x);
        j++;
    }

    return sp;
}