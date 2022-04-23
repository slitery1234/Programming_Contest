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
/*
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
*/
/*
int sum ( int *a, int *b )
{
    return *a+*b;
}
*/
/*
int compare (const void *a, const void *b)
{
    int x=*(int*)a;
    int y=*(int*)b;
    return x-y;
}
*/
void calculate_tile_placement ( int N, int obs[2] )
{
    int space[N][N];
    int tile_n=1;
    for(int i=0;i<N;i++)
        tile_n*=4;

    tile_n/=3;
    int tile[3][2];

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            space[i][j]=0;
    }
    space[obs[0]][obs[1]]=2;

    if(obs[0]%2==0)
    {
        if(obs[1]%2==0)
        {
            tile[0][0]=obs[0]+1;
            tile[0][1]=obs[1];
            tile[1][0]=obs[0];
            tile[1][1]=obs[1]+1;
            tile[2][0]=obs[0]+1;
            tile[2][1]=obs[1]+1;
        }
        else
        {
            tile[0][0]=obs[0]+1;
            tile[0][1]=obs[1];
            tile[1][0]=obs[0];
            tile[1][1]=obs[1]-1;
            tile[2][0]=obs[0]+1;
            tile[2][1]=obs[1]-1;
        }
    }
    else
    {
        if(obs[1]%2==0)
        {
            tile[0][0]=obs[0]-1;
            tile[0][1]=obs[1];
            tile[1][0]=obs[0];
            tile[1][1]=obs[1]+1;
            tile[2][0]=obs[0]-1;
            tile[2][1]=obs[1]+1;
        }
        else
        {
            tile[0][0]=obs[0]-1;
            tile[0][1]=obs[1];
            tile[1][0]=obs[0];
            tile[1][1]=obs[1]-1;
            tile[2][0]=obs[0]-1;
            tile[2][1]=obs[1]-1;
        }
    }
    tile_n--;
    fill_with_tile(N,space,tile);

    /*for(int i=0;i<tile_n;i++)
        place_tile_At(tile[i]);*/
}
int fill_with_tile(int n,int space[n][n], int position[3][2])
{
    space[position[0][0]][position[0][1]]=1;
    space[position[1][0]][position[1][1]]=1;
    space[position[2][0]][position[2][1]]=1;
}

