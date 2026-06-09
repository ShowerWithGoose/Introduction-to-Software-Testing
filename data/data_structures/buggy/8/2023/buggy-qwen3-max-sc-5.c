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
void BFS(Vlink G[],int v,int visted[]); // @@ [Function declaration has typo in parameter name 'visted' instead of 'visited', causing mismatch with definition]
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
    G[deNum].exF=0;
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
void BFS(Vlink G[],int v,int visited[]){ // @@ [Function definition uses correct 'visited', but declaration had 'visted'; this mismatch causes compilation error]
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
            if(G[w].exF==0)return; // @@ [Early return here skips processing other adjacent nodes when one deleted node is encountered, breaking BFS logic]
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