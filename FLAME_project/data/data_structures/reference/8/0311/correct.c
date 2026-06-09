#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int s[105][105],visit[105]={0},queue[105];
void dfs(int p,int n){
    visit[p]=1;
    printf("%d ",p);
    int i;
    for(i=0;i<n;i++){
        if(s[p][i]==1&&visit[i]==0)
            dfs(i,n);
    }
}
void bfs(int p,int n){
    int t;
    queue[0]=p;
    int begin=0,end=0;
    for(;begin<=end;){
        t=queue[begin];begin++;
        if(visit[t]!=1){
            printf("%d ",t);
            visit[t]=1;
            int i;
            for(i=0;i<n;i++){
                if(s[t][i]==1&&visit[i]==0){
                    end++;queue[end]=i;
                }
            }
        }
    }
}
int main(){
    int n,edg;
    scanf("%d%d",&n,&edg);
    int i;
    for(i=1;i<=edg;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        s[a][b]=1;s[b][a]=1;
    }
    int dlt;
    scanf("%d",&dlt);
    dfs(0,n);
    printf("\n");
    for(i=0;i<105;i++)
        visit[i]=0;
    bfs(0,n);
    printf("\n");
    for(i=0;i<105;i++)
        visit[i]=0;
    visit[dlt]=1;
    dfs(0,n);
    printf("\n");
    for(i=0;i<105;i++)
        visit[i]=0;
    visit[dlt]=1;
    bfs(0,n);
    return 0;
}

