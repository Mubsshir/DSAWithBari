#include <iostream>
class Stack
{
private:
  int *A;

public:
  int top = -1, size;
  Stack()
  {
    size = 1;
    A = new int[size];
  }
  Stack(int size)
  {
    this->size = size;
    A = new int[this->size];
  }
  ~Stack()
  {
    delete A;
  }
  void Push(int element);
  int *Pop();
  int *Peak(int pos);
  void Display();
  bool isEmpty();
  bool isFull();
  int* getTopValue();
};

void Stack::Push(int element)
{
  if (top < size)
  {
    top++;
    A[top] = element;
  }
  else
  {
    std::cout << "Stack overflow";
  }
}

int *Stack::Pop()
{
  int *x = nullptr;
  if (top == -1)
  {
    std::cout << "stack underflow";
    return x;
  }
  x=&A[top];
  top--;  
  return x;
}

void Stack::Display()
{
  int i = top;
  printf("\n");
  while (i != -1)
  {
    printf("| %2d |\n", A[i]);
    printf(" --- \n");
    i--;
  }
  printf("\n");
}


int* Stack::Peak(int pos){
  int* x=nullptr;
  if(pos<=top+1){
    x= &A[top-pos+1];
  }
  return x;
}

bool Stack::isEmpty(){
  return top==-1;
}

bool Stack::isFull(){
  return top==size-1;
}

int* Stack::getTopValue(){
  int*x=nullptr;
  if(!isEmpty()){
    x=&A[top];
  }
  return x;
}