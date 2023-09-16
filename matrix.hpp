#include <iostream>
using namespace std;

class Matrix
{
public:
  int m, n;
  int *matrix;

  Matrix()
  {
    this->matrix = new int[4];
  }
  Matrix(int m, int n)
  {
    this->m = m;
    this->n = n;
    this->matrix = new int[m * n];
  }
  ~Matrix()
  {
    delete[] matrix;
  }
  void Show();
  void SetElement(int i, int j, int x);
  int GetElement(int i, int j);
  static Matrix Multiply(Matrix a, Matrix b);
};

void Matrix::SetElement(int i, int j, int x)
{
  if (i <= this->n && j <= this->n)
  {
    this->matrix[3 * i + j - 4] = x;
    return;
  }
  cout << "Out of array boundary";
}

int Matrix::GetElement(int i, int j)
{
  if (i <= this->n && j <= this->n)
  {
    return this->matrix[3 * i + j - 4];
  }
  cout << "Out of array boundary";
  return;
}

void Matrix::Show()
{
  for (int i = 1; i < this->m + 1; i++)
  {
    for (int j = 1; j < this->n + 1; j++)
    {
      printf("%d  ",GetElement(i,j));
    }
    cout<<"\n\n";
  }
}