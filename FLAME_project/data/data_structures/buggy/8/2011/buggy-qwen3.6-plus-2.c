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

void BFS(struct gra p,int i){ // @@ The BFS logic is fundamentally flawed. It relies on a global queue 'que' and index 'y' that are not properly reset or managed for separate traversals. It also incorrectly uses the 'flag' array (checking for 1 instead of 0 for unvisited) and mixes printing with queue population in a way that doesn't implement standard BFS level-by-level or FIFO correctly for this structure. Specifically, it prints nodes when they are discovered in the neighbor list of the current node being processed from the queue, but the condition `if(flag[q->num]==1)` is wrong because flags are set to 1 when visited. It should check if unvisited (0). Furthermore, `tbfs` calls `BFS` for each node in the queue, but `BFS` itself tries to print and enqueue neighbors. This implementation is broken.
    struct graph *q;
    if(flag[i]==1){ // @@ Error: Flag is 1 when visited. We should only process/start if it's unvisited (0). But here it seems to assume flag 1 means something else or is just wrong. In main, flags are 0 initially. DFS sets them to 1. Then for the second part, deleted node is 2. Flags are not reset.
        printf("%d ",i);
        flag[i]=0; // @@ Error: Setting flag to 0 after visiting? This contradicts standard visited marking.
        que[y++]=i;
    }
    q=p.link;
    while(q!=NULL){
        if(flag[q->num]==1){ // @@ Error: Should check if unvisited (0). If flag is 1, it means visited by DFS previously.
            printf("%d ",q->num);
            flag[q->num]=0; // @@ Error: Incorrect flag management.
            que[y++]=q->num;
        }
        q=q->next;
    }
}

void tbfs(struct gra p,int n){ // @@ This function attempts to drive the BFS using the global queue 'que' and index 'y'. However, 'y' is not reset between the first and second BFS calls. Also, the BFS logic inside `BFS` function is incorrect.
    int i;
    for(i=0;i<n;i++){ // @@ Error: Looping up to n is incorrect because the number of valid nodes in the queue might be less than n, especially after deletion. It should loop up to y (the number of elements enqueued).
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
  tbfs(point[0],n); // @@ Error: The global state (flag, que, y) is not initialized/reset before this call. 'flag' is all 0 initially, so DFS sets them to 1. Then tbfs/BFS expects flags to be 1 to process? No, standard BFS needs unvisited nodes. The logic is completely mixed up.
  printf("\n");
  flag[op]=2;
  point[op].link=NULL;
  DFS(point[0],0); // @@ Error: Flags are not reset before the second DFS. Nodes visited in the first DFS still have flag=1, so they won't be visited again.
  printf("\n");
  tbfs(point[0],n); // @@ Error: Flags and queue state are not reset for the second BFS.
  return 0;
}