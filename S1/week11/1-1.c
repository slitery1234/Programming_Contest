#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double length_of_vector ( int n, double A[] )
{
    long double x=0;
    for(int i=0;i<n;i++)
        x+=(A[i]*A[i]);

    return sqrt(x);
}
