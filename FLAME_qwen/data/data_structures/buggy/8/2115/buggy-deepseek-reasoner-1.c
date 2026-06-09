#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int e[10000][10000]; // @@ Array too large; will cause stack overflow. Use smaller size (e.g., e[110][110]).
int st[10000];
int sum1;
int n,m;
void dfs(int u)
{
    printf("%d ",u); // @@ Prints trailing space; expected no trailing space.
    st[u]=1;
    for(int i=0;i<n;i++) 
    {
        if(!st[i]&&e[u][i])
        {
        st[i]=1;
        dfs(i);
        }    
    }
}
int queue[100000];
int top=0;
int tail=0;
int std[10000];
void bfs(int u)
{
    queue[tail++]=u; // @@ tail not reset; should set top=tail=0 at start of bfs.
    std[u]=1;
    while(tail>top)
    {
        int t=queue[top]; // @@ top not reset; should set top=tail=0 at start of bfs.
        printf("%d ",t); // @@ Prints trailing space; expected no trailing space.
        top++;
        for(int i=0;i<n;i++)
        {
            if(!std[i]&&e[t][i])
            {    queue[tail++]=i;
                std[i]=1;
            }
        }
    }
}
int main()
{
    memset(e,0,sizeof(int)); // @@ Wrong size; should be sizeof(e) or sizeof(e[0])*n*n.
    memset(st,0,sizeof(int)); // @@ Wrong size; should be sizeof(st).
    scanf("%d%d",&n,&m);
    while(m--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        e[x][y]=1;
        e[y][x]=1;
    }
    int re;scanf("%d",&re);
    for(int i=0;i<n;i++)
    {
        if(!st[i]) dfs(i);
    }
    printf("\n");
    memset(std,0,sizeof(int)); // @@ Wrong size; should be sizeof(std).
    for(int i=0;i<n;i++)
    {
        if(!std[i]) 
        {
        bfs(i);    
        }
    }
    printf("\n");

    for(int i=0;i<n;i++)
    {
        e[i][re]=0;
        e[re][i]=0;
    }
    for(int i=0;i<n;i++)
    {
        st[i]=std[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        if(!st[i]) dfs(i);
    }
    printf("\n");
        
    for(int i=0;i<n;i++)
    {
        if(!std[i]) 
        {
        bfs(i);    
        }
    }
    return 0; // @@ Missing newline after final BFS output.
}