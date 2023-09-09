#include<iostream>
#include<vector>
using namespace std;

void DisplayExpression(vector<int> c){
  int len=c.size();
  for(int i=len-1;i>0;i--){
    printf("%dX^%d+",c[len-i-1],i);
  }
  printf("%d",c[len-1]);
}

int main(){
  vector<int> coefficients={5,8,6,9};
  DisplayExpression(coefficients);
  return 0;
}