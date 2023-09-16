#include <iostream>
using namespace std;
struct term
{
  int coefficient;
  int exponent;
};

class Poly
{
private:
  int n;
  term *t;
  int idx = 0;

public:
  Poly()
  {
    this->t = new term[1];
  };
  Poly(int n)
  {
    this->n = n;
    this->t = new term[n];
  };
  ~Poly()
  {
    delete[] t;
  }
  void DisplayExpression();
  void addTerm(int c, int e);
};

void Poly::DisplayExpression()
{
  for (int i = 0; i < this->idx - 1; i++)
  {
    if(this->t[i].exponent!=0){
      printf("%dX^%d + ", this->t[i].coefficient, this->t[i].exponent);
    }else{
      printf("%d +", this->t[i].coefficient, this->t[i].exponent);
    }
  }
  if(this->t[this->idx-1].exponent!=0){
      printf("%dX^%d", this->t[this->idx-1].coefficient, this->t[this->idx-1].exponent);
    }else{
      printf("%d ", this->t[this->idx-1].coefficient, this->t[this->idx-1].exponent);
    }
}

void Poly::addTerm(int c,int e){
  if(this->idx<this->n){
    term t;
    t.coefficient=c;
    t.exponent=e;
    this->t[idx]=t;
    this->idx++;
  }
  else{
    std::cout<<"you are out of space";
  }
}