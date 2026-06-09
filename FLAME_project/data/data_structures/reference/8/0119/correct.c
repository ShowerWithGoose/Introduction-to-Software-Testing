#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MaxV 200

typedef struct edge{
    int adjvex;
    struct edge *next;
}ELink;
typedef struct ver{
    int vertex;
    ELink *link;
}VLink;

VLink G[MaxV];
int Q[MaxV];
int visited[MaxV]={0};
int rear=-1,front=0,count=0;

ELink *insertEdge(ELink *head,int avex);
void travelDFS(int n,int de);
void DFS(int v);
void travelBFS(int n,int de);
void BFS(int v);
void enQueue(int v);
int deQueue();
int emptyQ();


int main(){
    int v_num,e_num,de_v;
    int v1,v2;
    int i,j;
    scanf("%d %d",&v_num,&e_num);
    for(i=0;i<e_num;i++){
        scanf("%d %d\n",&v1,&v2);
        G[v1].vertex=v1;
        G[v2].vertex=v2;
        G[v1].link= insertEdge(G[v1].link,v2);
        G[v2].link= insertEdge(G[v2].link,v1);
    }
    scanf("%d",&de_v);
   // printf("%d",G[1].link->next->adjvex);
    travelDFS(v_num,EOF);
    printf("\n");
    travelBFS(v_num,EOF);
    printf("\n");
    travelDFS(v_num,de_v);
    printf("\n");
    travelBFS(v_num,de_v);
    return 0;

}

ELink *insertEdge(ELink *head,int avex){
    ELink *e,*p,*s;
    e=(ELink*) malloc(sizeof(ELink));
    e->adjvex=avex;
    e->next=NULL;
    if(head==NULL){
        head=e;
        return head;
    }
    else{
        if(e->adjvex<head->adjvex){
            e->next=head;
            head=e;
            return head;
        }
        for(s=p=head;p!=NULL;s=p,p=p->next){
            if(e->adjvex<p->adjvex){
                s->next=e;
                e->next=p;
                return head;
            }
        }
        s->next=e;
    }
    return head;
}
void travelDFS(int n,int de){
    int i;
    for(i=0;i<n;i++) visited[i]=0;
    if(de!=EOF) visited[de]=1;
    for(i=0;i<n;i++){
        if(!visited[i]) DFS(i);
    }
}
void DFS(int v){
    ELink *p;
    visited[v]=1;
    printf("%d ",G[v].vertex);
    for(p=G[v].link;p!=NULL;p=p->next){
        if(!visited[p->adjvex])
            DFS(p->adjvex);
    }
}
void travelBFS(int n,int de){
    int i;
    for(i=0;i<n;i++) visited[i]=0;
    if(de!=EOF) visited[de]=1;
    for(i=0;i<n;i++){
        if(!visited[i]) BFS(i);
    }
}
void BFS(int v){
    ELink *p;
    printf("%d ",G[v].vertex);
    visited[v]=1;
    enQueue(v);
    while (!emptyQ()){
        v=deQueue();
        p=G[v].link;
        for(;p!=NULL;p=p->next){
            if(!visited[p->adjvex]){
                printf("%d ",G[p->adjvex].vertex);
                visited[p->adjvex]=1;
                enQueue(p->adjvex);
            }
        }
    }

}
void enQueue(int v){
    if(rear==MaxV-1) {
        printf("Full Error!");
        exit(1);
    }
    else {
        count++;
        Q[++rear]=v;
    }
}
int deQueue(){
    if(emptyQ()==1){
        printf("Empty Error!");
        return EOF;
    }
    else{
        count--;
    }
    return Q[front++];
}
int emptyQ(){
    if(count==0) return 1;
    return 0;
}
