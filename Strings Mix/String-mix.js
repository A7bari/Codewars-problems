function isLetter(c) {
  return c.toLowerCase() != c.toUpperCase();
}

function separe(s) {
  liste = [];
  s.split('').forEach(litter => {
    if (isLetter(litter)) {
      i = liste.findIndex(e => e[0] === litter);
      if (i === -1) {
        liste.push(litter);
      } else {
        liste[i] += litter; 
      } 
    }
  });
  return liste.filter(w => w.length > 1);
}

function mix(s1, s2) {
  s1Liste = separe(s1).sort((a,b) => a > b);
  s2Liste = separe(s2).sort((a,b) => a > b);

  
  equals = [];
  s1Liste.forEach((element , index) => {
    i = s2Liste.findIndex(e => element[0] === e[0]);
    if (i != -1) {
      if (element.length === s2Liste[i].length) {
        equals.push("=:" + element);
        s1Liste[index] = '';
        s2Liste.splice(i,1);
      }
      else if (element.length < s2Liste[i].length)
      {
        s1Liste[index] = '';
      }
      else 
      {
        s2Liste.splice(i,1);
      }
    }
  });
  let res = s1Liste.filter(e => e != '').map(e => e = "1:" + e).concat(s2Liste.map(e => e = "2:" + e), equals);
  res.sort((a,b) => b.length - a.length);
 

  return res.join('/');
}