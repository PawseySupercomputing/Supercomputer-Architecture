#include "stdlib.h"
#include "stdio.h"
#include "math.h"

int main(int argc, char** argv)
{
	// iterators
	int i,j;	

	// domain
	int tot = 10000;
	double min = -10.0;
	double max = 10.0;
	double range = max-min;
	double inc = range/tot;
	
	// allocate memory
	int size = tot*tot;
	int bsize = size*sizeof(double);
	double* val = (double*)malloc(bsize);
	
	// write gaussian
	for (i=0; i<tot; i++)
	{
		for (j=0; j<tot; j++)
		{
			int xi = i;
			int yi = j;
			double x = min+xi*inc;
			double y = min+yi*inc;
			val[yi*tot+xi] = exp(-1*(x*x+y*y));
		}
	}

	// read and integrate gaussian
	double sum = 0;
	for (i=0; i<tot; i++)
	{
		for (j=0; j<tot; j++)
		{
			int xi = i;
			int yi = j;
			sum += val[yi*tot+xi];
		}
	}
	sum = sum*inc*inc;
	printf("Integral of 2D gaussian: %f\n",sum);

	// free allocations
	free(val);

	return EXIT_SUCCESS;
}

