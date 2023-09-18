#include "Sorting.hpp"

int main() {
  int myArray[] = {10, 9, 1, 2, 3, 6,2,4,5,6, 4};
  show(myArray, sizeof(myArray) / sizeof(myArray[0]));
  BubbleSort(myArray,sizeof(myArray) / sizeof(myArray[0]));
  show(myArray,sizeof(myArray) / sizeof(myArray[0]));
  return 0;
}