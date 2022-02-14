# Matrix Determinant

[see in codewars](https://www.codewars.com/kata/52a382ee44408cea2500074c/train/javascript)

## Instructions

Write a function that accepts a square matrix `(N x N 2D array)` and returns the determinant of the matrix.

How to take the determinant of a matrix -- it is simplest to start with the smallest cases:

`A 1x1` matrix `|a|` has determinant a.

A 2x2 matrix `[ [a, b], [c, d] ]` or

```bash
|a  b|
|c  d|
```

has determinant: `a*d - b*c`.

The determinant of an `n x n` sized matrix is calculated by reducing the problem to the calculation of the determinants of n matrices of `n-1 x n-1 size`.

For the 3x3 case, `[ [a, b, c], [d, e, f], [g, h, i] ]` or

```bash
|a b c|  
|d e f|  
|g h i| 
```

the determinant is : ` a * det(a_minor) - b * det(b_minor) + c * det(c_minor) ` where `det(a_minor)` refers to taking the determinant of the `2x2 matrix` created by crossing out the row and column in which the element a occurs:

```bash
|- - -|
|- e f|
|- h i| 
```

**Note the alternation of signs.**

The determinant of larger matrices are calculated analogously, e.g. if `M` is a `4x4 matrix` with first row `[a, b, c, d]`, then:

`det(M) = a * det(a_minor) - b * det(b_minor) + c * det(c_minor) - d * det(d_minor)`


# My solution

## mathematical solution : Laplace expansion

  Laplace expansion expresses the determinant of a matrix `A` in terms of determinants of smaller matrices, known as its minors.

  The minor `Mj` is defined to be the determinant of the `(n-1)*(n-1)`-matrix that results from `A` by removing the `1st row` and the `j-th column`. The expression <img src="https://render.githubusercontent.com/render/math?math=(-1)^{j}M_{j}"> is known as a cofactor.
  
  <img src="https://render.githubusercontent.com/render/math?math=\det(A)=\sum _{j=0}^{n-1}(-1)^{j}a_{j}M_{j}">

  *`a_{j}` is the value of the `j` index in the 1st row*

## Javascript solution

Define `Matrix` class with :

- **Attributes :**
  - `matrix` : 2D array of values.

  - `size` : the size of the matrix.

  - `minors` : Array of minors matrices of the 1st row.

- **Methodes :**

  - `minor()` : to calculate the minors matrices of the 1st row.
  - `det()` : to calculate the determinant recursively with Laplace expansion formula
