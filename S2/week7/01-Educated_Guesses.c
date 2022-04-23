#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
int binary_search ( int A[], int n, int k )
{
    int left=0,right=(n-1);
    int mid=(left+right)/2;


    while(left<right||left==right)
    {
        if(k==A[mid])
            return 1;
        else if(k>A[mid])
        {
            left=mid+1;
            mid=(left+right)/2;
        }
        else if(k<A[mid])
        {
            right=mid-1;
            mid=(left+right)/2;
        }
    }

    return 0;
}
*/
int main()
{

    unsigned int left=1,right=2147483647;
    unsigned int mid=(left+right)/2;
    int end=0;

    printf("? %u\n",mid);
    fflush(stdout);

    char message[50];
    while(end==0)
    {

        scanf("%s",message);
        if( strncmp(message,"C",1)==0 || strncmp(message,"A",1)==0 )
            end=1;
        else if(strcmp(message,">")==0)
        {
            right=mid-1;
            mid=(left+right)/2;
            printf("? %u\n",mid);
        }
        else if(strcmp(message,"<")==0)
        {
            left=mid+1;
            mid=(left+right)/2;
            printf("? %u\n",mid);
        }
        fflush(stdout);
        fflush(stdin);

    }

    return 0;
}
