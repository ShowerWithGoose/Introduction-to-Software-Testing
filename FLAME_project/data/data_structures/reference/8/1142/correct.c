#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define ll long long 
#define ull unsigned long long
int read()
{
	int x=0,fl=1;char st=getchar();
	while(st<'0'||st>'9'){ if(st=='-')fl=-1; st=getchar();}
	while(st>='0'&&st<='9') x=x*10+st-'0',st=getchar();
	return x*fl;
}
int maps[10005][1005];
int rt;
int n,m;
int vis[1005];
void dfs(int x)
{
    printf("%d ",x);
    vis[x]=1;
    for(int i=0;i<n;i++)
    {
        if(vis[i]||maps[x][i]==0) continue;
        dfs(i);
    }
}
int q[10005],h,t;
void bfs()
{
    h=1;t=0;
    q[++t]=0;
    vis[0]=1;
    while(h<=t)
    {
        int x=q[h];h++;
        printf("%d ",x);
        for(int i=0;i<n;i++)
        {
            if(vis[i]||maps[x][i]==0) continue;
            q[++t]=i;vis[i]=1;
        }
    }
}
int main()
{
    n=read();m=read();
    for(int i=1;i<=m;i++)
    {
        int x=read(),y=read();
        maps[x][y]=1;
        maps[y][x]=1;
    }
    rt=read();
    dfs(0);
    printf("\n");
    memset(vis,0,sizeof vis);
    bfs();
    printf("\n");
    memset(vis,0,sizeof vis);
    vis[rt]=1;
    dfs(0);
    printf("\n");
    memset(vis,0,sizeof vis);
    vis[rt]=1;
    bfs();
    printf("\n");
    return 0;
}

