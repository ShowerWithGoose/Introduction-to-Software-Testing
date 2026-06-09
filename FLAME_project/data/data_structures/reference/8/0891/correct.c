#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int visit[100],flag=0,n,s[100][100];

void dfs(int a)
{
    printf("%d ",a);
    visit[a]=1;
    for(int i=1;i<=n;i++)
    {
        if(s[a][i]>0&&visit[i]==0)
            dfs(i);
    }
}
int b[100];
void bfs(int a)
{
    b[1]=a;
    int l=1,r=1,t;
    while(l<=r)
    {
        t=b[l++];
        if(visit[t]==0)
        {
            visit[t]=1;
            printf("%d ",t);
            for(int i=1;i<=n;i++)
            {
                if(s[t][i]>0&&visit[i]==0)
                {
                    r++;
                    b[r]=i;
                }

            }
        }
    }
    printf("\n");
}
int main()
{
    int m,a,b;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d",&a,&b);
        s[a][b]=s[b][a]=1;
    }
    dfs(0);
    printf("\n");
    memset(visit,0,sizeof(visit));
    bfs(0);
    memset(visit,0,sizeof(visit));

    scanf("%d",&a);
    visit[a]=1;
    dfs(0);
    printf("\n");
    memset(visit,0,sizeof(visit));
    visit[a]=1;
    bfs(0);

}

