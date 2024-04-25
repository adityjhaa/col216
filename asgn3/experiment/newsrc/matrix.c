#include "matrix.h"

int *initialize(int n)
{
	int *a;

	a = calloc(n * n, sizeof(int));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i + j * n] = rand() % 100;
		}
	}

	return a;
}

int *init0(int n)
{
	int *a;

	a = calloc(n * n, sizeof(int));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i + j * n] = 0;
		}
	}

	return a;
}

void printmat(int *mat, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", mat[i + j * n]);
		}
		printf("\n");
	}
}

void freemat(int *mat, int n)
{
	free(mat);
}
