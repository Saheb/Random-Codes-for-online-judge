//Problem Link is below.
//http://www.codechef.com/problems/SUMTRIAN
#include<stdio.h>
int arr[101][101];
int ans[101][101];
int max(int a,int b)
{
    if(a>=b)
        return a;
    else
        return b;
}
int maximum(int i,int j)
{
    ans[i][j] = arr[i][j] + max(ans[i+1][j],ans[i+1][j+1]);
}
int main()
{
    int cases,rows;
    scanf("%d",&cases);
    while(cases--)
        {
            scanf("%d",&rows);
            for(int a=0;a<=rows;a++)
                for(int b=0;b<=a;b++)
                    {
                        arr[a][b] = 0;
                        ans[a][b] = 0;
                    }

            for(int i=0;i<rows;i++)
                for(int j=0;j<=i;j++)
                    scanf("%d",&arr[i][j]);

            for(int i=rows-1;i>=0;i--)
                    {
                        for(int j=0;j<=i;j++)
                            {
                                maximum(i,j);
                            }
                    }
            printf("%d\n",ans[0][0]);
        }
return 0;
}
