#include <iostream>
using namespace std;

class Matrix
{
protected:
    int *A;
    int n;

public:
    Matrix()
    {
        n = 2;
        A = new int[n * n];
    }
    Matrix(int n)
    {
        this->n = n;
        A = new int[n * n];
    }
    virtual ~Matrix()
    {
        delete[] A;
    }
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
    void SetRow(int i, int j, int x);
    int GetRow(int i, int j);
    void DisplayRow();
};

class SymMatrix : public Matrix
{

public:
    SymMatrix()
    {
        n = 2;
        A = new int[n * (n + 1) / 2];
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
    int GetRow(int i, int j);
    void DisplayRow();
};

class UTMatrix : public Matrix
{

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
    virtual void SetCol(int i, int j, int x);
    int GetRow(int i, int j);
    virtual int GetCol(int i, int j);
    void DisplayRow();
    virtual void DisplayCol();
};
class LTMatrix : public UTMatrix
{
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

class Diagonal : public Matrix
{
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

class TriDiagMatrix : public Matrix
{
public:
    TriDiagMatrix()
    {
        this->n = 2;
        A = new int[4];
    }
    TriDiagMatrix(int n)
    {
        this->n = n;
        A = new int[3 * n - 2];
    }
    ~TriDiagMatrix()
    {
        delete[] A;
    }
    void setMatrix(int i, int j, int x);
    int getMatrix(int i, int j);
    void Display();
};

void TriDiagMatrix::setMatrix(int i, int j, int x)
{
    if (i - j == 0)
    {
        A[n + i - 2] = x;
    }
    else if (i - j == 1)
        A[j - 1] = x;
    else if (i - j == -1)
        A[2 * (n - 1) + i] = x;
}

int TriDiagMatrix::getMatrix(int i, int j)
{
    if (i - j == 0)
    {
        return A[n + i - 2];
    }
    else if (i - j == 1)
        return A[j - 1];
    else if (i - j == -1)
        return A[2 * (n - 1) + i];
    else
    {
        return 0;
    }
}

void TriDiagMatrix::Display()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i - j == 0)
            {
                printf("%02d  ", A[n + i - 2]);
            }
            else if (i - j == 1)
                printf("%02d  ", A[j - 1]);
            else if (i - j == -1)
                printf("%02d  ", A[2 * (n - 1) + i]);
            else
            {
                printf("%02d  ");
            }
        }
        printf("\n");
    }
}

class TopLitzMatrix : public Matrix
{
public:
    TopLitzMatrix()
    {
        this->n = 2;
        A = new int[4];
    }
    TopLitzMatrix(int n)
    {
        this->n = n;
        A = new int[2 * n - 1];
    }
    ~TopLitzMatrix()
    {
        delete[] A;
    }
    void setMatrix(int i, int j, int x);
    int getMatrix(int i, int j);
    void Display();
};

void TopLitzMatrix::setMatrix(int i, int j, int x)
{
    if (i <= j)
    {
        A[j - i] = x;
    }
    else if (i > j)
    {
        A[n + i - j - 1] = x;
    }
}

int TopLitzMatrix::getMatrix(int i, int j)
{
    if (i <= j)
    {
        return A[j - i];
    }

    return A[n + i - j - 1];
}

void TopLitzMatrix::Display()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i <= j)
            {
                printf("%02d ", A[j - i]);
            }
            else if (i > j)
            {
                printf("%02d ", A[n + i - j - 1]);
            }
            else
            {
                printf("00 ");
            }
        }
        printf("\n");
    }
}