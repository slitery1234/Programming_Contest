#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double determinant(int n,double A[][n])
{
    if(n==2)
    {
        double d;
        double a=A[0][0]*A[1][1],b=A[0][1]*A[1][0];
        d=a-b;
        //printf("%lf ",d);
        return  d;
    }
    else
    {
        double d=0;

        for(int i=0;i<n;i++)
        {
            int a=-1;
            double A2[n-1][n-1];


            for(int j=0;j<n-1;j++)
            {
                if(((a+1)==i)&&(a+2<=n-1))
                    a+=2;
                else
                    a++;

                for(int k=0;k<n-1;k++)
                {
                    A2[j][k]=A[a][k+1];

                   /* printf("a=%d,b=%d",a,k+1);
                    printf("A[%d][%d]=",j,k);
                    printf("%lf\n",A2[j][k]);*/
                }
                //printf("\n");
            }
            //printf("\n");

            d+= pow(-1,i) * (A[i][0]) * determinant(n-1,A2);
            //printf("\n%lf\n",d);
        }
        return d;
    }
}
/*
int main()
{
    double A[3][3];
    for(int j=0;j<3;j++)
    {
        for(int k=0;k<3;k++)
        {
            scanf("%lf",&A[j][k]);
        }
    }
    //printf("%lf\n",A[0][1]);
    printf("%lf\n",determinant(3,A));
    //printf("%lf",);
    return 0;
}*/
