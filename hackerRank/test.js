const countJumps = (nums) => {
  let jumps = 0;
  let currentEnd = 0;
  let farthest = 0;

  for (let i = 0; i < nums.length - 1; i++) {
    farthest = Math.max(farthest, i + nums[i]);
    if (i === currentEnd) {
      jumps++;
      currentEnd = farthest;
    }
    if (currentEnd >= nums.length - 1) {
      break;
    }
  }
  return currentEnd >= nums.length - 1 ? jumps : -1;
};

let a = [3,2,1,0,4];
console.log(countJumps(a));