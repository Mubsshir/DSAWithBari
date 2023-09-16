#include<iostream>
#include<vector>
#include"poly.hpp"
using namespace std;

void DisplayExpression(vector<int> c){
  int len=c.size();
  for(int i=len-1;i>0;i--){
    printf("%dX^%d+",c[len-i-1],i);
  }
  printf("%d",c[len-1]);
}

int BruteForcePoly(vector<int> coefficients , int x){
  int sum=0;
  int len=coefficients.size();
  for(int i=0;i<len-1;i++){
    //solve degree of x
    int degree=1;
    for(int j=0;j<len-i;j++){
      degree*=x;
    }
    sum+=(degree*coefficients[i]);
  }
  return sum+coefficients[len-1];//add last coefficient with 0 degree and return result
}

int HornerAlgoPoly (vector<int> coefficients, int x){
  int s=coefficients[0];
  for(int i=1;i<coefficients.size();i++){
    s=s*x+coefficients[i];
  }
  return s;
}

int main(){
  // Poly p(4);
  // p.addTerm(2,3);
  // p.addTerm(3,2);
  // p.addTerm(1,1);
  // p.addTerm(4,0);
  // p.DisplayExpression();
  vector<int> coefficients={3,2,0,-5,7};
  DisplayExpression(coefficients);
  cout<<"\n"<<BruteForcePoly(coefficients,1);
  cout<<"\n"<<HornerAlgoPoly(coefficients,1);
  return 0;
}