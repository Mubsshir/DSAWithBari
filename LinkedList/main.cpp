#include "linked.hpp"

int main(){
   LinkedList list;
   list.Push(1);
   list.Push(2);
   list.Push(4);
   list.Display();
   list.OptimizeSearch(2);
   list.Display();
    return 0;
}