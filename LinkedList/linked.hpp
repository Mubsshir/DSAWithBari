#include <iostream>
#include <vector>

using namespace std;
class Node
{
public:
  Node *prev;
  int data;
  Node *next;
};
class LinkedList
{
private:
  Node *head, *tail;
  bool isLinear = true;

public:
  LinkedList(bool isLinear = true)
  {
    head = NULL;
    tail = NULL;
    if (!isLinear)
    {
      this->isLinear = false;
    }
  }

  LinkedList(int a[], int n, bool isLinear = true)
  {
    Node *temp;
    head = new Node;
    head->data = a[0];
    head->next = tail;
    tail = head;
    for (int i = 1; i < n; i++)
    {
      temp = new Node;
      temp->data = a[i];
      temp->next = nullptr;
      tail->next = temp;
      tail = temp;
    }
    if (!isLinear)
    {
      tail->next = head;
      this->isLinear = false;
    }
  }
  Node *getHead()
  {
    return head;
  }
  Node *getTail()
  {
    return tail;
  }
  ~LinkedList()
  {
    Node *temp = head;
    while (head)
    {
      head = head->next;
      delete temp;
      temp = head;
      if (temp == tail)
      {
        delete temp;
        break;
      }
    }
  }
  void Display();
  int Length();
  int FindMax();
  int FindMin();
  bool Search(int key);
  bool OSearch(int key);
  void Insert(int element, int positon = -1);
  void InsertSort(int element);
  void Delete(int pos);
  bool IsSorted();
  void RemoveDuplicates();
  void ReverseListElement();
  void ReverseListLink();
  void Reverse(Node *p, Node *q);
  void AddList(LinkedList *list);
  Node *Merge(LinkedList *list);
  bool IsLoop();
};

class DoublyLinkedList
{
private:
  Node *head, *tail;
  bool isLinear = true;

public:
  DoublyLinkedList(bool isLinear = true)
  {
    head = NULL;
    tail = NULL;
    this->isLinear = isLinear;
  }
  DoublyLinkedList(int a[], int n, bool isLinear = true)
  {
    if (n <= 0)
    {
      return;
    }
    head = new Node;
    head->data = a[0];
    head->prev = nullptr;
    head->next = nullptr;
    tail = head;

    for (int i = 1; i < n; i++)
    {
      Node *temp = new Node;
      temp->data = a[i];
      temp->prev = tail;
      temp->next = nullptr;
      tail->next = temp;
      tail = temp;
    }
    if (!isLinear)
    {
      this->isLinear = isLinear;
      head->prev = tail;
      tail->next = head;
    }
  }
  ~DoublyLinkedList()
  {
    Node *p = head;
    while (p)
    {
      head = head->next;
      delete p;
      p = head;
      if (p == tail)
      {
        delete p;
        break;
      }
    }
  }
  void Display();
  void Insert(int element, int pos = -1);
  int Length();
  int *popBack();
  int *popFront();
  int *pop(int pos = -1);
  void Reverse();
  int FindMiddle();
};

/// This method print the whole linked list
///
///\param Starting_Node  "start node from where you want to start printing"
/// \return void

void Printl(Node *headNode)
{
  Node *p = headNode;
  while (p)
  {
    printf("%d ", p->data);
    p = p->next;
  }
  std::cout << endl;
}

/// This method Print the Linked List to screen
///
///
/// \return void
void LinkedList::Display()
{
  Node *p = head;
  while (p)
  {
    printf("%d ", p->data);
    p = p->next;
    if (!isLinear && p == head)
    {
      break;
    }
  }
  printf("\n");
}

/// This method return the size of  the Linked List
///
///
/// \return integer
int LinkedList::Length()
{
  int count = 0;
  Node *p = head;
  while (p)
  {
    count++;
    p = p->next;
    if (p == head && !isLinear)
    {
      break;
    }
  }
  return count;
}
/// This method return the maximum int present in list
///
///
/// \return integer
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
    if (p == head && !isLinear)
    {
      break;
    }
  }
  return max;
}
/// This method return the minimum int present in list
///
///
/// \return integer
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
    if (p == head && !isLinear)
    {
      break;
    }
  }
  return min;
}

/// This method return the maximum int present in list
///
///\param key "element you want to search"
/// \return integer
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
    if (p == head && !isLinear)
    {
      break;
    }
  }
  printf("\nElement not Found");
  return false;
}
/// This method search for passed element and if the integer is find then it make the found element as head element
/// so next time if we search the same element it will be fetched fast
///\param key "element you want to search"
/// \return integer
bool LinkedList::OSearch(int key)
{
  Node *p, *q;
  q = NULL;
  p = head;
  while (p)
  {
    if (p->data == key)
    {
      if (!q)
      {
        printf("\nElement Found\n");
        return true;
      }
      q->next = p->next;
      p->next = head;
      head = p;
      printf("\nElement Found\n");
      return true;
    }
    q = p;
    p = p->next;
    if (p == head && !isLinear)
    {
      break;
    }
  }
  printf("\nElement not Found\n");
  return false;
}

