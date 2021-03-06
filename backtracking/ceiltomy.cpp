//Here is the link for the problem//
///http://www.codechef.com/problems/CIELTOMY///
#include<stdio.h>
#define INF 100
using namespace std;
bool visited[11];
int adj[11][11];
int n,count;
int L;
void backtrack(int node, int len)
{
    if (len>L)
        return;

    if (node == n)
        {
            if (len<L)
                {
                L = len;
                count = 1;
                }
            else if (len == L)
                count = count + 1;
        return;
        }

    visited[node]=true;

    for(int j=1;j<=n;j++)
        {
            if(visited[j]==false && adj[node][j]>0)
            {
                backtrack(j,len+adj[node][j]);
            }
        }
    visited[node]=false;
}

int main()
{
    int test,m,temp1,temp2;
    scanf("%d",&test);
    while(test--)
        {
            scanf("%d",&n);
            scanf("%d",&m);
            for(int j=0; j<=n; j++) visited[j] = false;
            for(int j=0; j<=n; j++) for(int k=0; k<=n; k++) adj[j][k] = 0;
            for(int i=1;i<=m;i++)
                {
                    scanf("%d",&temp1);
                    scanf("%d",&temp2);
                    scanf("%d",&adj[temp1][temp2]);
                    adj[temp2][temp1] = adj[temp1][temp2];
                }
            bool visited[11] = {false};
            count = 0;
            visited[1] = true;
            L = INF;
            backtrack(1,0);
            printf("%d\n",count);
        }
}
