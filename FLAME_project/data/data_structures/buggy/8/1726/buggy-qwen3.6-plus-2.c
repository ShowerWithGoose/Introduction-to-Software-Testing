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
        prev->next=e; // @@ Potential Runtime Error: If the new vertex is larger than all existing neighbors, 'prev' might remain NULL if the list was empty (handled above) or if logic fails. However, the main issue here is that if p becomes NULL immediately (list empty), it's handled. But if p is not NULL and loop doesn't run, prev is NULL. Wait, if G[v1].link is not NULL and v2 >= head->adjvex, we enter else. If v2 > all, p becomes NULL, prev is last node. Correct. If v2 < head, handled in if. So this logic is mostly okay for insertion, BUT:
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
    if(G[v].link!=NULL) // @@ Logical Error: The problem requires printing the vertex if it is visited/reached. Even if a vertex has no edges (isolated after deletion, though problem says connected, but specifically vertex 0 starts traversal), it should be printed if it's part of the traversal. More importantly, the condition `G[v].link!=NULL` prevents printing vertices that have become isolated or are leaf nodes if implemented incorrectly? No, leaf nodes have links. But if a vertex is isolated (degree 0), it won't print. In the "after deletion" case, if the graph remains connected, every node has degree >= 1 except possibly if n=1? No, n>=3. However, the standard DFS prints the node when visited. The condition `if(G[v].link!=NULL)` is incorrect because it suppresses output for vertices with no neighbors. While the problem states the graph is connected, if we delete a vertex, the remaining graph is connected. But vertex 0 might have neighbors. The real issue is that `printf` should happen unconditionally upon visiting `v`, not dependent on whether it has outgoing edges.
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
        if(G[v].link!=NULL) // @@ Logical Error: Same as DFS. The vertex should be printed when it is dequeued/visited, regardless of whether it has adjacent vertices. The condition `G[v].link!=NULL` incorrectly suppresses output for vertices with no neighbors (degree 0). Although the graph is connected, this is semantically wrong for a general traversal implementation and might fail if specific structural assumptions change or if the start node has no edges (unlikely here but bad practice). More critically, in the provided test case, this might not trigger if all nodes have edges, but it's a logical bug.
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
    printf("\n%d\n",G[1].link->next->next->adjvex); // @@ Runtime Error: This line accesses `G[1].link->next->next`. Depending on the graph structure, `G[1].link` or its `next` might be NULL, causing a segmentation fault. Also, this output is not required by the problem description and corrupts the expected output format. It should be removed or commented out.
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