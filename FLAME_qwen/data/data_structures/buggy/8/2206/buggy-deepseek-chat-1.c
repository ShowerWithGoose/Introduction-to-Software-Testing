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
    Dpr(101); // @@ [Error: The function Dpr is called with argument 101, but the vertex numbers range from 0 to n-1 (n ≤ 100). Using 101 as a "deleted" marker is incorrect because it does not correspond to any vertex. The intended logic should mark vertex k as visited before traversal to exclude it, but here 101 is out of bounds and will cause undefined behavior when used as an index in the visit array.]
    printf("\n");
    Bpr(101); // @@ [Error: Same issue as above; Bpr is called with 101 instead of the actual vertex to delete. This will cause incorrect traversal behavior.]
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
    visit[k]=1; // @@ [Error: When k is 101 (from the first call), this line accesses visit[101], which is out of bounds (visit array size is 105, but valid indices are 0-104; however, the problem's vertex range is 0-99, so 101 is invalid and may cause undefined behavior. Additionally, the logic should mark the vertex to be deleted as visited to exclude it from traversal, but using 101 is incorrect.]
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
    visit[k]=1; // @@ [Error: Same out-of-bounds issue as in Dpr when k is 101.]
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