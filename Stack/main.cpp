#include "stackLink.hpp"
using namespace std;
int main()
{
  string exp="((()))))";
  Stack st;
  cout<<st.IsParanthesisMatch(exp);
  return 0;
}