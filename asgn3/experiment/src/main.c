#include "matrix.h"
#include "matmul.h"

int main()
{
	int n;
	int e = scanf("%d", &n);

	if (e != 1)
	{
		printf("Error reading input.\n");
		return 1;
	}

	srand(time(NULL));

	int **mat1 = initialize(n);
	int **mat2 = initialize(n);
	int **mat = init0(n);

	printmat(mat1, n);
	printf("\n");
	printmat(mat2, n);
	printf("\n");

	matmul(mat1, mat2, mat, n);

	printmat(mat, n);

	freemat(mat1, n);
	freemat(mat2, n);
	freemat(mat, n);

	return 0;
}
