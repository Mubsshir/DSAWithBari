#include <iostream>
#include <math.h>
using namespace std;

struct Term
{
    int cofficient;
    int exponent;
    Term *next;
};

class LinkedPoly{
    private:
        Term* head;
        Term* tail;
    public:
    LinkedPoly(){
        head=NULL;
        tail=NULL;        
    };
    ~LinkedPoly(){
        Term *p;
        p=head;
        while(p){
            head=head->next;
            delete p;
            p=head;
        }
    }
    void InsertTerm(int coffi,int expo);
    void DisplayExpression();
    float SolveExpression(int valueOfx);

};
class Polynomial
{
private:
    int n;
    struct Term *term;
    int idx = 0;

public:
    Polynomial()
    {
        this->n = 1;
        this->term = new Term[n];
    }
    Polynomial(int n)
    {
        this->n = n;
        this->term = new Term[n];
    }
    ~Polynomial()
    {
        delete[] term;
    }
    void SetPoly(int c, int e);
    int EvaluatePoly(int x);
    void Display();
    static Polynomial AddPolynomial(Polynomial p, Polynomial q);
};

void Polynomial ::SetPoly(int c, int e)
{
    if (idx < this->n)
    {
        term[idx].cofficient = c;
        term[idx].exponent = e;
        idx++;
    }
}

int Polynomial ::EvaluatePoly(int x)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += (term[i].cofficient * pow(x, term[i].exponent));
    }
    return sum;
}

void Polynomial ::Display()
{
    string rep = "";
    for (int i = 0; i < n; i++)
    {
        if (i != n - 1)
        {
            printf("%dx^%d + ", term[i].cofficient, term[i].exponent);
        }
        else
        {
            printf("%d ", term[i].cofficient);
        }
    }
}

Polynomial Polynomial ::AddPolynomial(Polynomial p, Polynomial q)
{
    Polynomial r(0);
    int i = 0, j = 0;
    while (i < p.n && j < q.n)
    {
        if (p.term[i].exponent == q.term[j].exponent)
        {
            r.n++;
            r.SetPoly(p.term[i].cofficient + q.term[j].cofficient, p.term[i].exponent);
            i++;
            j++;
        }
        else if (p.term[i].exponent > q.term[j].exponent)
        {
            r.n++;
            r.SetPoly(p.term[i].cofficient, p.term[i].exponent);
            i++;
        }
        else
        {
            r.n++;
            r.SetPoly(q.term[j].cofficient, q.term[j].exponent);
            j++;
        }
    }
    return r;
}

void LinkedPoly::InsertTerm(int coffi,int expo){
    if(!head){
        head=new Term;
        head->cofficient=coffi;
        head->exponent=expo;
        head->next=nullptr;
        tail=head;
        return;
    }
    Term *p=head;
    while(p){
        if(p->exponent==expo){
            p->cofficient+=coffi;
            return;
        }
        p=p->next;
    }
    Term *newTerm=new Term;
    newTerm->cofficient=coffi;
    newTerm->exponent=expo;
    newTerm->next=nullptr;
    tail->next=newTerm;
    tail=newTerm;
}

void LinkedPoly::DisplayExpression(){
    Term *p=head;
    while(p){
        if(p->next==nullptr){
            cout<<p->cofficient;
            p->exponent!=0?cout<<"X^"<<p->exponent:cout<<"";
        }
        else{
            cout<<p->cofficient;
            p->exponent!=0?cout<<"X^"<<p->exponent<<"+":cout<<""<<"+";
        }
        p=p->next;
    }
}

float LinkedPoly::SolveExpression(int valueOfx){
    float result=0.0;
    Term *p=head;
    while(p){
        result+=p->cofficient*pow(valueOfx,p->exponent);
        p=p->next;
    }
    return result;
}