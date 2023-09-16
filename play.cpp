#include "matrix.hpp"

int main(){
  Matrix a(2,2);
  a.SetElement(1,1,1);
  a.SetElement(1,2,4);
  a.SetElement(2,1,3);
  a.SetElement(2,2,9);
  return 0;
}