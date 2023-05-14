#include "linked.hpp"
using namespace std;

int main()
{
    LinkedList list;
    list.Insert(3);
    list.Insert(5);
    list.Insert(7);
    list.Insert(7);
    list.Insert(7);
    list.Insert(17);
    list.Insert(17);
    list.Display();
    list.RemoveDuplicates();
    list.Display();
    list.Reverse();
    list.Display();
    return 0;
}