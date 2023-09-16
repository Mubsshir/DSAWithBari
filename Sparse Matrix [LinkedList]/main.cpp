#include<iostream>
#include "sparse.hpp"

int main() {
  SparseMatrix matrix(3, 4);
  matrix.SetElement(0, 1, 2);
  matrix.SetElement(1, 2, 5);
  matrix.SetElement(2, 0, 1);
  matrix.SetElement(2, 3, 7);

  matrix.Display();

  return 0;
}
