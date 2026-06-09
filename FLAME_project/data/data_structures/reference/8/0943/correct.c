#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define N 1005
int graph[N][N];
int visit[N];
int n,m;
void dfs(int start);
void bfs(int start);
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf("%d %d",&n,&m);//输入顶点个数 边数
    int s,t;
    for(int i=0;i<m;++i){
        scanf("%d %d",&s,&t);
        graph[s][t]=1;
        graph[t][s]=1;
    }
    int back;
    scanf("%d",&back);
    dfs(0);
    puts("");
    bfs(0);
    puts("");
    for(int i=0;i<n;++i){
        graph[back][i]=0;
        graph[i][back]=0;
    }
    memset(visit,0,sizeof (visit));
    dfs(0);
    puts("");
    bfs(0);
    return 0;
}
void dfs(int start){
    printf("%d ",start);
    visit[start]=1;//标记某个顶点已经访问过了
    for(int i=0;i<n;++i){
        if(graph[start][i]&&!visit[i]){
            dfs(i);
        }
    }
}
void bfs(int start){
    int queue[N]={0};
    int head=0,tail=1;
    memset(visit,0,sizeof (visit));
    queue[head]=start;
    visit[start]=1;
    while(head<tail){
        printf("%d ",queue[head]);
        for(int i=0;i<n;i++){
            if(!visit[i]&&graph[i][queue[head]]==1){
                queue[tail++]=i;
                visit[i]=1;
            }
        }
        head++;
    }
}

