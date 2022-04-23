#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int ncase;
    scanf("%d",&ncase);
    double ordinate[ncase][2];
    double p0[2];
    int convex_hull_tag[ncase+1];

    for(int i=0; i<ncase; i++)
    {
        scanf("%lf%lf",&ordinate[i][0],&ordinate[i][1]);
        if(i==0)
        {
            p0[0]=ordinate[i][0];
            p0[1]=ordinate[i][1];
            convex_hull_tag[0]=i+1;
        }
        else if(ordinate[i][0]>p0[0])
        {
            p0[0]=ordinate[i][0];
            p0[1]=ordinate[i][1];
            convex_hull_tag[0]=i+1;
        }
        convex_hull_tag[i+1]=0;
    }


    double vec[2]= {0,1};
    int n=0;

   // printf("vec:%lf,%lf p0:%lf,%lf\n\n\n",vec[0],vec[1],p0[0],p0[1]);
    do
    {
        n++;
        double a_dot_b,a_length,b_length;
        double abcos=-2,n_abcos;

        for(int i=0; i<ncase; i++)
        {
            if( (p0[0]==ordinate[i][0]) && (p0[1]==ordinate[i][1]) )
            {

            }
            else
            {
                a_dot_b = ((ordinate[i][0]-p0[0])*vec[0]) + ((ordinate[i][1]-p0[1])*vec[1]);
                a_length = sqrt( pow( ( ordinate[i][0]-p0[0] ),2) + pow( ( ordinate[i][1]-p0[1] ),2) );
                b_length = sqrt( pow(vec[0],2) + pow(vec[1],2) );
                n_abcos= (a_dot_b/a_length) / b_length;

                //printf("%lf %lf %lf %lf\n",a_dot_b,a_length,b_length,n_abcos);

                if(abcos < n_abcos)
                {
                    abcos = (a_dot_b/a_length) / b_length;
                    convex_hull_tag[n]=i+1;
                    //printf("point:%d\n\n",convex_hull_tag[n]);
                }
            }

        }


        vec[0]=ordinate[convex_hull_tag[n]-1][0] - p0[0];
        vec[1]=ordinate[convex_hull_tag[n]-1][1] - p0[1];
        p0[0]=ordinate[convex_hull_tag[n]-1][0];
        p0[1]=ordinate[convex_hull_tag[n]-1][1];
        abcos=-2;

        //printf("vec:%lf,%lf p0:%lf,%lf\n",vec[0],vec[1],p0[0],p0[1]);
        //printf("--------------------\n");
    }
    while(convex_hull_tag[n]!=convex_hull_tag[0]);

    for(int i=0;i<ncase+1;i++)
    {
        if(convex_hull_tag[i]==0)
            break;
        else
            printf("%d ",convex_hull_tag[i]);
    }


    return 0;
}
