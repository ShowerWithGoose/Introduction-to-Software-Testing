#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define max(a, b) ((a)>(b)? a : b)
int vis[101],delete[101];
int dian,bian;
struct graph{
    int vex[101];
    int arc[101][101];
};

void DFSG(struct graph *g,int n){
    if(vis[n]){
        return;
    }
    else{
        printf("%d ",n);
        vis[n]=1;
        for(int i=0;i<dian;i++){
            if(!vis[i]&&g->arc[n][i]){
                DFSG(g,i);
            }
        }
    }
}
void DFS(struct graph *g){
    memset(vis, 0, sizeof(vis));
    for(int i=0;i<dian;i++){
        if(!vis[i]&&delete[i]!=1){
            DFSG(g, i);
        }
    }
    printf("\n");
}
void BFS(struct graph *g){
    int Q[101*2], front = 0, rear = 0, qt;
    memset(vis, 0, sizeof(vis));
    for(int i=0;i<dian;i++){
        if(!vis[i]&&!delete[i]){
            printf("%d ",i);
            vis[i]=1;
            Q[++rear]=i;
            while(front != rear){
                qt = Q[++front];
                for(int j = 0;j<dian;j++){
                    if(!vis[j] && g->arc[qt][j]){
                        printf("%d ",j);
                        vis[j]=1;
                        Q[++rear]=j;
                    }
                }
            }
        }
    }
    printf("\n");
}
int main(){
    int a,b,shan;
    struct graph *g = (struct graph*)malloc(sizeof(struct graph));
    scanf("%d %d", &dian,&bian);
    for(int i=0;i<bian;i++){
        scanf("%d %d",&a,&b);
        g->arc[a][b]=1;
    	g->arc[b][a]=1;
    }
    scanf("%d", &shan);
    DFS(g);
    BFS(g);
    for(int i=0;i<dian;i++){
        g->arc[shan][i]=0;
        g->arc[i][shan]=0;
    }
    delete[shan]=1;
    DFS(g);
    BFS(g);
    return 0;
}

