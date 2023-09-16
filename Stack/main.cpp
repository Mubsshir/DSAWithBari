#include "stackLink.hpp"
using namespace std;
int main()
{
  string exp="[a+(a-b)*{(a-3)+((a-9)}]";
  Stack st;
  cout<<st.IsParanthesisMatch(exp);
  return 0;
}