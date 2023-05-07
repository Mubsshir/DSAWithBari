#include "linked.hpp"
using namespace std;

int main()
{
    int a[6]={1,2,3,10,4,-9};   
    LinkedList list(a,6);
    list.Display();
    list.Insert(6,7);
    list.Display();
    return 0;
}
