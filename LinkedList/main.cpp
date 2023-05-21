#include "linked.hpp"
using namespace std;


int main()
{
    int a[]={1,2,3,4,5};
    DoublyLinkedList list(a,5,0);
    list.Display();
    list.Reverse();
    list.Display();
    return 0;
}