function decompose(nbr) {
  
  if (nbr === [1]) return 1;
  let a = nbr ,res = [];
  for (let i = 2; i <= nbr; i++) {
    
    if (a % i === 0) {
      res.push(i);
      while (a % i === 0) {
        a /= i;
      }
    } 
    
  }
  return res;
}


function sumOfDivided(lst) {

  let res = [];
  lst.forEach(nbr => {
    decompose(Math.abs(nbr))
      .forEach(factor => {
        let find = res.findIndex(element => element[0] === factor);
      
        if (find === -1) {
          res.push([factor,nbr]);
        } else {
          res[find][1] += nbr;
        }
    });
  });

  return res.sort((first, second) =>  first[0] - second[0] );
}