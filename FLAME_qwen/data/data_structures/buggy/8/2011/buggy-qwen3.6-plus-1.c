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
int flag[120]={0},que[120]={0},y=0; // @@ Global arrays flag, que, and y are not reset between traversals, causing incorrect results for subsequent traversals.

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
    if(flag[i]==1){ // @@ Error: flag[i]==0 indicates unvisited. Condition should be flag[i]==0 to process unvisited nodes.
        printf("%d ",i);
        flag[i]=0; // @@ Error: Should mark node as visited (e.g., flag[i]=1), not unvisited.
        que[y++]=i;
    }
    q=p.link;
    while(q!=NULL){
        if(flag[q->num]==1){ // @@ Error: Should check for unvisited neighbors, condition should be flag[q->num]==0.
            printf("%d ",q->num);
            flag[q->num]=0; // @@ Error: Should mark neighbor as visited (e.g., flag[q->num]=1).
            que[y++]=q->num;
        }
        q=q->next;
    }
}

void tbfs(struct gra p,int n){
    int i;
    for(i=0;i<n;i++){ // @@ Error: Loop bound should be based on queue size y (i<y), not n. Accessing uninitialized que elements causes undefined behavior and incorrect traversal order.
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
  tbfs(point[0],n);
  printf("\n");
  flag[op]=2; // @@ Error: flag array and queue variables (que, y) are not reset before the second traversal, leading to skipped nodes or incorrect output.
  point[op].link=NULL;
  DFS(point[0],0);
  printf("\n");
  tbfs(point[0],n);
  return 0;
}