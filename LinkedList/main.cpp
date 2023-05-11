#include "linked.hpp"
using namespace std;

int main()
{
    LinkedList list;
    list.Insert(3);
    list.Insert(5);
    list.Insert(15);
    list.Insert(17);
    list.Display();
    list.Delete(4);
    list.Insert(43,-1);
    list.Display();
    return 0;
}