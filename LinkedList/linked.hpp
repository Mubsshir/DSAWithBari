#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void Display(Node *p)
{
    Node *current = p;
    while (current)
    {
        printf("%d ", current->data);
        current = current->next;
    }
}
void DisplayRecursive(Node *p)
{
    if (p)
    {
        printf("%d ", p->data);
        Display(p->next);
    }
}
int Length(Node *p)
{
    int count = 0;
    while (p)
    {
        count++;
        p = p->next;
    }
    return count;
}

int LengthR(Node *p)
{
    if (p)
    {
        return Length(p->next) + 1;
    }
    return 0;
}

int SumUp(Node *p)
{
    int sum = 0;
    while (p)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int SumUpR(Node *p)
{
    if (p)
    {
        return p->data + SumUpR(p->next);
    }
    return 0;
}

int FindMax(Node *p)
{
    int max = -32768;
    while (p)
    {
        if (p->data > max)
        {
            max = p->data;
        }
        p = p->next;
    }
    return max;
}