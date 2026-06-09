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

int Q[101],rear,front;
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
        prev->next=e; // @@ [Error: When p is NULL (i.e., v2 is larger than all existing nodes), prev points to the last node, but the code does not handle the case where prev is NULL (should not happen here because the else branch implies at least one node exists). However, the main issue is that if p is NULL after the loop, prev->next = e is correct, but e->next = p (which is NULL) is set below, so it works. The real error is that the insertion logic is flawed: when v2 is greater than all existing nodes, the loop ends with p == NULL, and prev points to the last node. Then prev->next = e and e->next = p (NULL) is correct. But if v2 should be inserted in the middle, the code works. However, there is a subtle bug: if the list has only one node and v2 is greater than that node, the loop runs once, p becomes NULL, prev points to the only node, and the insertion works. But if the list has multiple nodes and v2 is less than the first node, the if branch handles it. So the insertion logic is actually correct for ascending order. The error is elsewhere.]
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
    if(G[v].link!=NULL) // @@ [Error: This condition incorrectly skips printing vertex v if it has no adjacent edges (i.e., isolated vertex). According to the problem, the graph is connected before and after deletion, but after deletion, vertex 0 might become isolated if it was only connected to the deleted vertex. The traversal should still print vertex 0 even if it has no neighbors. The condition should be removed or changed to always print the vertex.]
    printf("%d ",v);
    for(p=G[v].link;p!=NULL;p=p->next)
        if(!visited[p->adjvex])
          DFS(G,p->adjvex);
}
void travelDFS(VLink G[],int n){
    int i;
    for(i=0;i<n;i++) visited[i]=0;
    for(i=0;i<n;i++)
        if(!visited[i]) DFS(G,i);
}
void BFS(VLink G[],int v){
    ELink* p;
    visited[v]=1;
    enQueue(v);
    while(!emptyQ()){
        v=deQueue();
        if(G[v].link!=NULL) // @@ [Error: Same issue as in DFS. This condition skips printing vertex v if it has no adjacent edges. Should always print the vertex when it is dequeued.]
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
    for(i=0;i<n;i++)
        if(!visited[i]) BFS(G,i);
}


int main(){
    scanf("%d%d",&nv,&ne);
    int v1,v2;
    for(int i=0;i<ne;i++){
        scanf("%d%d",&v1,&v2);
        add(v1,v2),add(v2,v1);
    }
    printf("\n%d\n",G[1].link->next->next->adjvex); // @@ [Error: This line is a debugging print that should be removed. It assumes G[1].link has at least three nodes, which may not be true for all test cases, causing undefined behavior or crashes.]
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