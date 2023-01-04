#include <iostream>
using namespace std;

class SymMatrix
{
private:
    int *A;
    int n;

public:
    SymMatrix()
    {
        n = 2;
        A = new int[n];
    }
    SymMatrix(int n)
    {
        this->n = n;
        A = new int[n * (n + 1) / 2];
    }
    ~SymMatrix()
    {
        delete[] A;
    }
    void SetRow(int i, int j, int x);
    void SetCol(int i, int j, int x);
    int GetRow(int i, int j);
    int GetCol(int i, int j);
    void DisplayRow();
    void DisplayCol();
};

class UTMatrix
{
private:
    int *A;
    int n;

public:
    UTMatrix()
    {
        n = 2;
        A = new int[2 * (2 + 1) / 2];
    }
    UTMatrix(int n)
    {
        this->n = n;
        A = new int[n * (n + 1) / 2];
    }

    ~UTMatrix()
    {
        delete[] A;
    }
    void SetRow(int i, int j, int x);
    void SetCol(int i, int j, int x);
    int GetRow(int i, int j);
    int GetCol(int i, int j);
    void DisplayRow();
    void DisplayCol();
};
class LTMatrix
{
private:
    int *A;
    int n;

public:
    LTMatrix()
    {
        n = 2;
        A = new int[2 * (2 + 1) / 2];
    }
    LTMatrix(int n)
    {
        this->n = n;
        A = new int[n * (n + 1) / 2];
    }
    ~LTMatrix()
    {
        delete[] A;
    }
    void SetRow(int i, int j, int x);
    void SetCol(int i, int j, int x);
    int GetRow(int i, int j);
    int GetCol(int i, int j);
    void DisplayRow();
    void DisplayCol();
};

class Diagonal
{
private:
    int *A;
    int n;

public:
    Diagonal()
    {
        n = 2;
        A = new int[2];
    }
    Diagonal(int n)
    {
        this->n = n;
        A = new int[n];
    }
    ~Diagonal()
    {
        delete[] A;
    }
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
};

void Diagonal::Set(int i, int j, int x)
{
    if (i == j)
    {
        A[i - 1] = x;
    }
}
int Diagonal::Get(int i, int j)
{
    if (i == j)
    {
        return A[i - 1];
    }
    else
    {
        return 0;
    }
}
void Diagonal::Display()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                cout << A[i] << " ";
                continue;
            }
            cout << "0 ";
        }
        cout << "\n";
    }
}

void LTMatrix::SetRow(int i, int j, int x)
{
    if (i >= j)
    {
        A[i * (i - 1) / 2 + j - 1] = x;
    }
}
void LTMatrix::SetCol(int i, int j, int x)
{
    if (i >= j)
    {
        A[n * (j - 1) - ((j - 2) * (j - 3)) / 2 + i - j] = x;
    }
}
int LTMatrix::GetRow(int i, int j)
{
    if (i >= j)
    {
        return A[i * (i - 1) / 2 + j - 1];
    }
    return 0;
}

int LTMatrix::GetCol(int i, int j)
{
    if (i >= j)
    {
        return A[n * (j - 1) - ((j - 2) * (j - 3)) / 2 + i - j];
    }
    return 0;
}

void LTMatrix::DisplayRow()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i >= j)
            {
                printf("%d ", A[(i * (i - 1) / 2 + j - 1)]);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}
void LTMatrix::DisplayCol()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i >= j)

            {
                printf("%d ", A[n * (j - 1) - ((j - 2) * (j - 3)) / 2 + i - j]);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

void UTMatrix::SetRow(int i, int j, int x)
{
    if (i <= j)
    {
        A[n * (i - 1) - ((i - 2) * (i - 1)) / 2 + j - i] = x;
    }
}
void UTMatrix::SetCol(int i, int j, int x)
{
    if (i <= j)
    {
        A[j * (j - 1) / 2 + i - 1] = x;
    }
}

int UTMatrix::GetRow(int i, int j)
{
    if (i <= j)
    {
        return A[n * (i - 1) - ((i - 2) * (i - 1)) / 2 + j - i];
    }
    return 0;
}
int UTMatrix::GetCol(int i, int j)
{
    if (i <= j)
    {
        return A[j * (j - 1) / 2 + i - 1];
    }
    return 0;
}
void UTMatrix::DisplayRow()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i <= j)
            {
                printf("%d ", A[n * (i - 1) - ((i - 2) * (i - 1)) / 2 + j - i]);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}
void UTMatrix::DisplayCol()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i <= j)
            {
                printf("%d ", A[j * (j - 1) / 2 + i - 1]);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}
// symmetric  using lower triangle

void SymMatrix::SetRow(int i, int j, int x)
{
    A[i * (i - 1) / 2 + j - 1] = x;
}

int SymMatrix::GetRow(int i, int j)
{
    if (i >= j)
    {
        return A[i * (i - 1) / 2 + j - 1];
    }
    else
    {
        return A[j * (j - 1) / 2 + i - 1];
    }
}

void SymMatrix::DisplayRow()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i >= j)
            {
                printf("%02d ", A[i * (i - 1) / 2 + j - 1]);
            }
            else
            {
                printf("%02d ", A[j * (j - 1) / 2 + i - 1]);
            }
        }
        printf("\n");
    }
}