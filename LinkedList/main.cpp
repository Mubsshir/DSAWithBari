#include "linked.hpp"
int main()
{
    int a[] = {1, 2, 3, 4, 5};
    LinkedList list(a, 5);
    list.Display();
    list.OSearch(5);
    list.Display();
    list.OSearch(3);
    list.Display();
    return 0;
}
