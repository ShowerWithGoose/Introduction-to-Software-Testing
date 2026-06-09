#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int n,b;
int a[110][110];
int path[110];
void dfs(int x,int num)
{
    printf("%d ",x);
    path[x]=1;
    if(n==num)
    {
        return ;
    }
    int i;
    for(i=0;i<n;i++)
    {
        if(a[x][i])
        {
            if(!path[i])
            {                
                dfs(i,num+1);
            }
        }
    }
}
void bfs()
{
    int quee[110]={0};
    int l=0,r=1;
    quee[l]=0;
    path[0]=1;
    int i;
    while(l<r)
    {
        for(i=0;i<n;i++)
        {
            if(a[quee[l]][i])
            {
                if(!path[i])
                {
                    path[i]=1;
                    quee[r++]=i;
                }
            }
        }
        printf("%d ",quee[l]);
        l++;
    }
    puts("");
}
int main()
{
    memset(a,0,sizeof(a));
    int i,j,p,q,del;
    scanf("%d%d",&n,&b);
    for(i=0;i<b;i++)
    {
        scanf("%d %d",&p,&q);
        a[p][q]=1;
        a[q][p]=1;
    }
    scanf("%d",&del);
    dfs(0,1);
    puts("");
    memset(path,0,sizeof(path));
    bfs();
    for(i=0;i<n;i++)
    {
        a[i][del]=0;
        a[del][i]=0;
    }
    memset(path,0,sizeof(path));
    dfs(0,1);
    puts("");
    memset(path,0,sizeof(path));
    bfs();
    return 0;
}


