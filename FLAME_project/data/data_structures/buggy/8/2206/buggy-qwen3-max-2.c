#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
typedef struct _Node {
    int x;
    struct _Node* link;
} Node,*Nodeptr;
void operate(int,int);
void Dpr(int);
void Bpr(int);
void Dfs(int);
void Bfs(int);
Nodeptr point[105]= {NULL};
int n,m,l=0,r=0;
int visit[105]= {0};
int queue[105]= {0};
int main() {
    int a,b,k;
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++) {
        scanf("%d%d",&a,&b);
        operate(a,b);
        operate(b,a);
    }
    for(int i=0; i<n; i++) {
        printf("%d ",i);
        for(Nodeptr q=point[i]; q!=NULL; q=q->link ) {
            printf("%d ",q->x );
        }
        printf("\n");
    }
    scanf("%d",&k);
    Dpr(101); // @@ [Passing 101 as the vertex to delete is incorrect. The first two traversals should be on the original graph without deleting any vertex. Instead, Dpr and Bpr should start from vertex 0 and traverse the full graph. Marking visit[101]=1 has no effect since vertices are 0..n-1, but the real issue is that Dpr/Bpr are designed to skip a vertex k, which should not happen in the "before deletion" phase.]
    printf("\n");
    Bpr(101); // @@ [Same error as above: using 101 causes no vertex to be skipped (since 101 >= n), but the logic of Dpr/Bpr is flawed—they loop over all unvisited vertices and start DFS/BFS from each, which violates the requirement to always start from vertex 0 and traverse the entire connected graph in one go.]
    printf("\n");
    Dpr(k); // @@ [After deletion, Dpr(k) correctly skips vertex k, but because Dpr starts DFS from every unvisited vertex in order (not just 0), it may produce wrong output if the graph becomes disconnected—but the problem states it remains connected. However, the bigger issue is that Dpr doesn't start only from 0; it starts from the first unvisited vertex, which should be 0, but due to the loop structure, if 0 is visited, it might skip. But more critically, the traversal must start at 0 always, not iterate over all vertices.]
    printf("\n");
    Bpr(k); // @@ [Same issue as Dpr(k): Bpr loops over all vertices and starts BFS from each unvisited one, but the problem requires starting only from vertex 0. This leads to incorrect traversal sequences when the graph is connected (which it always is), because it should do a single DFS/BFS from 0, not multiple.]
    printf("\n");
    return 0;
}
void operate(int a,int b) {
    Nodeptr q,r;
    q=(Nodeptr)malloc(sizeof(Node));
    q->link =NULL;
    q->x =b;
    if(point[a]==NULL) {
        point[a]=q;
    } else {
        if(b<point[a]->x) {
            q->link =point[a];
            point[a]=q;
        } else {
            for(Nodeptr p=point[a]; p!=NULL&&p->x<b; p=p->link)
                r=p;
            q->link =r->link ;
            r->link =q;
        }
    }
}
void Dpr(int k) {
    for(int i=0; i<n; i++) {
        visit[i]=0;
    }
    visit[k]=1; // @@ [If k >= n (like 101), this writes out of bounds of the visit array (size 105, but n <= 100, so 101 is within array bounds but logically invalid). However, the main flaw is that Dpr is intended to skip vertex k, but for the "before deletion" case, no vertex should be skipped. More importantly, Dpr then iterates over all vertices and starts DFS from each unvisited one, violating the requirement to start only from vertex 0.]
    for(int i=0; i<n; i++) {
        if(visit[i]==0) {
            Dfs(i);
        }
    }
}
void Dfs(int i) {
    Nodeptr p;
    visit[i]=1;
    printf("%d ",i);
    for(p=point[i]; p!=NULL; p=p->link ) {
        if(visit[p->x]==0) {
            Dfs(p->x);
        }
    }
}
void Bpr(int k) {
    for(int i=0; i<n; i++) {
        visit[i]=0;
    }
    visit[k]=1; // @@ [Same as Dpr: marking visit[k]=1 to skip k is correct for after deletion, but for before deletion, k=101 is used which doesn't skip any real vertex. However, the core error is that Bpr loops over all vertices and starts BFS from each unvisited one, whereas the problem requires a single BFS starting from vertex 0.]
    for(int i=0; i<n; i++) {
        if(visit[i]==0) {
            Bfs(i);
        }
    }
}
void Bfs(int i) {
    Nodeptr p;
    visit[i]=1;
    printf("%d ",i);
    queue[r++]=i;
    while(l<r){
        int t=queue[l++];
        p=point[t];
        for(;p!=NULL;p=p->link ){
            if(visit[p->x]==0){
                visit[p->x]=1;
                printf("%d ",p->x);
                queue[r++]=p->x;
            }
        }
    }
}