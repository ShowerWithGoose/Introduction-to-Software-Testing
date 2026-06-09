#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
int m,n,a[110][110];
int visit[110],flag,p[105];
void DFS(int x)
{
    if(flag==0)
    {
        printf("%d",x);
        flag=1;
    }
    else printf(" %d",x);
    visit[x]=1;
    int i;
    for(i=1;i<=n;i++){
        if(a[x][i]==1){
            if(visit[i]==0)DFS(i);
        }
    }
}
void BFS(int x)
{
    p[1]=x;
    int left=1,right=1,i;
    while(left<=right){
        int q=p[left];
        left++;
        if(visit[q]==1)continue;
        if(flag==0){
            printf("%d",q);
            flag=1;
        }
        else printf(" %d",q);
        visit[q]=1;
        for(i=1;i<=n;i++){
            if(a[q][i]==1){
                if(visit[i]==0)p[++right]=i;
            }
        }
    }
    memset(visit,0,sizeof(visit));
}
int main()
{
    scanf("%d%d",&n,&m);
    int i,x,y,t;
    for(i=1;i<=m;i++){
        scanf("%d%d",&x,&y);
        a[x][y]=1;
        a[y][x]=1;
    }
    scanf("%d",&t);
    flag=0;
    DFS(0);
    printf("\n");
    memset(visit,0,sizeof(visit));
    flag=0;
    BFS(0);
    printf("\n");
    visit[t]=1;
    flag=0;
    DFS(0);
    printf("\n");
    memset(visit,0,sizeof(visit));
    visit[t]=1;
    flag=0;
    BFS(0);
    printf("\n");
    return 0;
}

