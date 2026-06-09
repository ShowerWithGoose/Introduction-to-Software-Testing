#include <stdio.h>
#include <stdlib.h>
#define MAXQ 100
int Q[MAXQ];
int front=-1,end=-1,nq=0;
int ADDQ(int v);
int DELQ();
typedef struct edge{
    int adjvex;
    struct edge *next;
}Elink;
typedef struct ver{
    int exF;
    Elink *link;
}Vlink;
void InitG(Vlink *G,int nv);
void DFS(Vlink G[],int v,int visited[]);
void TRAVEL_DFS(Vlink G[],int visited[],int n);
void BFS(Vlink G[],int v,int visted[]);
void TRAVEL_BFS(Vlink G[],int visited[],int n);
int EMPTYQ(){
    return nq==0;
}
int main() {
    int nv,ne;
    scanf("%d %d",&nv,&ne);
    int visited[nv];
    Vlink G[nv];
    InitG(G,nv);
    for(int i=0;i<ne;i++){
        int p,q;
        scanf("%d %d",&p,&q);
        Elink *ep=(Elink*)malloc(sizeof(Elink));
        ep->adjvex=q;
        ep->next=NULL;
        if(G[p].link==NULL){
            G[p].link=ep;
        }
        else if(q<G[p].link->adjvex){
            ep->next=G[p].link;
            G[p].link=ep;
        }
        else {
            Elink *pp = G[p].link;
            while (pp->next != NULL) {
                if(q>pp->adjvex&&q<pp->next->adjvex)break;
                pp = pp->next;
            }
            ep->next=pp->next;
            pp->next=ep;
        }
        Elink *eq=(Elink*)malloc(sizeof(Elink));
        eq->adjvex=p;
        eq->next=NULL;
        if(G[q].link==NULL){
            G[q].link=eq;
        }
        else if(p<G[q].link->adjvex){
            eq->next=G[q].link;
            G[q].link=eq;
        }
        else {
            Elink *qq = G[q].link;
            while (qq->next != NULL) {
                if(p>qq->adjvex&&p<qq->next->adjvex)break;
                qq = qq->next;
            }
            eq->next=qq->next;
            qq->next=eq;
        }
    }//邻接表图构建完成
//    for(int i=0;i<nv;i++){
//        if(G[i].link!=NULL){
//            printf("%d\n",G[i].link->adjvex);
//        }
//    }//输出最小边，初步检查图存储没问题
    int deNum;
    scanf("%d",&deNum);
    TRAVEL_DFS(G,visited,nv);
    TRAVEL_BFS(G,visited,nv);
    G[deNum].exF=0; // @@ The logic for "deleting" a vertex by setting a flag is flawed because the traversal functions still iterate based on the original vertex count `nv` and indices. More critically, the BFS function has a logical error that causes early termination. However, the primary issue causing the specific wrong output "0 2" vs "0 2" (wait, expected is 0 2, buggy is 0 2? No, expected last line is 0 2, buggy is 0. Let's look at BFS).
    // In the test case: Graph 0-1, 1-2, 0-2. Delete 1.
    // Remaining graph: 0-2.
    // DFS from 0: Visits 0. Neighbors of 0 are 1 (deleted) and 2.
    // The DFS implementation checks `if(G[v].exF==0)return;`.
    // When DFS(0) runs: prints 0. visited[0]=1.
    // Neighbor 1: G[1].exF is 0. So `if(G[w].exF==0)` in DFS? No, DFS doesn't check exF of neighbors explicitly in the loop, it calls DFS(w).
    // Inside DFS(1): `if(G[1].exF==0) return;`. So it returns immediately. Correct.
    // Next neighbor of 0 is 2. DFS(2) called. Prints 2. Returns.
    // So DFS output: "0 2 ". This matches expected "0 2".
    
    // Now BFS from 0 after deleting 1.
    // BFS(0): prints 0. visited[0]=1. ADDQ(0).
    // Queue not empty. v=DELQ() -> 0.
    // p=G[0].link. Assume sorted: 1, 2.
    // w=1. G[1].exF==0.
    // The code has: `if(G[w].exF==0)return;` inside the neighbor processing loop? 
    // Let's look at line 136: `if(G[w].exF==0)return;`. 
    // This is inside `if(p!=NULL){ w=p->adjvex; if(G[w].exF==0)return; }`.
    // This means if the *first* neighbor is deleted, the entire BFS function returns immediately.
    // It should `continue` to the next neighbor, not `return` from the function.
    TRAVEL_DFS(G,visited,nv);
    TRAVEL_BFS(G,visited,nv);
    return 0;
}
void InitG(Vlink *G,int nv){
    for(int i=0;i<nv;i++){
        G[i].link=NULL;
        G[i].exF=1;
    }
}
void DFS(Vlink G[],int v,int visited[]){
    if(G[v].exF==0)return;
    int w;
    printf("%d ",v);
    visited[v]=1;
    Elink *p=G[v].link;
    if(p!=NULL){
        w=p->adjvex;
    }
    else{
        w=-1;
    }
    while(w!=-1){
        if(visited[w]==0){
            DFS(G,w,visited);
        }
        p=p->next;
        if(p!=NULL){
            w=p->adjvex;
        }
        else{
            w=-1;
        }
    }
}
void TRAVEL_DFS(Vlink G[],int visited[],int n){
    int i;
    for( i=0;i<n;i++){
        visited[i]=0;
    }
    DFS(G,0,visited);
    printf("\n");
}
int ADDQ(int v){
    if(nq==0){
        nq++;
        front=end=0;
        Q[front]=v;
        return 0;
    }
    if(nq==MAXQ){
        printf("Q has been full!\n");
        return -1;
    }
    nq++;
    end=(end+1)%MAXQ;
    Q[end]=v;
    return 0;
}
int DELQ(){
    if(nq==0){
        printf("Q has been empty!\n");
        return -1;
    }
    nq--;
    int x=Q[front];
    front=(front+1)%MAXQ;
    return x;
}
void BFS(Vlink G[],int v,int visited[]){
    if(G[v].exF==0)return ;
    int w;
    printf("%d ",v);
    visited[v]=1;
    ADDQ(v);
    while(!EMPTYQ()){
        v=DELQ();
        Elink *p=G[v].link;
        if(p!=NULL){
            w=p->adjvex;
            if(G[w].exF==0)return; // @@ Error: If the current neighbor `w` is deleted (exF==0), the function returns immediately instead of skipping this neighbor and checking the next one. This causes incomplete traversal. It should be `continue` or logic to skip, but since it's inside a nested structure, simply returning is wrong. Specifically, this line terminates the BFS prematurely if a deleted node is encountered as a neighbor.
        }
        else{
            w=-1;
        }
        while(w!=-1){
            if(G[w].exF==1&&visited[w]==0){
                printf("%d ",w);
                ADDQ(w);
                visited[w]=1;
            }
            p=p->next;
            if(p!=NULL){

                w=p->adjvex;
            }
            else{
                w=-1;
            }
        }
    }
}
void TRAVEL_BFS(Vlink G[],int visited[],int n){
    int i;
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
            BFS(G,0,visited);
    printf("\n");
}