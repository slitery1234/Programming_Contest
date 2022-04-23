#include <stdio.h>
#include <stdlib.h>

void matrix_cross(int n2 , int A[n2][n2], int B[n2][n2], int C[n2][n2])
{

    if(n2 == 2)
    {
        int m[8];
        m[0] = (A[0][0]+A[1][1]) * (B[0][0]+B[1][1]);
        m[1] = (A[1][0]+A[1][1]) * (B[0][0]);
        m[2] = (A[0][0]) * (B[0][1]-B[1][1]);
        m[3] = (A[1][1]) * (B[1][0]-B[0][0]);
        m[4] = (A[0][0]+A[0][1]) * (B[1][1]);
        m[5] = (A[1][0]-A[0][0]) * (B[0][0]+B[0][1]);
        m[6] = (A[0][1]-A[1][1]) * (B[1][0]+B[1][1]);

        C[0][0] = m[0] + m[3] - m[4] + m[6];
        C[0][1] = m[2] + m[4];
        C[1][0] = m[1] + m[3];
        C[1][1] = m[0] - m[1] + m[2] + m[5];
    }
    else
    {
        int newn = n2/2;

        int A11[newn][newn];
        int A12[newn][newn];
        int A21[newn][newn];
        int A22[newn][newn];

        int B11[newn][newn];
        int B12[newn][newn];
        int B21[newn][newn];
        int B22[newn][newn];

        for(int i=0;i<newn;i++)
        {
            for(int j=0;j<newn;j++)
            {
                A11[i][j] = A[i][j];
                A12[i][j] = A[i][j+newn];
                A21[i][j] = A[i+newn][j];
                A22[i][j] = A[i+newn][j+newn];

                B11[i][j] = B[i][j];
                B12[i][j] = B[i][j+newn];
                B21[i][j] = B[i+newn][j];
                B22[i][j] = B[i+newn][j+newn];
            }
        }

        int temp1[newn][newn];
        int temp2[newn][newn];

        int m1[newn][newn];
        int m2[newn][newn];
        int m3[newn][newn];
        int m4[newn][newn];
        int m5[newn][newn];
        int m6[newn][newn];
        int m7[newn][newn];


        //----------------------------------
        for(int i=0;i<newn;i++)
        {
            for(int j=0;j<newn;j++)
            {
                temp1[i][j] = A11[i][j] + A22[i][j];
                temp2[i][j] = B11[i][j] + B22[i][j];
            }
        }
        matrix_cross(newn , temp1, temp2, m1);
        //----------------------------------
        for(int i=0;i<newn;i++)
        {
            for(int j=0;j<newn;j++)
            {
                temp1[i][j] = A21[i][j] + A22[i][j];
                temp2[i][j] = B11[i][j];
            }
        }
        matrix_cross(newn , temp1, temp2, m2);
        for(int i=0;i<newn;i++)
        {
            for(int j=0;j<newn;j++)
            {
                temp1[i][j] = A21[i][j] + A22[i][j];
                temp2[i][j] = B11[i][j];
            }
        }
        //----------------------------------
        for(int i=0;i<newn;i++)
        {
            for(int j=0;j<newn;j++)
            {
                temp1[i][j] = A11[i][j];
                temp2[i][j] = B12[i][j] - B22[i][j];
            }
        }
        matrix_cross(newn , temp1, temp2, m3);
        //----------------------------------
        for(int i=0;i<newn;i++)
        {
            for(int j=0;j<newn;j++)
            {
                temp1[i][j] = A22[i][j];
                temp2[i][j] = B21[i][j] - B11[i][j];
            }
        }
        matrix_cross(newn , temp1, temp2, m4);
        //----------------------------------
        for(int i=0;i<newn;i++)
        {
            for(int j=0;j<newn;j++)
            {
                temp1[i][j] = A11[i][j] + A12[i][j];
                temp2[i][j] = B22[i][j];
            }
        }
        matrix_cross(newn , temp1, temp2, m5);
        //----------------------------------
        for(int i=0;i<newn;i++)
        {
            for(int j=0;j<newn;j++)
            {
                temp1[i][j] = A21[i][j] - A11[i][j];
                temp2[i][j] = B11[i][j] + B12[i][j];
            }
        }
        matrix_cross(newn , temp1, temp2, m6);
        //----------------------------------
        for(int i=0;i<newn;i++)
        {
            for(int j=0;j<newn;j++)
            {
                temp1[i][j] = A12[i][j] - A22[i][j];
                temp2[i][j] = B21[i][j] + B22[i][j];
            }
        }
        matrix_cross(newn , temp1, temp2, m7);
        //----------------------------------
        for(int i=0;i<newn;i++)
        {
            for(int j=0;j<newn;j++)
            {
                C[i][j] = m1[i][j] + m4[i][j] - m5[i][j] + m7[i][j];
                C[i][j+newn] = m3[i][j] + m5[i][j];
                C[i+newn][j] = m2[i][j] + m4[i][j];
                C[i+newn][j+newn] = m1[i][j] - m2[i][j] + m3[i][j] + m6[i][j];
            }
        }
    }
    return;

}


int main()
{
    int pow_of_two[11];
    pow_of_two[0]=1;
    for(int i=1;i<11;i++)
        pow_of_two[i] = pow_of_two[i-1] * 2;
    int n,n2;
    scanf("%d",&n);
    for(int i=0;i<11;i++)
    {
        if(n <= pow_of_two[i])
        {
            n2 = pow_of_two[i];
            i = 12;
        }
    }
    int ori_matrix1[n2][n2];
    int ori_matrix2[n2][n2];
    int ans_matrix[n2][n2];

    for(int i=0;i<n2;i++)
    {
        for(int j=0;j<n2;j++)
        {
            ori_matrix1[i][j] = 0;
            ori_matrix2[i][j] = 0;
            ans_matrix[i][j] = 0;
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&ori_matrix1[i][j]);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&ori_matrix2[i][j]);
        }
    }
    matrix_cross(n2 ,ori_matrix1,ori_matrix2,ans_matrix);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",ans_matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
