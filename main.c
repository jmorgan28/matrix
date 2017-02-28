#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  screen s;
  struct matrix *edges;
  struct matrix *edges2;
  struct matrix *edges3;

  color c;
 
  
  c.red = 0;
  c.green = MAX_COLOR;
  c.blue = 0;


  edges = new_matrix(4, 4);
  edges2 = new_matrix(4, 4);
  edges3 = new_matrix(4, 4);


  printf("creating a matrix. Here is matrix one empty\n");

  print_matrix(edges);
  clear_screen(s);
  add_edge(edges,80,4,0,100,4,0);
  add_edge(edges,105,499,0,283,99,0);
  add_edge(edges2,293,293,0,77,77,0);
  add_edge(edges2,29,23,0,77,77,0);
  add_edge(edges2,3,34,0,77,77,0);
  printf("Here is matrix one filled\n");
  print_matrix(edges);
  printf("Here is matriz 2 filled\n");
  print_matrix(edges2);
  matrix_mult(edges,edges2);
  printf("Matrix 2 after multiplication\n");
  print_matrix(edges2);
  printf("Matrix 2 scalar multiplied by 5\n");
  scalar_mult(5, edges2);
  print_matrix(edges2);
  printf("Matrix 1 made into identity matrix\n");
  ident(edges);
  print_matrix(edges);
  printf("Multiplying matrix 2 by identity matrix\n");
  matrix_mult(edges,edges2);
  print_matrix(edges2);


  add_edge(edges3,150,80,0,250,80,0);
  add_edge(edges3,150,80,0,150,280,0);
  add_edge(edges3,250,80,0,250,280,0);
  add_edge(edges3,150,280,0,250,280,0);
  add_edge(edges3,150,280,0,200,330,0);
  add_edge(edges3,250,280,0,200,330,0);
  add_edge(edges3,250,80,0,300,120,0);
  add_edge(edges3,250,280,0,300,320,0);
  add_edge(edges3,300,320,0,300,120,0);
  add_edge(edges3,200,330,0,250,370,0);
  add_edge(edges3,300,320,0,250,370,0);

  draw_lines(edges3,s,c);
  
  display(s);
  save_extension(s, "matrix.png");

  free_matrix( edges);
  free_matrix( edges2);
  free_matrix( edges3);
} 
