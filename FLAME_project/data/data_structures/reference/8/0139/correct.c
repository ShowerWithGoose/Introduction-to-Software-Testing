#include<time.h>
#include<math.h>
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define ll long long
#define maxn 1005
int n,m,s;
int mp[maxn][maxn];
bool vis[maxn];

int max(int a,int b){return a>=b ? a : b ;}
int min(int a,int b){return a<=b ? a : b ;}

void dfs(int x){
    printf("%d ",x);
    vis[x]=true;
    for(int i=0;i<n;i++)
     if(!vis[i]&&mp[x][i]) dfs(i);
}

int h,t,q[maxn];
void bfs(){
    h=1,t=0;
    q[++t]=0,vis[0]=true;
    while(h<=t){
        int x=q[h++];
        printf("%d ",x);
        for(int i=0;i<n;i++)
         if(!vis[i]&&mp[x][i]){
             vis[i]=true;
             q[++t]=i;
         }
    }
}

int main(){
    /*double st=clock();*/
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        mp[x][y]=mp[y][x]=1;
    }
    scanf("%d",&s);

    dfs(0);
    putchar('\n');

    memset(vis,false,sizeof(vis));
    bfs();
    putchar('\n');

    memset(vis,false,sizeof(vis));
    vis[s]=true;
    dfs(0);
    putchar('\n');

    memset(vis,false,sizeof(vis));
    vis[s]=true;
    bfs();
    /*double ed=clock();
    printf("Time:%lf ms",ed-st);*/
    return 0;
}
