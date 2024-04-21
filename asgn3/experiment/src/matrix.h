#ifndef MATRIX_H
#define MATRIX_H

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int **initialize(int n);

int **init0(int n);

void printmat(int **mat, int n);

void freemat(int **mat, int n);

#endif
