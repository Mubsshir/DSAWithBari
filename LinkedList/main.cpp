#include "linked.hpp"
using namespace std;

void Hell(LinkedList *hello)
{
    hello->Display();
}
int main()
{
    int a[] = {1, 2, 3, 4, 5};
    DoublyLinkedList list(a,5);
    list.Display();
    list.Reverse();
    list.Display();
    return 0;
}