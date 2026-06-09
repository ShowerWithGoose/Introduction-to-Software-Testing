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
    Dpr(101); // @@ [Calling Dpr(101) passes an invalid vertex index (101), which is out of the valid range [0, n-1]. This causes undefined behavior and incorrect traversal output. Should call Dpr(k) only after printing initial traversals. Also, initial DFS/BFS before deletion is missing.]
    printf("\n");
    Bpr(101); // @@ [Same issue as above: passing 101 to Bpr leads to marking an invalid vertex as visited, breaking the traversal logic. The program should first perform DFS and BFS on the original graph (without deleting any vertex), but instead it tries to traverse with an invalid deleted vertex.]
    printf("\n");
    Dpr(k);
    printf("\n");
    Bpr(k);
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
    visit[k]=1; // @@ [If k >= n (e.g., k=101), this writes beyond the bounds of the visit array (size 105, but n <= 100). However, more critically, when k is a valid vertex to delete (as per problem), this marks it visited so it's skipped. But in the first two calls (Dpr(101), Bpr(101)), k=101 is invalid and corrupts memory or logic.]
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
    visit[k]=1; // @@ [Same as in Dpr: when k=101, this accesses visit[101], which is within allocated size (105) but logically wrong because vertex 101 doesn't exist. This breaks the intended traversal by incorrectly skipping non-existent vertex and not starting from 0 as required.]
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