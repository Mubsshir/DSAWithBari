#include "linked.hpp"
using namespace std;

void Hell(LinkedList *hello)
{
    hello->Display();
}
int main()
{
    int a[] = {1, 2, 3, 4, 5};
    LinkedList list(0);
    list.Insert(23);
    list.Insert(3);
    list.Insert(13);
    list.Insert(2);
    list.Insert(1,0);
    list.Insert(1,0);
    list.Insert(1,0);
    list.Insert(1,0);
    cout<<list.Length()<<endl;
    list.Display();
    list.Delete(8);
    cout<<list.Length()<<endl;
    list.Display();
    return 0;
}