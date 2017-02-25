#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "matrix.h"


/*-------------- void print_matrix() --------------
Inputs:  struct matrix *m 
Returns: 
print the matrix
*/
void print_matrix(struct matrix *m) {
  int i, f;
  for(i = 0; i < m->rows; i ++){
    for(f = 0; f < m->cols; f ++){
      printf("%lf ", m ->m[i][f]);
    }
    printf("\n");
  }
}

/*-------------- void ident() --------------
Inputs:  struct matrix *m <-- assumes m is a square matrix
Returns: 
turns m in to an identity matrix
*/
void ident(struct matrix *m) {
  int i, f;
  for(i = 0; i < m->rows; i ++){
    for(f = 0; f < m->cols; f ++){
      if(i == f){
	m -> m[i][f] = 1;
      }
      else{
	m -> m[i][f] = 0;
      }
    }
  }	
}


/*-------------- void scalar_mult() --------------
Inputs:  double x
         struct matrix *m 
Returns: 
multiply each element of m by x
*/
void scalar_mult(double x, struct matrix *m) {
  int i, f;
  for( i = 0; i < m->rows; i ++){
    for( f = 0; f < m->cols; f ++){
      m -> m[i][f] = x * m -> m[i][f];
    }
  }
}


/*-------------- void matrix_mult() --------------
Inputs:  struct matrix *a
         struct matrix *b 
Returns: 
a*b -> b
*/
void matrix_mult(struct matrix *a, struct matrix *b) {
  printf("work\n");
  struct matrix *temp = new_matrix(b->rows, b->cols);
  printf("working\n");
  int e,f,g;
  for(e = 0; e < a->rows; e++){
    for(f = 0; f < b-> cols; f ++){
      for(g = 0; g < a -> rows;g ++){
	temp -> m[e][f] = temp->m[e][f] + (a -> m[e][g] * b->m[g][e]);
      }
    }
  }
  copy_matrix(temp,b);
}
					 


/*===============================================
  These Functions do not need to be modified
  ===============================================*/

/*-------------- struct matrix *new_matrix() --------------
Inputs:  int rows
         int cols 
Returns: 
Once allocated, access the matrix as follows:
m->m[r][c]=something;
if (m->lastcol)... 
*/
struct matrix *new_matrix(int rows, int cols) {
  double **tmp;
  int i;
  struct matrix *m;

  tmp = (double **)malloc(rows * sizeof(double *));
  for (i=0;i<rows;i++) {
      tmp[i]=(double *)malloc(cols * sizeof(double));
    }

  m=(struct matrix *)malloc(sizeof(struct matrix));
  m->m=tmp;
  m->rows = rows;
  m->cols = cols;
  m->lastcol = 0;
  int h,s;
  for(h= 0; h < m->rows; h ++){
    for(s = 0; s < m->cols; s ++){
      m -> m[h][s] = 0;
    }
  }
  

  return m;
}


/*-------------- void free_matrix() --------------
Inputs:  struct matrix *m 
Returns: 
1. free individual rows
2. free array holding row pointers
3. free actual matrix
*/
void free_matrix(struct matrix *m) {

  int i;
  for (i=0;i<m->rows;i++) {
      free(m->m[i]);
    }
  free(m->m);
  free(m);
}


/*======== void grow_matrix() ==========
Inputs:  struct matrix *m
         int newcols 
Returns: 
Reallocates the memory for m->m such that it now has
newcols number of collumns
====================*/
void grow_matrix(struct matrix *m, int newcols) {
  
  int i;
  for (i=0;i<m->rows;i++) {
      m->m[i] = realloc(m->m[i],newcols*sizeof(double));
      m -> m[i][newcols - 1] = 0;
  }
  m->cols = newcols;
}


/*-------------- void copy_matrix() --------------
Inputs:  struct matrix *a
         struct matrix *b 
Returns: 
copy matrix a to matrix b
*/
void copy_matrix(struct matrix *a, struct matrix *b) {

  int r, c;

  for (r=0; r < a->rows; r++) 
    for (c=0; c < a->cols; c++)  
      b->m[r][c] = a->m[r][c];  
}
