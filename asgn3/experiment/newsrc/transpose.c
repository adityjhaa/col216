#include "transpose.h"

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/* Standard functions */

// in-place

void transpose1(int *mat, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(&mat[i + j * n], &mat[j + i * n]);
        }
    }
}

// using an additional matrix

void transpose2(int *mat1, int *mat2, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mat2[i + j * n] = mat1[j + i * n];
        }
    }
}

/* Orderings */

// in-place
void transpose1a(int *mat, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(&mat[i + j * n], &mat[j + i * n]);
        }
    }
}

void transpose1b(int *mat, int n)
{
    for (int j = 0; j < n; j++)
    {
        for (int i = j + 1; i < n; i++)
        {
            swap(&mat[i + j * n], &mat[j + i * n]);
        }
    }
}

// additional matrix

void transpose2a(int *mat1, int *mat2, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mat2[j + i * n] = mat1[i + j * n];
        }
    }
}

void transpose2b(int *mat1, int *mat2, int n)
{
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            mat2[j + i * n] = mat1[i + j * n];
        }
    }
}
