#include "linked.hpp"
using namespace std;

int main()
{
    LinkedList list;
    list.Insert(3);
    list.Insert(5);
    list.Insert(15);
    list.Display();
    list.InsertSort(16);
    list.Display();
    list.Insert(17);
    list.Display();
    list.InsertSort(14);
    list.Display();
    return 0;
}
