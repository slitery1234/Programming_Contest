#include <stdio.h>
#include <stdlib.h>

int motion(int,int,int,int);

int main()
{
    int n;
    scanf("%d",&n);
    int nx,ny,nz;
    int ballx,bally,ballz;
    int vx,vy,vz;
    int endx,endy,endz;
    int t;
    if(n==1)
    {
        scanf("%d",&nx);
        scanf("%d",&ballx);
        scanf("%d",&vx);
        scanf("%d",&t);
        endx=motion(nx,ballx,vx,t);

        printf("%d",endx);
    }
    else if(n==2)
    {
        scanf("%d%d",&nx,&ny);
        scanf("%d%d",&ballx,&bally);
        scanf("%d%d",&vx,&vy);
        scanf("%d",&t);

        endx=motion(nx,ballx,vx,t);
        endy=motion(ny,bally,vy,t);

        printf("%d %d",endx,endy);
    }
    else if(n==3)

    {
        scanf("%d%d%d",&nx,&ny,&nz);
        scanf("%d%d%d",&ballx,&bally,&ballz);
        scanf("%d%d%d",&vx,&vy,&vz);
        scanf("%d",&t);

        endx=motion(nx,ballx,vx,t);
        endy=motion(ny,bally,vy,t);
        endz=motion(nz,ballz,vz,t);

        printf("%d %d %d",endx,endy,endz);
    }
    return 0;
}

int motion(int n,int ball,int v,int t)
{
    int to_wall,remain;
    for(int i=0;i<t;i++)
    {
        if(ball+v>0&&ball+v<n)
            ball+=v;
        else
        {
            if(v>0)
            {
                to_wall=n-ball;
                remain=n-(v-to_wall);
            }
            else
            {
                to_wall=0-ball;
                remain=0-(v-to_wall);
            }
            ball=remain;
            v=-v;
        }
    }
    return ball;
}
