
// ------ rmv zeros from the start
function rmvZeros(p) {
  let arr = p.split('');
  let i = 0;
  while (arr[i] === '0' && i < arr.length - 1) {
    i++;
  }
  return arr.slice(i).join('');
}

// ------ add 2 big numbers
function add(a,b) {
  if (a === '') {
    return (b === '')? 0: b;
  }
  if (b=== '') {
    return  a; 
  }
  let res = [], ret = 0, arr =[[...a.split('')], [...b.split('')]];
  let max = (a.length > b.length) ? a.length : b.length ;

  for (let i = arr[0].length ; i < max + 1 ; i++) {
    arr[0] = ['0', ...arr[0]];
  }
  for (let i = arr[1].length ; i < max + 1 ; i++) {
    arr[1] = ['0', ...arr[1]];
  }
  
  for (let i = max; i > - 1; i--) {
    let v = parseInt(arr[0][i]) +  parseInt(arr[1][i]) + ret;
    res.push((v % 10) + "");
    ret = Math.trunc(v / 10);
  }
  
  return rmvZeros(res.reverse().join('')) ;
}

function multiply(a, b)
{
  let results = '' , zeros = [];
  a.split('').reverse().forEach( aNum => {
    let ret = 0, res = [...zeros];
    b.split('').reverse().forEach( bNum => {
      let v = parseInt(aNum) * parseInt(bNum) + ret ;
      res.push(v % 10);
      ret = Math.trunc(v / 10);
    });
    results = add(results, ret + res.reverse().join(''));
    zeros.push(0);
  });
  return rmvZeros(results + "" );
}





