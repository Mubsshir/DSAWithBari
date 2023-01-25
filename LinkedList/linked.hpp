#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }
    LinkedList(int a[], int n)
    {
        Node *last, *temp;
        head = new Node;
        head->data = a[0];
        head->next = NULL;
        last = head;

        for (int i = 1; i < n; i++)
        {
            temp = new Node;
            temp->data = a[i];
            temp->next = NULL;
            last->next = temp;
            last = temp;
        }
    }
    ~LinkedList()
    {
        Node *p = head;
        while (head)
        {
            head = head->next;
            delete p;
            p = head;
        }
    }

    void Display();
    int Length();
    int Sum();
    int Max();
    int Min();
    int Search(int key);
};

void LinkedList::Display()
{
    Node *p = head;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

int LinkedList::Length()
{
    int count = 0;
    Node *p = head;
    while (p)
    {
        count++;
        p = p->next;
    }
    return count;
}

int LinkedList::Sum()
{
    int sum = 0;
    Node *p = head;
    while (p)
    {
        sum = p->data;
        p = p->next;
    }
    return sum;
}
int LinkedList::Max()
{
    int max = -32768;
    Node *p = head;
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

int LinkedList::Search(int key)
{
    Node *p = head;
    while (p)
    {
    }
}

// ------------------Non oop code for c only---------------------------------------

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

void FindElementInList(Node *p, int key)
{
    while (p)
    {
        if (p->data == key)
        {
            printf("\nElement found\n");
            return;
        }
        p = p->next;
    }
    printf("\nelement not fond");
}

void FindelemetRec(Node *p, int key)
{
    if (!p)
    {
        printf("\nNot found");
        return;
    }
    if (p->data == key)
    {
        printf("\nElement found");
        return;
    }
    return FindelemetRec(p->next, key);
}

void OptimizedLinearSerach(Node *p, int dataToFind)
{
    Node *first = p;
    Node *q = NULL;
    while (p)
    {
        if (p->data = dataToFind)
        {
            printf("Element found");
            q = p->next;
            p->next = first;
            first = p;
        }
        q = p;
        p = p->next;
    }
}