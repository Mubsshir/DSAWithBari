#include "test.hpp"
using namespace std;
int main()
{

  std::vector<int> nums;
  int size = nums.size();
  for (int i = 0; i < size; i++)
  {
    if (nums[i] <= 0 || nums[i] > size)
    {
      nums[i] = size + 1;
    }
  }
  for(int i=0;i<size;i++){
    int index=abs(nums[i]);
    if(index<=size){
      nums[index -1]=-abs(nums[index -1]);
    }
  }
  for(int i=0 ;i<size;i++){
    if(nums[i]>0){
      return i+1;
    }
  }
  return size+1;
}