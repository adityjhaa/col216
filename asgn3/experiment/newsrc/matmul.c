#include "matmul.h"

void matmul(int *a, int *b, int *c, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
                c[i + j * n] += a[i + n * k] * b[k + n * j];
			}
		}
	}
}

// different ordered loops

// 1 : ijk

void matmul1(int *a, int *b, int *c, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
                c[i + j * n] += a[i + n * k] * b[k + n * j];
			}
		}
	}
}

// 2 : ikj

void matmul2(int *a, int *b, int *c, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < n; k++)
		{
			for (int j = 0; j < n; j++)
			{
                c[i + j * n] += a[i + n * k] * b[k + n * j];
			}
		}
	}
}

// 3 : jik

void matmul3(int *a, int *b, int *c, int n)
{
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int k = 0; k < n; k++)
			{
                c[i + j * n] += a[i + n * k] * b[k + n * j];
			}
		}
	}
}

// 4 : jki

void matmul4(int *a, int *b, int *c, int n)
{
	for (int j = 0; j < n; j++)
	{
		for (int k = 0; k < n; k++)
		{
			for (int i = 0; i < n; i++)
			{
                c[i + j * n] += a[i + n * k] * b[k + n * j];
			}
		}
	}
}

// 5 : kij

void matmul5(int *a, int *b, int *c, int n)
{
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
                c[i + j * n] += a[i + n * k] * b[k + n * j];
			}
		}
	}
}

// 6 : kji

void matmul6(int *a, int *b, int *c, int n)
{
	for (int k = 0; k < n; k++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int i = 0; i < n; i++)
			{
                c[i + j * n] += a[i + n * k] * b[k + n * j];
			}
		}
	}
}
