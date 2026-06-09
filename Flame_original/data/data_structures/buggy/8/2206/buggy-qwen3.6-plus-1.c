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
    for(int i=0; i<n; i++) { // @@ Incorrectly prints adjacency list instead of performing DFS traversal before deletion
        printf("%d ",i); // @@ Incorrectly prints adjacency list instead of performing DFS traversal before deletion
        for(Nodeptr q=point[i]; q!=NULL; q=q->link ) { // @@ Incorrectly prints adjacency list instead of performing DFS traversal before deletion
            printf("%d ",q->x ); // @@ Incorrectly prints adjacency list instead of performing DFS traversal before deletion
        } // @@ Incorrectly prints adjacency list instead of performing DFS traversal before deletion
        printf("\n"); // @@ Incorrectly prints adjacency list instead of performing DFS traversal before deletion
    } // @@ Incorrectly prints adjacency list instead of performing DFS traversal before deletion
    scanf("%d",&k);
    Dpr(101);
    printf("\n");
    Bpr(101);
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
            for(Nodeptr p=point[a]; p!=NULL&&p->x<b; p=p->link) // @@ Variable r is used uninitialized if the loop condition is initially false, leading to undefined behavior
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
    visit[k]=1;
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
    visit[k]=1;
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
    queue[r++]=i; // @@ Global queue indices l and r are not reset to 0 before each BFS traversal, causing subsequent BFS calls to fail
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