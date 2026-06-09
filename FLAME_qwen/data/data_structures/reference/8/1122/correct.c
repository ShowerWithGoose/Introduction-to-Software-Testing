#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define M 100
typedef struct edge{
    int knot;
    
    struct edge *nextknot;
}Elink;
int visited[M];
Elink *G[M];
Elink memory[100000];
int a=0;
void DFS(int v){
    int w;
    visited[v]=1;
    printf("%d ",v);
    Elink *p=G[v];
    w=p->knot;
    while(w!=-1){
        if(p->nextknot==NULL){
            w=-1;
            
        }
        else{
            w=p->nextknot->knot;
            if(visited[w]==0){
                DFS(w);
            }
            p=p->nextknot;
        }
    }
    
}
int q[10000];
int f=-1,l=-1;
void add_q(int w){
    q[++l]=w;
}
int del_q(void){
    return(q[++f]);
}
void BFS(int v){
    int w;
    add_q(v);
    while(l!=f){
        v=del_q();
        if(visited[v]==0){
            printf("%d ",v);
        }
        visited[v]=1;
        Elink *p=G[v];
        w=p->knot;
        while(w!=-1){
            if(p->nextknot==NULL){
                w=-1;
                
            }
            else{
                w=p->nextknot->knot;
                if(visited[w]==0){
                   add_q(w);
                }
                p=p->nextknot;
            }
            
        }
    }
}
void init(int n){
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
}
void del(int v,int n){
    G[v]->knot=-1;
    G[v]->nextknot=NULL;
    for(int i=0;i<n;i++){
        if(i!=v){
            Elink *p=G[i];
            while(p!=NULL&&p->nextknot!=NULL){
                if(p->nextknot->knot==v){
                    p->nextknot=p->nextknot->nextknot;
                }
                p=p->nextknot;
            }
        }
    }
}

int main(){
    int delete;
    int n,p;
    scanf("%d %d",&n,&p);
    for(int i=0;i<n;i++){
        G[i]=&memory[a++];
        G[i]->knot=i;
        G[i]->nextknot=NULL;
    }
    for(int i=0;i<p;i++){
        int v1,v2;
        scanf("%d %d",&v1,&v2);
        Elink *p=G[v1];
        while(p->nextknot!=NULL&&p->nextknot->knot<v2){
            p=p->nextknot;
        }
        Elink *q=&memory[a++];
        q->knot=v2;
        q->nextknot=NULL;
        
        if(p->nextknot==NULL){
            p->nextknot=q;
        }
        else{
            Elink *k=p->nextknot;
            p->nextknot=q;
            q->nextknot=k;
        }
        p=G[v2];
        while(p->nextknot!=NULL&&p->nextknot->knot<v1){
            p=p->nextknot;
        }
        q=&memory[a++];
        q->knot=v1;
        q->nextknot=NULL;
        
        if(p->nextknot==NULL){
            p->nextknot=q;
        }
        else{
            Elink *k=p->nextknot;
            p->nextknot=q;
            q->nextknot=k;
        }
    }
    scanf("%d",&delete);
    DFS(0);
    printf("\n");
    init(n);
    BFS(0);
    printf("\n");
    init(n);
    del(delete,n);
    DFS(0);
    printf("\n");
    init(n);
    BFS(0);
    printf("\n");
    return 0;
}
