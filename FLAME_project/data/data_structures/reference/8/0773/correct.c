#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<ctype.h>
#define ll long long
#define For(a, b, c) for (int a = b; a < c;a++)
#define FOR(a, b, c) for (int a = c - 1; a >= b;a--)
#define ull unsigned long long
#define MAXN 1000000
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))
int weights[200][200],vis[200],queue[200];
int n,m;
void DFS(int v){
    printf("%d ",v);
    vis[v]=1;
    for(int i=0;i<n;i++)
        if(weights[v][i]&&!vis[i])
            DFS(i);
}
void BFS(int v){
    int head=0,tail=1;
    queue[head]=v;
    while(head<tail){
        int tmp=queue[head];
        head++;
        if(!vis[tmp]){
            printf("%d ",tmp);
            vis[tmp]=1;
            for(int i=0;i<n;i++)
                if(weights[tmp][i]&&!vis[i])
                    queue[tail++]=i;
        }
    }
}
int main(){
    int v,u,p;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d %d",&u,&v);
        weights[u][v]=1;
        weights[v][u]=1;
    }
    DFS(0);
    printf("\n");
    memset(vis,0,sizeof(vis));
    BFS(0);
    printf("\n");
    scanf("%d",&p);
    memset(vis,0,sizeof(vis));
    vis[p]=1;
    DFS(0);
    printf("\n");
    memset(vis,0,sizeof(vis));
    vis[p]=1;
    BFS(0);
}
