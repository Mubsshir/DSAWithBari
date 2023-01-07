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
    static int index;
    struct Element *ele;

public:
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
        this->num = 2;
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
};

void Sparse::SetElement(int i, int j, int x)
{
    if (index < num)
    {
        ele[index].i = i;
        ele[index].j = j;
        ele[index].x = x;
        index++;
    }
}

int Sparse::GetElement(int idx)
{
    return ele[idx].x;
}