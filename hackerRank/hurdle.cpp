#include <iostream>
#include <vector>
int main()
{
  std::vector<int> nums = {2,3,1,1,4};
  int count = 0, i = 0, jumpsTo = 0;
  int hurdlesCount = nums.size();
   while (i < hurdlesCount)
  {
    jumpsTo +=nums[i];

    if (jumpsTo >=hurdlesCount-1)
    {
      count++;
      break;
    }
    if (nums[jumpsTo] == 0)
    {
      count = -1;
      break;
    }

    i = jumpsTo;
    count++;
  }
  std::cout << count;
}