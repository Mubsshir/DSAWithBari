#include <iostream>

class Node
{
public:
  int col;
  int val;
  Node *next;
};

class SparseMatrix
{
private:
  int m, n;
  Node **A;

public:
  SparseMatrix(int m, int n)
  {
    this->n = n; // number of columns
    this->m = m; // number of rows
    A = new Node *[m];
    for (int i = 0; i < m; i++)
    {
      A[i] = nullptr;
    }
  }

  void SetElement(int i, int j, int x)
  {
    if (i >= 0 && i < m && j >= 0 && j < n)
    {
      Node *newNode = new Node();
      newNode->col = j;
      newNode->val = x;
      if (A[i] == nullptr)
      {
        A[i] = newNode;
        return;
      }
      Node *p, *q;
      p = A[i];
      q = nullptr;
      while (p && p->col < j)
      {
        q = p;
        p = p->next;
      }
      if (p && p->col == j)
      {
        p->val = x;
        delete newNode;
        return;
      }
      newNode->next = q->next;
      q = newNode;
    }
  }
  void Display()
  {
    for (int i = 0; i < m; i++)
    {
      Node *current = A[i];
      for (int j = 0; j < n; j++)
      {
        if (current != nullptr && current->col == j)
        {
          std::cout << current->val << " ";
          current = current->next;
        }
        else
        {
          std::cout << "0 ";
        }
      }
      std::cout << std::endl;
    }
  }

  ~SparseMatrix()
  {
    for (int i = 0; i < m; i++)
    {
      Node *current = A[i];
      while (current != nullptr)
      {
        Node *temp = current;
        current = current->next;
        delete temp;
      }
    }
    delete[] A;
  }
};
