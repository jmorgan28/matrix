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

  color c;
 
  
  c.red = 0;
  c.green = MAX_COLOR;
  c.blue = 0;


  edges = new_matrix(4, 4);
  edges2 = new_matrix(4, 4);


  printf("creating a matrix. Here is matrix one empty\n");

  print_matrix(edges);

 
  

  
  //add_point(edges, 2, 4, 0);
  //add_point(edges, 99, 6, 0);
  // add_point(edges, 105, 507, 0);
  //add_point(edges, 283, 29, 0);
  //add_point(edges, 293, 293, 0);
  //add_point(edges, 77, 77, 0);


  clear_screen(s);
  add_edge(edges,80,4,0,100,4,0);
  add_edge(edges,105,499,0,283,99,0);
  add_edge(edges2,293,293,0,77,77,0);
  add_edge(edges2,29,23,0,77,77,0);
  add_edge(edges2,3,34,0,77,77,0);
  //draw_lines(edges, s,c);


  printf("Here is matrix one filled\n");
  print_matrix(edges);
  printf("Here is matriz 2 filled\n");
  print_matrix(edges2);
  //printf("check\n");


  // ident(edges);
  matrix_mult(edges,edges2);


  
  //edges2 = new_matrix(4, 6);

  // ident(edges);

  //scalar_mult(5, edges2);

  //matrix_mult(edges, edges2);

  //grow_matrix(edges, 5);

  printf("Matrix 2 after multiplication\n");
  
  print_matrix(edges2);

  printf("Matrix 2 scalar multiplied by 5\n");
  scalar_mult(5, edges2);
  print_matrix(edges2);

  printf("Matrix 1 made into identity matrix\n");
  ident(edges);
  print_matrix(edges);

  
  //display(s);
  //save_extension(s, "matrix.png");

  free_matrix( edges );
} 