void LinkedList::Insert(int element, int position)
{
  Node *temp;
  temp = new Node;
  temp->data = element;
  temp->next = nullptr;
  if (!head)
  {
    head = temp;
    if (!isLinear)
    {
      head->next = head;
    }
    tail = head;
    return;
  }
  if (position == -1)
  {
    tail->next = temp;
    tail = temp;
    if (!isLinear)
    {
      tail->next = head;
    }
    return;
  }
  else if (position == 0)
  {
    if (!isLinear)
    {
      tail->next = temp;
    }
    temp->next = head;
    head = temp;
    return;
  }
  else
  {
    int length = Length();
    if (position > length + 1 || position < -1)
    {
      printf("position can't be greater than list length or in minus");
      return;
    }
    Node *p = head;
    for (int i = 1; i <= length; i++)
    {
      if (position == i + 1)
      {
        temp->next = p->next;
        p->next = temp;
        return;
      }
      p = p->next;
      if (p == head && !isLinear)
      {
        break;
      }
    }
  }
}

void LinkedList::InsertSort(int element)
{
  Node *temp, *p, *q = nullptr;
  temp = new Node;
  temp->data = element;
  temp->next = nullptr;
  if (!head)
  {
    head = temp;
    head->next = tail;
    tail = head;
    return;
  }
  p = head;
  while (p)
  {
    if (p->data > element)
    {
      if (!q)
      {
        temp->next = head;
        head = temp;
        return;
      }
      temp->next = q->next;
      q->next = temp;
      return;
    }
    q = p;
    p = p->next;
    if (p == head && !isLinear)
    {
      break;
    }
  }
  printf("\n%d %d\n", q->data, element);
  tail->next = temp;
  tail = temp;
}

void LinkedList::Delete(int pos = 1)
{
  Node *p;
  p = head;
  if (pos == 1)
  {
    head = head->next;
    if (!isLinear)
    {
      tail->next = head;
    }
    delete p;
    return;
  }
  Node *q = nullptr;
  int len = Length();
  if (pos > len)
  {
    printf("Position is greater than list length");
    return;
  }
  for (int i = 0; i < pos; i++)
  {
    if (i + 1 == len)
    {
      q->next = !isLinear ? head : NULL;
      tail = q;
      delete p;
      return;
    }
    if (i == pos - 1)
    {
      q->next = p->next;
      delete p;
      return;
    }
    q = p;
    p = p->next;
    if (p == head && !isLinear)
    {
      break;
    }
  }
}

bool LinkedList::IsSorted()
{
  int x = INT_MIN;
  // walker
  Node *p;
  p = head;
  while (p)
  {
    if (p->data < x)
    {
      return false;
    }
    x = p->data;
    p = p->next;
    if (p == head && !isLinear)
    {
      break;
    }
  }
  return true;
}

void LinkedList::RemoveDuplicates()
{
  Node *p, *q;
  p = head;
  q = p->next;
  while (q)
  {
    if (p->data == q->data)
    {
      p->next = q->next;
      delete q;
      q = new Node;
      q = p->next;
      continue;
    }
    p = q;
    q = q->next;
    if (q == head && !isLinear)
    {
      break;
    }
  }
  tail = p;
}

void LinkedList::ReverseListElement()
{
  Node *p;
  std::vector<int> auxArray;
  p = head;
  for (int i = 0; p; i++)
  {
    auxArray.push_back(p->data);
    p = p->next;
    if (p == head && !isLinear)
    {
      break;
    }
  }
  p = head;
  for (int i = auxArray.size() - 1; p; i--)
  {
    p->data = auxArray[i];
    p = p->next;
    if (p == head && !isLinear)
    {
      break;
    }
  }
}

void LinkedList::ReverseListLink()
{
  Node *p, *q, *r;
  p = head;
  q, r = nullptr;
  while (p)
  {
    r = q;
    q = p;
    p = p->next;
    if (p == head && !isLinear)
    {
      break;
    }
    q->next = r;
  }
  tail = head;
  head = q;
  printf("\n %d \n", head->data);
}
void LinkedList::Reverse(Node *p, Node *q = nullptr)
{
  if (p)
  {
    if (p == head && !isLinear)
    {
      return;
    }
    Reverse(p->next, p);
    p->next = q;
    if (p->next == nullptr)
    {
      tail = p;
    }
  }
  else
  {
    head = q;
  }
}
/// Attach list to your list
///
///\param list "Linked List you want to add in exitsting list"
/// \return void
void LinkedList::AddList(LinkedList *list)
{
  tail->next = list->getHead();
  tail = list->getTail();
  list->head = NULL;
  if (!isLinear)
  {
    tail->next = head;
  }
}

