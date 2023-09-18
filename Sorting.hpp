#include <iostream>
using namespace std;

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}



void show(int a[], int size) {
  for(int i=0;i<size;i++){
    cout<<a[i]<<" ";
  }
  cout<<endl;
}

void BubbleSort(int a[], int size) {
  for (int i = size-1; i > 0; i--) {
    for (int j = 0; j <= i ; j++) {
      if(a[j]>a[j+1]){
        swap(&a[j], &a[j + 1]);
      }
    }
  }

}