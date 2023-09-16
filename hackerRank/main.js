
let a = [2, 3, 1, 0, 4];
const countJumps = (nums) => {
  let i = jumpsTo = count = 0;

  let numsLength = nums.length;

  while (i < numsLength) {
    if(nums[i]<nums[i+1]){
      count++;
      continue;
    }
    else{
      jumpsTo += nums[i];
    }
    if (jumpsTo >= numsLength - 1) {
      count++;
      break;
    }
    if (nums[jumpsTo] === 0) {
      count = -1;
      break;
    }
    if (jumpsTo < numsLength) {
      count++;
      i = jumpsTo;
      continue;
    }
    break;
  }
  return count;
};

let a = [2, 3, 1, 1, 4];

console.log(countJumps(a));
