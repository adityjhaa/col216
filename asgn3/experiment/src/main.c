#include "matrix.h"
#include "matmul.h"
#include "transpose.h"

// Multiplication

void part1a()
{
	int sizes[] = {1, 5, 10, 20, 50, 75, 100, 200, 500, 1000, 2000};

	int a = sizeof(sizes) / sizeof(int);
	int n;
	clock_t start, end;
	double time_t, avg_time;

	srand(time(NULL));

	for (int i = 0; i < a; i++)
	{
		n = sizes[i];

		avg_time = (double)0;

		for (int j = 0; j < 5; j++)
		{
			int **mat1 = initialize(n);
			int **mat2 = initialize(n);
			int **mat = init0(n);

			start = clock();

			matmul(mat1, mat2, mat, n);

			end = clock();

			time_t = ((double)(end - start)) / CLOCKS_PER_SEC;

			avg_time += time_t;

			freemat(mat1, n);
			freemat(mat2, n);
			freemat(mat, n);
		}

		avg_time /= 5;

		printf("Size : %d, Time : %f\n", n, avg_time);
	}
}

void part1b()
{
	int sizes[] = {100, 200, 500, 1000, 2000};

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

		printf("Size : %d\n", n);

		for (int j = 0; j < 6; j++)
		{
			avg_time = (double)0;

			for (int k = 0; k < 5; k++)
			{
				int **mat1 = initialize(n);
				int **mat2 = initialize(n);
				int **mat = init0(n);

				start = clock();

				(*orderings[j])(mat1, mat2, mat, n);

				end = clock();

				time_t = ((double)(end - start)) / CLOCKS_PER_SEC;

				avg_time += time_t;

				freemat(mat1, n);
				freemat(mat2, n);
				freemat(mat, n);
			}

			avg_time /= 5;

			printf("Order : %s, Time : %f\n", names[j], avg_time);
		}

		printf("\n");
	}
}

// Transpose

void part2a()
{
	int sizes[] = {1, 5, 10, 20, 50, 75, 100, 200, 500, 1000, 2000, 5000};

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

		avg_time = (double)0;

		for (int j = 0; j < 5; j++)
		{
			int **mat1 = initialize(n);

			start = clock();

			transpose1(mat1, n);

			end = clock();

			time_t = ((double)(end - start)) / CLOCKS_PER_SEC;

			avg_time += time_t;

			freemat(mat1, n);
		}

		avg_time /= 5;

		printf("Size : %d, Time : %f\n", n, avg_time);
	}
	printf("\n");

	// additional matrix

	printf("Additional Matrix\n");

	for (int i = 0; i < a; i++)
	{
		n = sizes[i];

		avg_time = (double)0;

		for (int j = 0; j < 5; j++)
		{
			int **mat1 = initialize(n);
			int **mat2 = init0(n);

			start = clock();

			transpose2(mat1, mat2, n);

			end = clock();

			time_t = ((double)(end - start)) / CLOCKS_PER_SEC;

			avg_time += time_t;

			freemat(mat1, n);
			freemat(mat2, n);
		}

		avg_time /= 5;

		printf("Size : %d, Time : %f\n", n, avg_time);
	}
}

void part2b()
{
	int sizes[] = {100, 200, 500, 1000, 2000, 5000};

	void (*orderings1[])(int **, int) = {&transpose1a, &transpose1b};
	void (*orderings2[])(int **, int **, int) = {&transpose2a, &transpose2b};

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
				int **mat1 = initialize(n);

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
				int **mat1 = initialize(n);
				int **mat2 = init0(n);

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
	int x;
	printf("Enter 0/1\n");
	printf("0 : Matrix Multiplication\n1 : Matrix Transpose\n?- ");

	int e = scanf("%d", &x);

	if (e != 1)
	{
		printf("Error!\n");
		return 1;
	}

	switch (x)
	{
	case 0:

		printf("Enter 0/1\n");
		printf("0 : Size V/s Time\n1 : Loop Order V/s Time\n?- ");

		e = scanf("%d", &x);

		if (e != 1)
		{
			printf("Error!\n");
			return 1;
		}

		if (x == 0)
			part1a();
		else if (x == 1)
			part1b();
		else
			printf("Not 0/1\n");

		break;
	case 1:

		printf("Enter 0/1\n");
		printf("0 : Size V/s Time\n1 : Loop Order V/s Time\n?- ");

		e = scanf("%d", &x);

		if (e != 1)
		{
			printf("Error!\n");
			return 1;
		}

		if (x == 0)
			part2a();
		else if (x == 1)
			part2b();
		else
			printf("Not 0/1\n");

		break;
	default:

		printf("Not 0/1\n");
		break;
	}

	return 0;
}
