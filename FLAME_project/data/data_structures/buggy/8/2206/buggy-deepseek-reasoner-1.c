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
    for(int i=0; i<n; i++) { @@ This loop prints adjacency lists, which is not required by the problem and causes extra output.
        printf("%d ",i); @@ This line contributes to the unintended debug output.
        for(Nodeptr q=point[i]; q!=NULL; q=q->link ) { @@ This inner loop prints neighbors, not part of the required output.
            printf("%d ",q->x ); @@ This line prints neighbor numbers, leading to extra lines in output.
        }
        printf("\n"); @@ This line prints a newline, adding to the extraneous output.
    }
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
    Nodeptr q,r; @@ Variable `r` is not initialized; it may be used uninitialized in the else branch if the for loop does not execute.
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
            for(Nodeptr p=point[a]; p!=NULL&&p->x<b; p=p->link) @@ If the list contains a node with x equal to b (duplicate edge) or b is greater but the first node's x is also greater? Actually, if b is greater than the first node, the loop will execute at least once. However, if b is exactly equal to some node’s x, the loop condition `p->x < b` fails immediately, so `r` remains uninitialized. Although duplicate edges are not given, this is a latent bug.
                r=p;
            q->link =r->link ; @@ `r` may be uninitialized if the for loop did not execute, leading to undefined behavior.
            r->link =q; @@ Same as above; use of uninitialized `r`.
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