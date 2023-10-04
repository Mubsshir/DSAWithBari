#include <iostream>
using namespace std;

struct Item
{
  int price;
  int weight;
  float fraction=1.0f;
};
struct Box
{
  int slot;
  struct Item *i;
};
struct Knapsack
{
  int noOfItem=0;
  int capacity;
  struct Item *i;
};

void swap(struct Item *a, struct Item *b)
{
  struct Item temp = *a;
  *a = *b;
  *b = temp;
}
void BubbleSort(struct Item *itm, int size)
{
  for (int i = size - 1; i > 0; i--)
  {
    for (int j = 0; j < i; j++)  
    {
      if (itm[j].price * 1.0 / itm[j].weight < itm[j + 1].price * 1.0 / itm[j + 1].weight)
      {
        swap(&itm[j], &itm[j + 1]);
      }
    }
  }
}

int main()
{
  struct Knapsack knap;
  knap.capacity = 20;
  struct Box box;
  box.slot = 3;
  box.i = new Item[box.slot];
  knap.i=new Item[box.slot];
  int price[] = {25, 24, 15};
  int weigh[] = {18, 15, 10};
  for (int i = 0; i < box.slot; i++)
  {
    struct Item itm;
    itm.price = price[i];
    itm.weight = weigh[i];
    box.i[i] = itm;
  }
  BubbleSort(box.i, box.slot);
  cout << "\nItem in Box\n";
  for (int i = 0; i < box.slot; i++)
  {
    printf("| $%d | %d kg| <>", box.i[i].price, box.i[i].weight);
  }
  int totalWeight=0;
  int i=0;
  while(totalWeight<knap.capacity){
    if(totalWeight+box.i[i].weight<knap.capacity){
      knap.i[i]=box.i[i];
      knap.i[i].fraction=1.0f;
      totalWeight+=box.i[i].weight;
      knap.noOfItem++;
    }
    else{
      knap.i[i]=box.i[i];
      knap.i[i].fraction=(knap.capacity-totalWeight)*1.0/box.i[i].weight;
      totalWeight=knap.capacity;
      knap.noOfItem++;
    }
    i++;
  }
  float profit=0;
  cout<<"\n----------\nItems in Knapsack\n";
  for(int i=0;i<knap.noOfItem;i++){
    profit+=knap.i[i].fraction*(knap.i[i].price);
    cout<< "Fraction : "<<knap.i[i].fraction <<"| Price: "<<knap.i[i].price <<" | Weight: "<<knap.i[i].weight<<endl;
  }
  cout<<"total profit: "<<profit;
  return 0;
}