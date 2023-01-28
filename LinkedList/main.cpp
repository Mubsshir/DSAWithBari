#include "linked.hpp"
int main()
{
    // int a[] = {1, 2, 3, 4, 5};
    LinkedList list;
    list.Push(1);
    list.Push(2);
    list.Push(3);
    list.Push(4);
    list.Push(5);
    list.Display();
    list.InsertAt(5, 8);
    list.Display();
    return 0;
}
