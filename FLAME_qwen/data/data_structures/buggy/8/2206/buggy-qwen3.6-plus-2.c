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
    for(int i=0; i<n; i++) { // @@ [This loop prints the adjacency list, which is not part of the required output format and will cause a Wrong Answer.]
        printf("%d ",i);
        for(Nodeptr q=point[i]; q!=NULL; q=q->link ) {
            printf("%d ",q->x );
        }
        printf("\n");
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
    visit[k]=1;
    for(int i=0; i<n; i++) {
        if(visit[i]==0) {
            Dfs(i);
        }
    }
}
void Bpr(int k) {
    for(int i=0; i<n; i++) {
        visit[i]=0;
    }
    visit[k]=1; // @@ [Global queue pointers l and r are not reset to 0 before BFS traversal. They retain values from previous calls, leading to incorrect queue operations and potential out-of-bounds array access.]
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