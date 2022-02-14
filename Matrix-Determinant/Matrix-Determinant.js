

class Matrix {
  constructor(size, matrix){
    this.size = size;
    this.matrix = matrix;
    this.minors = new Array(this.size);
  }

  minor(){
    for (let index = 0; index < this.size; index++) {
      let minor = new Array(this.size - 1);
      for (let i = 1; i < this.size; i++) {
        minor[i-1] = [];
        for (let j = 0; j < this.size; j++) {
          if (j != index) {
            minor[i-1].push(this.matrix[i][j]);
          }
        } 
      }
      this.minors[index] = new Matrix(this.size - 1 , minor);
    }
  }
  det(){
    if (this.size === 1 ) {
      return this.matrix[0][0];
    }
    this.minor();
    let determinant = 0;
    let sign = -1;

    for (let index = 0; index < this.size; index++) {
      sign *= -1;
      determinant += sign*this.matrix[0][index]*this.minors[index].det();
    }
    return determinant;
  }
}

function determinant(m) {
  // return the determinant of the matrix passed in
  let matrix = new Matrix(m.length, m);
  return matrix.det();
};