Node *LinkedList::Merge(LinkedList *list)
{
  Node *first, *second, *third, *last;
  first = head;
  second = list->getHead();
  if (first->data < second->data)
  {
    last = third = first;
    first = first->next;
    third->next = NULL;
  }
  else
  {
    third = last = second;
    second = second->next;
    third->next = NULL;
  }
  while (first && last)
  {
    if (first->data < second->data)
    {
      last->next = first;
      last = first;
      first = first->next;
      last->next = NULL;
    }
    else if (first->data > second->data)
    {
      last->next = second;
      last = second;
      second = second->next;
      last->next = NULL;
    }
    else
    {
      first = first->next;
      second = second->next;
    }
  }
  if (first)
  {
    last->next = first;
  }
  if (second)
  {
    last->next = second;
  }
  return third;
}

bool IsLoop(Node *head)
{
  Node *p, *q;
  p = q = head;
  do
  {
    p = p->next;
    q = q->next;
    q = q != NULL ? q->next : NULL;
  } while (p && q && p != q);
  return p == q ? true : false;
}

void DoublyLinkedList::Display()
{
  Node *p = head;
  while (p)
  {
    printf(" %d ", p->data);
    p = p->next;
    if (p == head && !isLinear)
    {
      break;
    }
  }
  cout << endl;
  return;
}

int DoublyLinkedList::Length()
{
  int count = 0;
  Node *p = head;
  while (p)
  {
    count++;
    p = p->next;
    if (p == head && !isLinear)
    {
      break;
    }
  }
  return count;
}
void DoublyLinkedList::Insert(int element, int pos)
{
  if (!head)
  {
    head = new Node;
    head->prev = !isLinear ? tail : nullptr;
    head->next = !isLinear ? tail : nullptr;
    head->data = element;
    tail = head;
    return;
  }
  Node *temp = new Node;
  int size = Length();
  if (pos == 1)
  {
    temp->prev = !isLinear ? tail : nullptr;
    temp->data = element;
    temp->next = head;
    if (!isLinear)
    {
      tail->next = temp;
    }
    head = temp;
    return;
  }
  if (pos == -1 || pos == size + 1)
  {
    temp->next = !isLinear ? head : nullptr;
    temp->prev = tail;
    temp->data = element;
    tail->next = temp;
    tail = temp;
    return;
  }
  if (pos > size)
  {
    cout << "given position is  invalid" << endl;
    return;
  }
  Node *p, *q;
  p = head;
  q = nullptr;
  for (int i = 0; p; i++)
  {
    if (i == pos - 1)
    {
      temp->prev = q;
      temp->next = p;
      temp->data = element;
      p->prev = temp;
      q->next = temp;
      return;
    }
    q = p;
    p = p->next;
  }
}

int *DoublyLinkedList::popFront()
{
  if (!head)
  {
    return nullptr;
  }
  Node *temp;
  temp = head;
  head = head->next;
  head->prev = !isLinear ? tail : nullptr;
  tail->next = !isLinear ? head : nullptr;
  int *x = new int(temp->data);
  delete temp;
  return x;
}

int *DoublyLinkedList::popBack()
{
  if (!tail)
  {
    return nullptr;
  }
  Node *temp;
  temp = tail;
  tail = tail->prev;
  tail->next = !isLinear ? head : nullptr;
  ;
  int *x = new int(temp->data);
  delete temp;
  return x;
}

int *DoublyLinkedList::pop(int pos)
{
  int size = Length();
  if (pos == 1)
  {
    return popFront();
  }
  if (pos == -1 or pos == size)
  {
    return popBack();
  }
  if (size < pos)
  {
    cout << "No node present in this location." << endl;
    return nullptr;
  }
  Node *p, *q;
  p = head;
  q = nullptr;
  for (int i = 0; p; i++)
  {
    if (i == pos - 1)
    {
      q->next = p->next;
      p->next->prev = q;
      int *x = new int(p->data);
      delete p;
      return x;
    }
    q = p;
    p = p->next;
  }
  return nullptr;
}

void DoublyLinkedList::Reverse()
{
  Node *temp, *p;
  temp = p = head;
  head = tail;
  tail = temp;
  while (p)
  {
    temp = p->prev;
    p->prev = p->next;
    p->next = temp;
    p = p->prev;
    if (!isLinear && p == tail)
    {
      break;
    }
  }
}

int DoublyLinkedList::FindMiddle()
{
  Node *p, *q;
  p = q = head;
  while (p && p->next)
  {
    p = p->next->next;
    q = q->next;
    if(!isLinear && p==head)break;
  }
  return q->data;
}