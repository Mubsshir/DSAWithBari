#include "linked.hpp"
using namespace std;

void Hell(LinkedList *hello){
    hello->Display();
}
int main()
{
    Node *p,*q,*r,*s;
    p=new Node;
    q=new Node;
    r=new Node;
    s=new Node;
    p->data=3;
    p->next=q;
    q->data=4;
    q->next=r;
    r->data=5;
    r->next=s;
    s->data=22;
    s->next=NULL;
    bool loop=IsLoop(p);
    cout<<loop;
    return 0;
}