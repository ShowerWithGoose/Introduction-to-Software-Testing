#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define LL long long
#define DB double
#define FOR(X,Y,Z)  for(int X = Y;X<Z;X++)  、
#define MaxV 256
typedef struct edge{ //边
    int adj;
    
    struct edge *next;
}Elink;
typedef struct ver{ //顶点
    Elink *link;
}Vlink;
Vlink G[MaxV];
int v[MaxV];
Elink *insertEdge(Elink *head, int avex){
    Elink *e,*p;
    e =(Elink *)malloc(sizeof(Elink));
    e->adj= avex; e->next = NULL;
    if(head == NULL) { 
        head=e; 
        return head; 
    }
    if(head->adj>e->adj){
        e->next = head;
        return e;
    }
    else{
    for(p=head;p->next != NULL; p=p->next){
        if(p->next!=NULL&&p->next->adj > e->adj)
        break;
    }
    e->next = p->next;
    p->next = e; 
    return head;
    }
}
void createGraph(int En,Vlink g[]){
    int i,v1,v2;
    for(i = 0;i<En;i++){
        scanf("%d %d ",&v1,&v2);
        g[v1].link = insertEdge(g[v1].link,v2);
        g[v2].link = insertEdge(g[v2].link,v1);
    }
}
void delvex(Vlink g[],int v,int max){
    g[v].link = NULL;
    int i;
    for(i = 0;i<max;i++){
        Elink* p = g[i].link;
        if(p==NULL) continue;
        if(p->adj==v){
            g[i].link = p->next;
        }
        else{
            for(;p->next!=NULL;p = p->next){
                if(p->next->adj == v){
                p->next = p->next->next;
                break;
             }
            }   
        }
    }
}
int Visited[MaxV];
int queue[MaxV],front = 0,rear = MaxV - 1,cnt = 0;
void enQ(int q[],int a){
    rear = (rear+1)%MaxV;
    q[rear] = a;
    cnt++;
}
int deQ(int q[]){
    if(cnt!=0){
    int e = q[front];
    front = (front+1)%MaxV;
    cnt--;
    return e;
    }
    else{
        printf("ERROR!\n");
        return -1;
    }
}
void BFS(Vlink g[],int v){
    int i;
    for(i=0; i<MaxV; i++) 
    Visited[i] = 0 ;
    Elink* p;
    printf("%d ",v);
    Visited[v] = 1;
    enQ(queue,v);
    while(cnt!=0){
        v = deQ(queue);
        p = g[v].link;
        for(;p!=NULL;p = p->next){
            if(!Visited[p->adj]){
                printf("%d ",p->adj);
                Visited[p->adj] = 1;
                enQ(queue,p->adj);
            }
        }
    }
    printf("\n");
}
void DFS(Vlink g[],int v){
    int i;
    Elink *p;
    printf("%d ",v);
    Visited[v] = 1;
    for(p = g[v].link; p !=NULL; p=p->next)
    if( !Visited[p->adj] )
    DFS(g, p->adj);
}
void G_DFS(Vlink g[],int v){
    int i;
    for(i=0; i<MaxV; i++) 
    Visited[i] = 0;
    DFS(g,v);
    printf("\n");
}
int main(){
    //freopen(".in","r",stdin);
    int vn,en;
    scanf("%d %d ",&vn,&en);
    createGraph(en,G);
    
   /* for(int i = 0;i<10;i++){
        Elink* p = G[i].link;
        if(p!=NULL)
        printf("ver %d:",i);
        while(p!=NULL){
            printf("%d ",p->adj);
            p = p->next;
        }
        putchar('\n');
    }*/
    G_DFS(G,0);
    BFS(G,0);
    int del;
    scanf("%d ",&del);
    delvex(G,del,vn);
    G_DFS(G,0);
    BFS(G,0);
    
    return 0;
}
