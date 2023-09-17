#include <iostream>
#include <vector>
using namespace std;

int PowerLeftToRight(int base, int exponent) {
  vector<int> expBits = {};
  int result = base;
  while (exponent != 0) {
    if (exponent % 2 != 0) {
      expBits.push_back(1);
    } else {
      expBits.push_back(0);
    }
    exponent = exponent / 2;
  }
  for (int i = expBits.size() - 2; i >= 0; i--) {

    result = result * result;
    if (expBits[i] == 1) {
      result *= base;
    }
  }
  return result;
}

int PowerRightToLeft(int base, int exponent) {
  vector<int> expBits = {};
  int x = base;
  int result;
  while (exponent != 0) {
    if (exponent % 2 != 0) {
      expBits.push_back(1);
    } else {
      expBits.push_back(0);
    }
    exponent = exponent / 2;
  }
  if (expBits[0] == 1) {
    result = x;
  } else {
    result = 0;
  }
  for(int i=1; i<expBits.size()-1;i++){
    x*=x;
    if(expBits[i]==1){
      result*=x;
    }
  }
  return result;
}