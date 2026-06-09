#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct graph{
    int num;
    struct graph *next;
};
struct gra{
    struct graph *link;
};

struct gra point[120];
int flag[120]={0},que[120]={0},y=0;

void record(int a,int b){
    struct graph *p,*q,*r,*s;
    s=r=NULL;
    p=(struct graph *)malloc(sizeof(struct graph));
    p->num=a;p->next=NULL;
    q=(struct graph *)malloc(sizeof(struct graph));
    q->num=b;q->next=NULL;
    if(point[a].link==NULL){
        point[a].link=q;
    } 
    else{
        for(r=point[a].link;r!=NULL;s=r,r=r->next){
            if(b<r->num){
                q->next=r;
                if(s==NULL) point[a].link=q;
                else s->next=q;
                break;
            }
        }
        if(r==NULL) s->next=q;
    } 
    s=NULL;
    if(point[b].link==NULL){
        point[b].link=p;
    }
    else{
        for(r=point[b].link;r!=NULL;s=r,r=r->next){
            if(a<r->num){
                p->next=r;
                if(s==NULL) point[b].link=p;
                else s->next=p;
                break;
            }
        }
        if(r==NULL) s->next=p;
    }
}

void DFS(struct gra p,int i){
    struct graph *q;
    printf("%d ",i);
    flag[i]=1;
    for(q=p.link;q!=NULL;q=q->next){
        if(flag[q->num]==0) DFS(point[q->num],q->num);
    }
}

void BFS(struct gra p,int i){
    struct graph *q;
    if(flag[i]==1){
        printf("%d ",i);
        flag[i]=0;
        que[y++]=i;
    }
    q=p.link;
    while(q!=NULL){
        if(flag[q->num]==1){
            printf("%d ",q->num);
            flag[q->num]=0;
            que[y++]=q->num;
        }
        q=q->next;
    }
}

void tbfs(struct gra p,int n){
    int i;
    for(i=0;i<n;i++){
        BFS(point[que[i]],que[i]);
    }
}

int main()
{
  int n,m,i,op,a,b;
  scanf("%d %d",&n,&m);
  for(i=0;i<m;i++){
      scanf("%d %d",&a,&b);
      record(a,b);
  }
  scanf("%d",&op);
  DFS(point[0],0);
  printf("\n");
  tbfs(point[0],n); // @@ [BFS traversal logic is incorrect: 'tbfs' uses a global queue 'que' that is never initialized before the first BFS call, and the BFS function does not implement standard BFS using a queue properly. Also, 'flag' array is reused without resetting between traversals.]
  printf("\n");
  flag[op]=2; // @@ [Marking deleted vertex with 2 is inconsistent; later DFS checks for 0 only, but BFS checks for 1. This leads to undefined behavior in traversal after deletion.]
  point[op].link=NULL;
  DFS(point[0],0); // @@ [DFS after deletion may still traverse through edges pointing to the deleted vertex because adjacent vertices' adjacency lists are not updated to remove the deleted vertex.]
  printf("\n");
  tbfs(point[0],n); // @@ [Same issues as first tbfs call: queue 'que' is not reset, 'flag' array has inconsistent states (some set to 2, others 0 or 1), and adjacency lists of neighbors of deleted vertex still contain the deleted vertex, causing potential access to invalid or unintended nodes.]
  return 0;
}