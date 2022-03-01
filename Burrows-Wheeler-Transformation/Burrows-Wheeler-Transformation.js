function encode(s) {
  if (!s) { return [s,1]}
  let matrix = new Array(s.length);
  let startIndex = 0 ;
  let size = s.length;
  for (let i = 0; i < size; i++) {
    matrix[i] = "";
    for (let j = 0; j < size; j++) {
      matrix[i] += s.charAt((startIndex + j + size) % size) ;
    }
    startIndex --;
  }
  console.log(matrix)
  return [ matrix.sort().map(row => row.slice(-1)).join(''), matrix.indexOf(s) ];
}

function decode(s,i) {
  if (!s) { return s}
  let res = s.split('');
  let sortS = s.split('').sort();
  for (let index = 0; index < s.length - 1; index++) {
    for (let j = 0; j < s.length; j++) {
      res[j] += sortS[j].charAt(index);
      sortS[j] = res[j];
    }
    sortS.sort();
  }
  return sortS[i];
}