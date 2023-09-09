#include <iostream>
using namespace std;
class Node
{
public:
  int ele;
  Node *next;
};
class Stack
{
private:
  Node *head = nullptr;

public:
  Stack()
  {
    head = nullptr;
  }
  Stack(int a[], int n)
  {
    head = new Node;
    head->ele = a[0];
    head->next = nullptr;
    Node *p;
    for (int i = 1; i < n; i++)
    {
      p = new Node;
      p->ele = a[i];
      p->next = head;
      head = p;
    }
  }
  ~Stack()
  {
    if (!head)
      return;
    Node *p = head;
    while (p)
    {
      head = head->next;
      delete p;
      p = head;
    }
  }
  void Push(int element);
  int *Pop();
  int *Peak(int pos);
  void Display();
  bool isEmpty();
  bool isFull();
  int *getTopValue();
  bool IsParanthesisMatch(string ab);
};

void Stack::Push(int element)
{
  Node *p = new Node;
  if (p)
  {
    p->ele = element;
    p->next = head;
    head = p;
  }
  else
  {
    std::cout << "Stack overflow";
  }
}

int *Stack::Pop()
{
  int *x = nullptr;
  if (head)
  {
    Node *p;
    p = head;
    x = &p->ele;
    head = head->next;
    delete p;
  }
  return x;
}

void Stack::Display()
{
  Node *p = head;
  printf("\n");
  while (p)
  {
    printf("| %2d |\n", p->ele);
    printf(" --- \n");
    p = p->next;
  }
  printf("\n");
}

int *Stack::Peak(int pos)
{
  int count = 0;
  Node *p = head;
  while (p)
  {
    count++;
    if (count == pos)
    {
      return &p->ele;
    }
    p = p->next;
  }
  return nullptr;
}

bool Stack::isEmpty()
{
  return !head;
}

bool Stack::isFull()
{
  Node *p = new Node;
  return p ? false : true;
}

int *Stack::getTopValue()
{
  if (head)
  {
    return &head->ele;
  }
  return nullptr;
}

bool Stack::IsParanthesisMatch(string a)
{
  for (int i = 0; a[i] != '\0'; i++)
  {
    if (a[i] == '(' || a[i] == '[' || a[i] == '{')
    {
      Push(a[i]);
    }
    else if (a[i] == ')')
    {
      if (isEmpty())
        return false;
      if (*getTopValue() != '(')
      {
        return false;
      }
      Pop();
    }
    else if (a[i] == ']')
    {
      if (isEmpty())
        return false;
      if (*getTopValue() != '[')
      {
        return false;
      }
      Pop();
    }
    else if (a[i] == '}')
    {
      if (isEmpty())
        return false;
      if (*getTopValue() != '{')
      {
        return false;
      }
      Pop();
    }
  }
  return isEmpty();
}