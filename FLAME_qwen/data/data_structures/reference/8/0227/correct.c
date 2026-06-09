#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define N 1005
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)>(b)?(b):(a))
typedef long long ll;
int w[200][200];
int visit[200]={0};
int q[200];
int n,m;
void dfs(int v)
{
int i;
printf("%d ",v);
visit[v]=1;
for(i=0;i<n;i++)
{   if(w[v][i]&&!visit[i])
    dfs(i);
}
}
void bfs(int v)
{
int i,head=0,tail=1,t;
q[head]=v;
while(head<=tail)
{
    t=q[head];
    head++;
    if(visit[t])
    continue;
    else
    {
    printf("%d ",t);
    visit[t]=1;
    for(i=0;i<n;i++)
    {
        if(w[t][i]&&!visit[i])
        q[tail++]=i;
    }

    }
}

}
int read();
int main()
{

int x,y,i,d;
scanf("%d %d",&n,&m);
for(i=0;i<m;i++)
{
    scanf("%d %d",&x,&y);
    w[x][y]=1;
    w[y][x]=1;
}
dfs(0);
printf("\n");
memset(visit,0,sizeof(visit));
bfs(0);
printf("\n");
scanf("%d",&d);
memset(visit,0,sizeof(visit));
visit[d]=1;
dfs(0);
printf("\n");
memset(visit,0,sizeof(visit));
memset(q,0,sizeof(q));
visit[d]=1;
bfs(0);
printf("\n");
return 0;
}
int read(){
int x=0,f=1,c=getchar();
while(c<'0'||c>'9')(c=='-')?(f=-1):0,c=getchar();
while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
return x*f;
}
