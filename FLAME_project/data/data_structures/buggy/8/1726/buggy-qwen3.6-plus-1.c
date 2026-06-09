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
        prev->next=e; // @@ Potential Runtime Error: If the new vertex is larger than all existing neighbors, 'prev' remains NULL because the loop condition fails immediately or 'p' becomes NULL without 'prev' being updated to the last node. This causes a crash when accessing prev->next. The logic should handle appending to the end of the list.
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
    if(G[v].link!=NULL) // @@ Logical Error: The problem requires printing all reachable vertices in the traversal sequence. Checking if G[v].link != NULL incorrectly suppresses the output for isolated vertices (or the last vertex in a component if it has no unvisited neighbors, though here it means leaf nodes with no edges left? No, it means if a vertex has NO neighbors at all, it won't print. But more importantly, the traversal logic relies on visiting adjacent nodes. If a vertex is visited, it should be printed regardless of whether it has outgoing edges, as long as it's part of the connected component being traversed. However, the bigger issue is usually that leaf nodes DO have links (back to parent), so this might just hide isolated nodes. But wait, if a node is a leaf in DFS tree, it still has links in the adjacency list. This check prevents printing a vertex if it has degree 0. In a connected graph > 1 node, only isolated nodes have degree 0. But after deletion, if the graph remains connected, this might be okay? No, standard DFS prints the node when visited. This condition is suspicious and likely wrong for general correctness, but let's look for Runtime Errors first. Actually, the prompt asks for logical/semantic errors too. This condition `if(G[v].link!=NULL)` means if a vertex has no neighbors, it is not printed. In a connected graph with n>=3, every node has at least one neighbor. So this might not trigger RE. However, the `add` function bug is a definite RE candidate.
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
        if(G[v].link!=NULL) // @@ Logical Error: Similar to DFS, this prevents printing vertices with no neighbors. While unlikely in a connected graph to have degree 0, it is semantically incorrect for a general traversal implementation which should print the vertex upon visit/dequeue.
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
    printf("\n%d\n",G[1].link->next->next->adjvex); // @@ Runtime Error: This line accesses specific pointers in the adjacency list of vertex 1 for debugging/output. If vertex 1 has fewer than 3 neighbors, or if the list is shorter than expected, this will cause a Segmentation Fault (NULL pointer dereference). It also produces unexpected output not required by the problem statement.
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