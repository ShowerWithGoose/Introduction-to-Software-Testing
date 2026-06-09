#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct  edge{ 
    int adjvex;
    //int weight;
    struct edge *next;
}Elink;
typedef struct ver{
    int vertex;
    Elink *link;
}Vlink;
Vlink g[100];
Elink* insertedge(Elink *head,int avex);
void deleteVex(int v,int vnum);
void DFS(Vlink Gragh[],int v);
void BFS(Vlink Gragh[],int v);
int visited[100] = {0};
int Q[100],front = 0,rear = -1;
int main(){
    int nv,ne,v1,v2,delete_v;
    scanf("%d%d",&nv,&ne);
    for(int i = 0;i<ne;i++){
        scanf("%d%d",&v1,&v2);
        g[v1].link = insertedge(g[v1].link,v2);
        g[v2].link = insertedge(g[v2].link,v1);
    }
    scanf("%d",&delete_v);
    for(int i = 0;i<nv;i++){
        if(!visited[i]) DFS(g,i);
    }
    printf("\n");
    for(int i = 0;i<nv;i++){
        visited[i] = 0;
    }
    for(int i = 0;i<nv;i++){
        if(!visited[i]) BFS(g,i);
    }
    printf("\n");
    deleteVex(delete_v,nv);
    for(int i = 0;i<nv;i++){
        visited[i] = 0;
    }
    visited[delete_v] = 1;
    for(int i = 0;i<nv;i++){
        if(!visited[i]) DFS(g,i);
    }
    printf("\n");
    for(int i = 0;i<nv;i++){
        visited[i] = 0;
    }
    visited[delete_v] = 1;
    rear = -1,front = 0;
    for(int i = 0;i<nv;i++){
        if(!visited[i]) BFS(g,i);
    }
    system("pause");
    return 0;
}
Elink* insertedge(Elink *head,int avex){
    Elink *p = (Elink*)malloc(sizeof(Elink));
    p->adjvex = avex,p->next = NULL;
    Elink *q = head;
    if(head == NULL) head = p;
    else if(head->adjvex > avex){
        p->next = head;
        head = p;
    }
    //else if(head->next == NULL) head->next = p;
    else{
        while(q->next != NULL && q->next->adjvex < avex){
            q = q->next;
        }
        p->next = q->next;
        q->next = p;
        //while(q->next != NULL) q = q->next;
        //q->next = p;
    }
    return head;
}
void deleteVex(int v,int vnum){
    g[v].link = NULL;
    for(int i = 0;i<vnum;i++){
        Elink *p = g[i].link,*q = NULL;
        if(p == NULL) continue;
        if(p->adjvex == v){
            g[i].link = p->next;
        }
        else{
            while(p != NULL){
            if(p->adjvex == v){
                q->next = p->next;
            }
            q = p,p = p->next;
            }
        }
    }
}
void DFS(Vlink Gragh[],int v){
    Elink *p;
    if(v == 0) printf("%d",v);
    else printf(" %d",v);
    visited[v] = 1;
    for(p = Gragh[v].link;p != NULL;p = p->next){
        if(!visited[p->adjvex]) DFS(Gragh,p->adjvex);
    }
    return;
}
void BFS(Vlink Gragh[],int v){
    Elink *p;
    if(v == 0) printf("%d",v);
    else printf(" %d",v);
    visited[v] = 1;
    Q[++rear] = v;
    while(rear >= front){
        v = Q[front++];
        p = g[v].link;
        for(;p != NULL;p = p->next){
            if(!visited[p->adjvex]){
                printf(" %d",p->adjvex);
                visited[p->adjvex] = 1;
                Q[++rear] = p->adjvex;
            }
        }
    }
    return;
}

