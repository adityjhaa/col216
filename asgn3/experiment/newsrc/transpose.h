#ifndef TRANSPOSE_H
#define TRANSPOSE_H

#include "matrix.h"


/* Standard functions */
// in-place

void transpose1(int *mat, int n);

// additional matrix

void transpose2(int *mat1, int *mat2, int n);

/* Orderings */

// in-place
void transpose1a(int *mat, int n);

void transpose1b(int *mat, int n);

// additional matrix

void transpose2a(int *mat1, int *mat2, int n);

void transpose2b(int *mat1, int *mat2, int n);


#endif
