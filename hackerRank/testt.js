function minJumps(nums) {
  const n = nums.length;
  
  if (n === 0 || nums[0] === 0) {
    // If the array is empty or the first element is 0, it's not possible to clear the hurdles
    return -1;
  }
  
  let jumps = 1; // Alice starts at the first hurdle
  let maxReach = nums[0]; // Maximum index that can be reached from the current position
  let steps = nums[0]; // Number of steps Alice can still take from the current position
  
  for (let i = 1; i < n; i++) {
    if (i === n - 1) {
      // If Alice reaches the last hurdle, return the number of jumps taken
      return jumps;
    }
    maxReach = Math.max(maxReach, i + nums[i]);
    steps--;
    if (steps === 0) {
      // If Alice has no more steps, she needs to take a jump
      jumps++;
      
      if (i > maxReach) {
        // If Alice cannot reach the next hurdle, it's not possible to clear all the hurdles
        return -1;
      }
      steps = maxReach - i;
    }
  }
  return -1; // If Alice doesn't reach the last hurdle, it's not possible to clear all the hurdles
}

let a = [2,3,1,1,4];
console.log(minJumps(a))