#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#define N 150
#define max(a,b) (a>b?a:b)
#define min(a,b) (a>b?b:a)
#define ll long long
int edg[N][N],v[N];
void clear(){
    for(int i=0;i<100;i++)v[i]=0;
}
int n,m;
void dfs(int x){
    v[x]=1;
    printf("%d ",x);
    for(int i=0;i<n;i++){
        if(edg[x][i]&&!v[i])dfs(i);
    }
    if(x==0)printf("\n");
}
int q[N];
void bfs(int x){
    for(int i=0;i<=n;i++)q[i]=0;
    v[0]=1;
    int head=1,tail=0;
    q[++tail]=0;
    while(head<=tail){
        int now=q[head++];
        printf("%d ",now);
        for(int i=0;i<n;i++){
            if(edg[now][i]&&!v[i]){
                v[i]=1;q[++tail]=i;
            }
        }
    }
    printf("\n");
}
int main(){
    scanf("%d%d",&n,&m);
    int x,y;
    while(m--){
        scanf("%d%d",&x,&y);
        edg[x][y]=edg[y][x]=1;
    }
    dfs(0);clear();
    bfs(0);clear();
    int s;scanf("%d",&s);
    v[s]=1;dfs(0);clear();
    v[s]=1;bfs(0);clear();
    return 0;
}
