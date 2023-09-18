#include<iostream>

using namespace std;


class Matrix{
  private:
    int n;
    int *e;
  public:
    Matrix(){
      this->e=new int[4];
    }
    Matrix(int n){
      this->n=n;
      this->e=new int[n*n];
    }
    ~Matrix(){
      delete [] this->e;
    }
    void Display();
    void AddElement(int i,int j,int x);
};

void Matrix::AddElement(int i ,int j,int x){
  this->e[i+j]=x;
}

void Matrix::Display(){
  for(int i =0;i<this->n*this->n;i++){
    for(int j=0;j<this->n*this->n;j++){
      printf("%d",this->e[i+j]);
    }
  }
}