/* probID: MT2-B-6-Determinant */

double determinant(int n,double A[9][9])
{
    if(n == 1)
        return A[0][0];
    else
    {
        double ans = 0;
        for(int j=0;j<n;j++)
        {
            double A2[9][9];
            for(int i=1;i<n;i++)
            {
                for(int k=0;k<n;k++)
                {
                    if(k < j)
                        A2[i-1][k] = A[i][k];
                    else if(k > j)
                        A2[i-1][k-1] = A[i][k];
                }
            }
            ans += ((-1)*(j%2) + (!(j%2))) * A[0][j] * determinant(n-1,A2);
        }
        return ans;
    }
}
