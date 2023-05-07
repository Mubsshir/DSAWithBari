#include <iostream>

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
    head = nullptr;
    tail = nullptr;
  }
  LinkedList(int a[], int n)
  {
    Node *temp;
    head=new Node;
    head->data = a[0];
    head->next = nullptr;
    tail = head;
    for (int i = 1; i < n; i++)
    {
      temp = new Node;
      temp->data = a[i];
      temp->next = nullptr;
      tail->next = temp;
      tail = temp;
    }
  }
  ~LinkedList()
  {
    Node *temp = head;
    while (head)
    {
      head = head->next;
      delete temp;
      temp = head;
    }
  }
  void Display();
  int Length();
  int FindMax();
  int FindMin();
  bool Search(int key);
  bool OSearch(int key);
  void Insert(int element,int positon=-1);
};

void LinkedList::Display()
{
  Node *p = head;
  while (p)
  {
    printf("%d ", p->data);
    p = p->next;
  }
  printf("\n");
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

int LinkedList::FindMax()
{
  int max = INT_MIN;
  // create a walker node
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

int LinkedList::FindMin()
{
  int min = INT_MAX;
  // create a walker node
  Node *p = head;
  while (p)
  {
    if (p->data < min)
    {
      min = p->data;
    }
    p = p->next;
  }
  return min;
}

bool LinkedList::Search(int key)
{
  Node *p = head;
  while (p)
  {
    if (p->data == key)
    {
      printf("\nElement Found");
      return true;
    }
    p = p->next;
  }
  printf("\nElement not Found");
  return false;
}

bool LinkedList::OSearch(int key)
{
  Node *p, *q;
  q = nullptr;
  p = head;
  while (p)
  {
    if (p->data == key)
    {
      q->next=p->next;
      p->next = head;
      head=p;
      printf("\nElement Found\n");
      return true;
    }
    q=p;
    p=p->next;
  }
  printf("\nElement not Found\n");
  return false;
}

void LinkedList::Insert(int element,int position){
  Node *temp;
  temp=new Node;
  temp->data=element;
  temp->next=nullptr;
  if(!head){
    head=temp;
    return;
  }
  if(position==-1){
    tail->next=temp;
    tail=temp;
    return;
  }
  else if(position==0){
    temp->next=head;
    head=temp;
    return;
  }
  else{
    int length=Length();
    if(position>length+1){
      printf("position can't be greater than list length");
      return;
    }
    Node *p=head;
    for(int i=1;i<=length;i++){
      if(position==i+1){
        temp->next=p->next;
        p->next=temp;
        return;
      }
      p=p->next;
    }
  }
}