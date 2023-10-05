#include<iostream>
using namespace std;

void Swap(int *a,int *b){
  int temp=*a;
  *a=*b;
  *b=temp;
}
int Partition(int arr[],int lower,int upper){
  int pivot=arr[lower];
  int i=lower, j=upper+1;
    while (i<j)
  {
    do{i++;}while(arr[i]<=pivot);
    do{j--;}while(arr[j]>pivot);
    if(i<j){
      Swap(&arr[i],&arr[j]);
    }
  }
  Swap(&arr[lower],&arr[j]);
  return j;
}

void QuickSort(int arr[],int lower,int upper){
  if(lower<upper){
    int j=Partition(arr,lower,upper);
    
    QuickSort(arr,lower,j-1);
    QuickSort(arr,j+1,upper);
  }
}


int main(){
  int arr[]={2,1,4,8,7,5,19,9,10};
  cout<<"Original Array : "<<endl;
   for(int i=0;i<9;i++){
    printf("%d ",arr[i]);
  }
  QuickSort(arr,0,9);
  //Swap(&arr[0],&arr[8]);
  cout<<"\nSorted array "<<endl;
  for(int i=0;i<9;i++){
    printf("%d ",arr[i]);
  }
  return 0;
}