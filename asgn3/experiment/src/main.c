#include "matrix.h"
#include "matmul.h"

int main()
{
	int sizes[] = {500, 1000};

	void (*orderings[])(int **, int **, int **, int) = {&matmul1, &matmul2, &matmul3, &matmul4, &matmul5, &matmul6};
	char *names[] = {"ijk", "ikj", "jik", "jki", "kij", "kji"};

	int a = sizeof(sizes) / sizeof(int);
	int n;
	clock_t start, end;
	double time_t, avg_time;

	srand(time(NULL));

	for (int i = 0; i < a; i++)
	{
		n = sizes[i];
		int **mat1 = initialize(n);
		int **mat2 = initialize(n);

		printf("Size : %d\n", n);

		for (int j = 0; j < 6; j++)
		{
			avg_time = (double)0;

			for (int k = 0; k < 5; k++)
			{
				int **mat = init0(n);
				start = clock();
				(*orderings[j])(mat1, mat2, mat, n);

				end = clock();

				time_t = ((double)(end - start)) / CLOCKS_PER_SEC;

				avg_time += time_t;

				freemat(mat, n);
			}

			avg_time /= 5;

			printf("Order : %s, Time : %f\n", names[j], avg_time);
		}

		printf("\n");

		freemat(mat1, n);
		freemat(mat2, n);
	}

	return 0;
}
