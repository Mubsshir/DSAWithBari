#include "linked.hpp"
using namespace std;

void Hell(LinkedList *hello)
{
    hello->Display();
}
int main()
{
    int a[] = {1, 2, 3, 4, 5};
    LinkedList list(a, 5,0);
    list.Display();
    return 0;
}