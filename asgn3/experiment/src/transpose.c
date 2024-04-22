#include "transpose.h"

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/* Standard functions */

// in-place

void transpose1(int **mat, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(&mat[i][j], &mat[j][i]);
        }
    }
}

// using an additional matrix

void transpose2(int **mat1, int **mat2, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mat2[i][j] = mat1[j][i];
        }
    }
}

/* Orderings */

// in-place
void transpose1a(int **mat, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(&mat[i][j], &mat[j][i]);
        }
    }
}

void transpose1b(int **mat, int n)
{
    for (int j = 0; j < n; j++)
    {
        for (int i = j + 1; i < n; i++)
        {
            swap(&mat[i][j], &mat[j][i]);
        }
    }
}

// additional matrix

void transpose2a(int **mat1, int **mat2, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mat2[i][j] = mat1[j][i];
        }
    }
}

void transpose2b(int **mat1, int **mat2, int n)
{
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            mat2[i][j] = mat1[j][i];
        }
    }
}
