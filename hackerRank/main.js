const countJumps = (track) => {
  let i = (jumpsTo = count = 0);
  let trackLength = track.length;
  while (i < trackLength) {
    jumpsTo += track[i];
    if (jumpsTo >= trackLength - 1) {
      count++;
      break;
    }
    if (track[jumpsTo] === 0) {
      count = -1;
      break;
    }
    if (jumpsTo < trackLength) {
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
