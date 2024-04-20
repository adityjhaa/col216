#include <stdio.h>
#include "matrix.h"

int main()
{
	int n;
	int e = scanf("%d", &n);
	
	if(e != 1)
	{
		printf("Error reading input.\n");
		return 1;
	}

	int **mat = initialize(n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}

	freemat(mat, n);

	return 0;
}

