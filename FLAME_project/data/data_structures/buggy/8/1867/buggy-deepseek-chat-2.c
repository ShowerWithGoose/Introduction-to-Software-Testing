#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
struct bian{
    int adj;
    struct bian *next;
}*p,*q;
struct dian{
    struct bian *link;
}G[110];
int n,m,d;
void travelDFS();
void DFS(int );
void travelBFS();
void BFS(int );
int a[110][110],visit[110],Q[110],front=0,rear=-1;

int main(){
    int i,j,k;
    for(i=0;i<100;i++){
        G[i].link=NULL;
    }
    scanf("%d%d",&n,&m);
    for(k=0;k<m;k++){
        scanf("%d%d",&i,&j);
        a[i][j]=1;
        a[j][i]=1;
    }
    scanf("%d",&d);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(a[i][j]==1){
                p=(struct bian*)malloc(sizeof(struct bian));
                if(G[i].link!=NULL){
                    q->next=p,q=p;
                }
                else{
                    G[i].link=p,q=p;    
                }
                p->adj=j,p->next=NULL;
            }
        }
    }
    for(i=0;i<n;i++){
        visit[i]=0;
    }
    travelDFS();
    printf("\n");
    for(i=0;i<n;i++){
        visit[i]=0;
    }
    travelBFS();
    printf("\n");
    for(i=0;i<n;i++){
        visit[i]=0;
    }
    visit[d]=1;
    travelDFS();
    printf("\n");
    for(i=0;i<n;i++){
        visit[i]=0;
    }
    visit[d]=1;
    travelBFS();
    
    return 0;
}

void travelDFS(){
    int i;
    for(i=0;i<n;i++){
        if(visit[i]==0){
            DFS(i);
        }
    }
}
void DFS(int x){
    struct bian *t;
    visit[x]=1;
    printf("%d ",x);
    for(t=G[x].link;t!=NULL;t=t->next){
        if(visit[t->adj]==0){
            DFS(t->adj);
        }
    }
    
}
void travelBFS(){
    int i;
    for(i=0;i<n;i++){
        if(visit[i]==0){
            BFS(i);
        }
    }
}
void BFS(int x){
    struct bian *t;
    visit[x]=1;
    printf("%d ",x);
    Q[++rear]=x;
    while(front<=rear){
        x=Q[front++];
        t=G[x].link;
        for(;t!=NULL;t=t->next){
            if(visit[t->adj]==0){
                printf("%d ",t->adj);
                visit[t->adj]=1;
                Q[++rear]=t->adj;
            }
        }
    }
}