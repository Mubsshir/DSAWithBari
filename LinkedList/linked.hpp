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
    Node *head, *tail;

public:
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }
    LinkedList(int a[], int n)
    {
        Node *temp;
        head = new Node;
        head->data = a[0];
        head->next = NULL;
        tail = head;

        for (int i = 1; i < n; i++)
        {
            temp = new Node;
            temp->data = a[i];
            temp->next = NULL;
            tail->next = temp;
            tail = temp;
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
    bool Search(int key);
    bool OSearch(int key);
    void Push(int x);
    void TPush(int x);
    void InsertToStart(int x);
    void InsertAt(int pos, int ele);
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

bool LinkedList::Search(int key)
{
    Node *p = head;
    while (p)
    {
        if (p->data == key)
        {
            printf("Key Found");
            return true;
        }
        p = p->next;
    }
    return false;
}

bool LinkedList::OSearch(int key)
{
    if (head->data == key)
    {
        printf("\nKey Found\n");
        return true;
    }
    Node *q = nullptr;
    Node *p = head;
    while (p)
    {
        if (p->data == key)
        {
            printf("\nKey Found\n");
            q->next = p->next;
            p->next = head;
            head = p;
            return true;
        }
        q = p;
        p = p->next;
    }
    printf("\nKey not found\n");
    return false;
}

void LinkedList::Push(int x)
{
    Node *node = new Node;
    node->data = x;
    node->next = NULL;
    // if list is empty then add data to head;

    if (head == NULL)
    {
        head = tail = node;
        return;
    }

    // if list is not empty then point tail pointer to node
    tail->next = node;
    tail = node;
}

void LinkedList::TPush(int x)
{
    Node *node = new Node;
    node->data = x;
    node->next = NULL;
    // if list is empty then add data to head;

    if (head == NULL)
    {
        head = node;
        return;
    }

    // if list is not empty then walk the list till last node
    Node *p = head;
    while (p->next)
    {
        p = p->next;
    }
    p->next = node;
}

void LinkedList::InsertToStart(int x)
{
    Node *node = new Node;
    node->data = x;
    node->next = head;
    head = node;
}

void LinkedList::InsertAt(int pos, int ele)
{
    Node *node = new Node;
    node->data = ele;
    Node *p = head;
    for (int i = 1; i < pos; i++)
    {
        p = p->next;
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