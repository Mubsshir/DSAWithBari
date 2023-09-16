#include "matrix.hpp"

int main() {
  Matrix a(2, 2);
  a.SetElement(1, 1, 1);
  a.SetElement(1, 2, 1);
  a.SetElement(2, 1, 1);
  a.SetElement(2, 2, 1);
  a.Show();
  Matrix b(2, 3);
  b.SetElement(1, 1, 2);
  b.SetElement(1, 2, 2);
  b.SetElement(1, 3, 2);

  b.SetElement(2, 1, 2);
  b.SetElement(2, 2, 2);
  b.SetElement(2, 3, 2);
  cout << b.GetElement(3, 2);
  b.Show();
  Matrix result=Matrix::Multiply(a,b);
  result.Show();
  return 0;
}