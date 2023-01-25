#include "linked.hpp"
int main()
{
    LinkedList list;
    list.Add(1);
    list.Add(2);
    list.Add(3);
    list.Display();
    list.OSearch(5);
    list.Display();
    list.OSearch(3);
    list.Display();
    return 0;
}
