#include "stack.hpp"


int main(){
  Stack st(3);
  st.Push(2);
  st.Push(21);
  st.Push(32);
  st.Display();
  int *x=st.Peak(3);
  x!=nullptr?std::cout<<*x:std::cout<<"Invalid Position";
  return 0;
}