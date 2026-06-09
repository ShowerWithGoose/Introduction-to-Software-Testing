#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int e[200][200];
int n,m;
int deletePoint;
int vis[200];
int queue[200];
int head,tail;
void init(){
    memset(vis,0,200*sizeof(int));
    memset(queue,0,200*sizeof(int));
    head=tail=0;
}
void dfs(int s){
    vis[s]=1;
    printf("%d ",s);
    for(int i=0;i<n;i++){
        if(!vis[i]&&e[s][i]){
            dfs(i);
        }
    }
}

void bfs(){
    queue[tail++]=0;
    vis[0]=1;
    printf("0 ");
    while(head<tail){
        int s=queue[head++];
        for(int i=0;i<n;i++){
            if(!vis[i]&&e[s][i]){
                vis[i]=1;
                printf("%d ",i);
                queue[tail++]=i;
            }
        }
    }
}
int main(void){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    scanf("%d%d",&n,&m);
    int a,b;
    for(int i=1;i<=m;i++){
        scanf("%d%d",&a,&b);
        e[a][b]=e[b][a]=1;
    }
    scanf("%d",&deletePoint);

    init();
    dfs(0);
    printf("\n");

    init();
    bfs();
    printf("\n");
    
    for(int i=0;i<n;i++){
        e[i][deletePoint]=e[deletePoint][i]=0;
    }

    init();
    dfs(0);
    printf("\n");

    init();
    bfs();
    return 0;
}
