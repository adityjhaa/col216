#include "matrix.h"
#include "matmul.h"
#include "transpose.h"

void part1()
{
	int sizes[] = {500, 750, 1000, 1250, 1500, 1750, 2000};

	void (*orderings[])(int *, int *, int *, int) = {&matmul1, &matmul2, &matmul3, &matmul4, &matmul5, &matmul6};
	char *names[] = {"ijk", "ikj", "jik", "jki", "kij", "kji"};

	int a = sizeof(sizes) / sizeof(int);
	int n;
	clock_t start, end;
	double time_t, avg_time;

	srand(time(NULL));

	for (int i = 0; i < a; i++)
	{
		n = sizes[i];

		printf("Size : %d\n", n);

		for (int j = 0; j < 6; j++)
		{
			avg_time = (double)0;

			for (int k = 0; k < tries; k++)
			{
				int *mat1 = initialize(n);
				int *mat2 = initialize(n);
				int *mat = init0(n);

				start = clock();

				(*orderings[j])(mat1, mat2, mat, n);

				end = clock();

				time_t = ((double)(end - start)) / CLOCKS_PER_SEC;

				avg_time += time_t;

				freemat(mat1, n);
				freemat(mat2, n);
				freemat(mat, n);
			}

			avg_time /= tries;

			printf("Order : %s, Time : %f\n", names[j], avg_time);
		}

		printf("\n");
	}
}


void part2b()
{
	int sizes[] = {500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000};

	void (*orderings1[])(int *, int) = {&transpose1a, &transpose1b};
	void (*orderings2[])(int *, int *, int) = {&transpose2a, &transpose2b};

	char *names[] = {"ij", "ji"};

	int a = sizeof(sizes) / sizeof(int);
	int n;
	clock_t start, end;
	double time_t, avg_time;

	srand(time(NULL));

	// in-place

	printf("In-place\n");

	for (int i = 0; i < a; i++)
	{
		n = sizes[i];

		printf("Size : %d\n", n);

		for (int j = 0; j < 2; j++)
		{
			avg_time = (double)0;

			for (int k = 0; k < 5; k++)
			{
				int *mat1 = initialize(n);

				start = clock();

				(*orderings1[j])(mat1, n);

				end = clock();

				time_t = ((double)(end - start)) / CLOCKS_PER_SEC;

				avg_time += time_t;

				freemat(mat1, n);
			}

			avg_time /= 5;

			printf("Order : %s, Time : %f\n", names[j], avg_time);
		}
	}

	printf("\n");

	// additional matrix

	printf("Additional Matrix\n");

	for (int i = 0; i < a; i++)
	{
		n = sizes[i];

		printf("Size : %d\n", n);

		for (int j = 0; j < 2; j++)
		{
			avg_time = (double)0;

			for (int k = 0; k < 5; k++)
			{
				int *mat1 = initialize(n);
				int *mat2 = init0(n);

				start = clock();

				(*orderings2[j])(mat1, mat2, n);

				end = clock();

				time_t = ((double)(end - start)) / CLOCKS_PER_SEC;

				avg_time += time_t;

				freemat(mat1, n);
				freemat(mat2, n);
			}

			avg_time /= 5;

			printf("Order : %s, Time : %f\n", names[j], avg_time);
		}
	}
}

int main()
{
	return 0;
}
