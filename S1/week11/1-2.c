#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
double length_of_vector ( int n, double A[] )
{
    long double x=0;
    for(int i=0;i<n;i++)
        x+=(A[i]*A[i]);

    return sqrt(x);
}
*/
double angle_between_2_vectors ( int n, double A[], double B[] )
{
    long double x=0;
    long double a=0,b=0;
    long double a_length=0,b_length=0;
    long double cos_of_ab=0;

    for(int i=0;i<n;i++)
    {
        x+=A[i]*B[i];
        a+=A[i]*A[i];
        b+=B[i]*B[i];
    }
    a_length=sqrt(a);
    b_length=sqrt(b);

    cos_of_ab = x/a_length/b_length;

    return acos(cos_of_ab);
}
