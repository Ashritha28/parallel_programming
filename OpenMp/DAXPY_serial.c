#include <stdio.h>
#include <omp.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define vector_size pow(2,16)

int main()
{
	int vectorX[(int)vector_size];
	int vectorY[(int)vector_size];
	int a = 10;
	int i;
	for(i=0;i<(int)vector_size;i++)
	{
		int r1 = rand() % 101;
		vectorX[i] = r1;
		int r2 = rand() % 501;
		vectorY[i] = r2;
	}
	clock_t begin = clock();
	for (i = 0; i < (int)vector_size; i++)
	{
		vectorX[i] = a*vectorX[i] + vectorY[i];
	}
	clock_t end = clock();
	double serial_time = (double)(end - begin)/CLOCKS_PER_SEC;
	printf("%lf\n", serial_time);
}