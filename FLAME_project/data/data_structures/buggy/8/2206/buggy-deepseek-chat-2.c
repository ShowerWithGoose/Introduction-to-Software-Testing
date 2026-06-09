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
    Dpr(101); // @@ [Error: The parameter 101 is used as a vertex index, but valid vertices are 0 to n-1. This causes visit[101] to be out-of-bounds and incorrectly marks a non-existent vertex as visited, leading to wrong traversal output.]
    printf("\n");
    Bpr(101); // @@ [Error: Same issue as Dpr(101); using 101 as a vertex index is invalid and causes out-of-bounds access and incorrect traversal.]
    printf("\n");
    Dpr(k); // @@ [Error: The function Dpr(k) marks visit[k]=1 before traversing, which skips vertex k entirely instead of deleting it. The correct approach is to remove vertex k from the graph structure, not just mark it visited.]
    printf("\n");
    Bpr(k); // @@ [Error: Same issue as Dpr(k); marking visit[k]=1 skips vertex k instead of properly deleting it from the graph.]
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
    visit[k]=1; // @@ [Error: This marks vertex k as visited, effectively skipping it in traversal. For deletion, the vertex should be removed from the adjacency lists, not just marked visited.]
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
    visit[k]=1; // @@ [Error: Same issue as in Dpr; marking vertex k as visited skips it instead of deleting it.]
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