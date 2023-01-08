#include "linked.hpp"
int main()
{
    Node *head = new Node;
    Node *first = new Node;
    Node *second = new Node;

    head->data = 2;
    head->next = first;
    first->data = 3;
    first->next = second;
    second->data = 6;
    second->next = NULL;
    Display(head);
    cout << "\n"
         << LengthR(head);
    cout << "\nSum: " << SumUpR(head);
    cout << "\nmax: " << FindMax(head);
    return 0;
}
