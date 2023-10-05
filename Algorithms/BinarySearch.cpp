#include<iostream>

int BinarySearch(int arr[],int n,int key){
  int h=n-1;
  int l=0;
  int m;
  while(l<=h){
    m=(l+h)/2;
    if(arr[m]==key){
      printf("%d Key Found At index %d",key,m);
      return m;
    }
    else if(arr[m]<key){
      l=m+1;
    }
    else{
      h=m-1;
    }
  }
  printf("Key not found");
  return -1;
}

int RBinarySearch(int lower,int higher,int arr[],int key){
  while(lower<=higher){
    int middle=(lower+higher)/2;
    if(key==arr[middle]){
      printf("%d Key Found At index %d",key,middle);
      return middle;
    }
    else if(key<arr[middle]){
      return RBinarySearch(lower,middle-1,arr,key);
    }
    else{
      return RBinarySearch(middle+1,higher,arr,key);
    }
  }
  return -1;
}
int main(){
  int arr[]={1,2,3,4,5,6,7};
  int n=7;
  int key;
  scanf("%d",&key);
  RBinarySearch(0,n-1,arr,key);
  return 0;
}