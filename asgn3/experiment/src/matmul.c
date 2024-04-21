#include "matmul.h"

void matmul(int **a, int **b, int **c, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
}

// different ordered loops

// 1

void matmul1(int **a, int **b, int **c, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
}

// 2

void matmul2(int **a, int **b, int **c, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < n; k++)
		{
			for (int j = 0; j < n; j++)
			{
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
}

// 3

void matmul3(int **a, int **b, int **c, int n)
{
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int k = 0; k < n; k++)
			{
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
}

// 4

void matmul4(int **a, int **b, int **c, int n)
{
	for (int j = 0; j < n; j++)
	{
		for (int k = 0; k < n; k++)
		{
			for (int i = 0; i < n; i++)
			{
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
}

// 5

void matmul5(int **a, int **b, int **c, int n)
{
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
}

// 6

void matmul6(int **a, int **b, int **c, int n)
{
	for (int k = 0; k < n; k++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int i = 0; i < n; i++)
			{
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
}

