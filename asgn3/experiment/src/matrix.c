#include "matrix.h"

int **initialize(int n)
{
	int **a;

	a = calloc(n, sizeof(int *));

	srand(time(NULL));

	for (int i = 0; i < n; i++)
	{
		a[i] = calloc(n, sizeof(int));
		for (int j = 0; j < n; j++)
		{
			a[i][j] = rand() % 1000;
		}
	}

	return a;
}

int **init0(int n)
{
	int **a;
	
	a = calloc(n, sizeof(int *));

	for (int i = 0; i < n; i++)
	{
		a[i] = calloc(n, sizeof(int));
		
		for (int j = 0; j < n; j++)
		{
			a[i][j] = 0;
		}
	}

	return a;
}

void freemat(int **mat, int n)
{
	for (int i = 0; i < n; i++)
	{
		free(mat[i]);
	}
	free(mat);
}

