#include <iostream>
using namespace std;

class Matrix {
public:
  int m, n;
  int *matrix;

  Matrix() { this->matrix = new int[4]; }
  Matrix(int m, int n) {
    this->m = m;
    this->n = n;
    this->matrix = new int[m * n];
  }
  ~Matrix() { delete[] matrix; }
  void Show();
  void SetElement(int i, int j, int x);
  int GetElement(int i, int j);
  static Matrix Multiply(Matrix a, Matrix b);
};

void Matrix::SetElement(int i, int j, int x) {
  if (i <= this->n && j <= this->n) {
    this->matrix[3 * i + j - 4] = x;
    return;
  }
  throw out_of_range("Out of array boundary");
}

int Matrix::GetElement(int i, int j) {
  if (i <= this->n && j <= this->n) {
    return this->matrix[3 * i + j - 4];
  }
  throw out_of_range("Out of array boundary");
}

void Matrix::Show() {
  cout << "\n";
  for (int i = 1; i <= this->m; i++) {
    for (int j = 1; j <= this->n; j++) {
      printf("%d  ", GetElement(i, j));
    }
    cout << "\n\n";
  }
}

Matrix Matrix::Multiply(Matrix a, Matrix b) {
  Matrix c(b.m, b.n);
  if (a.n != b.m)
    throw range_error("\nColumn of 1st matrix should be equal to rows of 2nd matrix.");
  for (int i = 1; i <= a.n; i++) {
    for (int j = 1; j <= b.n; j++) {
      int sum = 0;
      for (int k = 1; k <= b.m; k++) {
        sum += a.GetElement(i, k) * b.GetElement(k, j);
      }
      c.SetElement(i, j, sum);
    }
  }
  return c;
}