#include <stdio.h>
#include <stdlib.h>
int nv,ne;
typedef struct edge{
    int  adjvex;
    struct edge* next;
 }ELink;
typedef struct ver{
    ELink* link;
}VLink;
VLink G[101];

int Q[101],rear,front; // @@ Queue size is too small for multiple traversals without resetting indices. With n up to 100 and two traversals, indices can exceed array bounds.
void enQueue(int v){
    Q[rear++]=v;
}
int emptyQ(){
    return rear==front;
}
int deQueue(){
    if(emptyQ()){
        return -1;
    }
    return Q[front++];
}

void add(int v1,int v2){
    ELink *e;
    e=(ELink *)malloc(sizeof(ELink));
    e->adjvex=v2,e->next=NULL;
    if(G[v1].link==NULL||v2<G[v1].link->adjvex){
        e->next=G[v1].link;
        G[v1].link=e;
    }
    else{
        ELink *p=G[v1].link,*prev=NULL;
        while(p!=NULL&&p->adjvex<v2){
            prev=p;
            p=p->next;
        }
        prev->next=e;
        e->next=p; 
    }
    
}
void dele(int v){
    ELink *p=G[v].link;
    while(p!=NULL){
        ELink* next=p->next;
        free(p);
        p=next;
    }
    G[v].link=NULL;
    for (int i = 0; i < nv; i++) {
    if (i != v && G[i].link != NULL) {
       ELink* prev = NULL;
        p = G[i].link;
        while (p != NULL) {
            if (p->adjvex == v) {
                if (prev != NULL) {
                    prev->next = p->next;
                } else {
                    G[i].link = p->next;
                }
                free(p);
                break;
            }
            prev = p;
            p = p->next;
        }
    }
    }
}
int visited[101]={0};
void DFS(VLink G[],int v){
    ELink *p;
    visited[v]=1;
    if(G[v].link!=NULL) // @@ Unnecessary condition; the reference program prints the vertex unconditionally. This may skip printing a vertex that should be visited.
    printf("%d ",v);
    for(p=G[v].link;p!=NULL;p=p->next)
        if(!visited[p->adjvex])
          DFS(G,p->adjvex);
}
void travelDFS(VLink G[],int n){
    int i;
    for(i=0;i<n;i++) visited[i]=0;
    for(i=0;i<n;i++) // @@ Should start traversal from vertex 0 only, as per problem specification. Looping over all vertices is incorrect.
        if(!visited[i]) DFS(G,i);
}
void BFS(VLink G[],int v){
    ELink* p;
    visited[v]=1;
    enQueue(v);
    while(!emptyQ()){
        v=deQueue();
        if(G[v].link!=NULL) // @@ Unnecessary condition; same issue as in DFS.
        printf("%d ",v);
        for(p=G[v].link;p!=NULL;p=p->next)
          if(!visited[p->adjvex]){
              visited[p->adjvex]=1;
              enQueue(p->adjvex);
          }
    }
}
void travelBFS(VLink G[],int n){
    int i;
    for(i=0;i<n;i++) visited[i]=0;
    for(i=0;i<n;i++) // @@ Should start traversal from vertex 0 only, as per problem specification.
        if(!visited[i]) BFS(G,i);
}


int main(){
    scanf("%d%d",&nv,&ne);
    int v1,v2;
    for(int i=0;i<ne;i++){
        scanf("%d%d",&v1,&v2);
        add(v1,v2),add(v2,v1);
    }
    printf("\n%d\n",G[1].link->next->next->adjvex); // @@ Debug line produces extra output and may cause undefined behavior if the adjacency list is too short.
    travelDFS(G,nv);
    printf("\n");
    travelBFS(G,nv);
    printf("\n");
    int v;
    scanf("%d",&v);
    dele(v);
    travelDFS(G,nv);
    printf("\n");
    travelBFS(G,nv);
    printf("\n");
    
    return 0;
}