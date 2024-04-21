#include "matrix.h"
#include "matmul.h"

int main()
{
	int sizes[] = {500, 1000, 2000, 5000};

	void (*orderings[])(int **, int **, int **, int) = {&matmul1, &matmul2, &matmul3, &matmul4, &matmul5, &matmul6};
	char *names[] = {"ijk", "ikj", "jik", "jki", "kij", "kji"};

	int a = sizeof(sizes) / sizeof(int);
	int n;
	clock_t start, end;
	double time_t;

	srand(time(NULL));

	for (int i = 0; i < a; i++)
	{
		n = sizes[i];
		int **mat1 = initialize(n);
		int **mat2 = initialize(n);
		int **mat = init0(n);

		printf("Size : %d\n", n);

		for (int j = 0; j < 6; j++)
		{
			start = clock();

			(*orderings[j])(mat1, mat2, mat, n);

			end = clock();

			time_t = ((double)(end - start)) / CLOCKS_PER_SEC;

			printf("\Order : %s, Time : %f\n", names[j], time_t);
		}

		printf("\n");

		freemat(mat1, n);
		freemat(mat2, n);
		freemat(mat, n);
	}

	return 0;
}
