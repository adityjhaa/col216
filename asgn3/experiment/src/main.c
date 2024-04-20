#include <stdio.h>
#include "matrix.h"

int main()
{
	int a;
	printf("Enter a number (0/1)\n");
	printf("0 : Matrix Multiplication\n");
	printf("1 : Transpose Matrix\n?- ");

	if (scanf("%d", &a) != 1)
	{
		printf("Error reading input.\n");
		return 1;
	}

	switch (a)
	{
	case 0:
		// Matrix Multiplication

		break;
	case 1:
		// Transpose Matrix

		break;
	default:
		printf("Number not 0/1\n");
	}

	int **mat = initialize(5);

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}

	freemat(mat, 5);

	return 0;
}
