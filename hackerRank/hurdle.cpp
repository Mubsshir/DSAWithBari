#include <iostream>
#include <vector>
int main()
{
  std::vector<int> nums = {2,3,1,1,4};
  int count = 0,currentPosition=0,farthest=0;
  for(int i=0;i<nums.size();i++){
    farthest=std::max(farthest,i+nums[i]);
    if(i==currentPosition){
      count++;
      currentPosition=farthest;
    }
    if(currentPosition>=nums.size()-1){
      break;
    }
  }
  std::cout << count;
}