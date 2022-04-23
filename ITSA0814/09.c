#include <stdio.h>
#include <stdlib.h>


int main()
{

    int nc;
    scanf("%d",&nc);
    for(int nci=0;nci<nc;nci++)
    {
        int a[5][5];
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<5;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }

        int out =   a[0][0]+ a[0][1]+ a[0][2]+ a[0][3]+ a[0][4]+
                    a[1][0]+ a[1][4]+
                    a[2][0]+ a[2][4]+
                    a[3][0]+ a[3][4]+
                    a[4][0]+ a[4][1]+ a[4][2]+ a[4][3]+ a[4][4];

        int in =    a[1][1]+ a[1][2]+ a[1][3]+
                    a[2][1]+ a[2][3]+
                    a[3][1]+ a[3][2]+ a[3][3];

        int mid =   a[2][2];


        if(out == 12 && in == 0 && mid == 0)
            printf("0\n");
        else if(out == 2 && in == 2 && mid == 1)
            printf("1\n");
        else if(out == 10 && in == 2 && mid == 0)
            printf("2\n");
        else if(out == 10 && in == 1 && mid == 1)
            printf("3\n");
        else if(out == 5 && in == 4 && mid == 1)
            printf("4\n");
        else if(out == 12 && in == 2 && mid == 1)
            printf("5\n");
        else if(out == 6 && in == 3 && mid == 1)
        {
            int x[8],found=0;
            x[0]=a[1][1];
            x[1]=a[1][2];
            x[2]=a[1][3];
            x[3]=a[2][3];
            x[4]=a[3][3];
            x[5]=a[3][2];
            x[6]=a[3][1];
            x[7]=a[2][1];

            for(int z=0;z<7;z++)
            {
                if(x[z] == 1 && x[z+1] == 1)
                {
                    printf("9\n");
                    found = 1;
                }
            }
            if(found == 0)
            {
                if(x[0]==1 && x[7]==1)
                    printf("9\n");
                else
                    printf("6\n");
            }
        }
        else if(out == 6 && in == 2 && mid == 0)
            printf("7\n");
        else if(out == 10 && in == 2 && mid == 1)
            printf("8\n");
    }
    return 0;
}
