#include "transpose.h"

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

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
