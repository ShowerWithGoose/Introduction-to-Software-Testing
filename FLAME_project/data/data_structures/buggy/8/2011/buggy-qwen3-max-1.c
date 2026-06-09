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
  memset(flag, 1, sizeof(flag)); // @@ [BFS uses flag array as a "to-be-visited" marker (1 means not visited), but after DFS, all flags are set to 1 (visited). So before BFS, we must reset flag to 1 for unvisited nodes. However, the current code does not reset flag before first BFS, causing BFS to output nothing or wrong order.]
  y = 0; // @@ [The global variable 'y' used as queue index is not reset before first BFS, but it's 0 initially so may be okay. However, more critically, the flag array is not properly initialized for BFS.]
  tbfs(point[0],n);
  printf("\n");
  flag[op]=2; // @@ [Setting flag[op]=2 prevents DFS from visiting 'op', but the graph structure itself is not updated—edges to 'op' still exist in adjacency lists of other nodes. So during DFS/BFS after deletion, the program may still try to traverse to 'op' and skip it due to flag[op]!=0, but this doesn't remove edges, leading to potential issues if 'op' appears in neighbor lists. However, in this specific test case it works by accident. The real issue is that the BFS implementation is flawed.]
  point[op].link=NULL; // @@ [This only removes outgoing edges from 'op', but does not remove 'op' from the adjacency lists of other vertices. So other vertices still have 'op' in their neighbor lists, which can cause problems during traversal if not handled by flag. But since flag[op] is set to 2 (non-zero), it won't be visited. However, the bigger issue is in BFS logic.]
  memset(flag, 0, sizeof(flag)); // @@ [Before second DFS, flag should be reset to 0 (unvisited), but the code doesn't do it. Instead, it relies on previous state. In the given code, after first BFS, flag values are 0 for visited nodes. Then flag[op]=2 is set. But for second DFS, we need all nodes except 'op' to start as unvisited (flag=0). However, the existing flag values from BFS are 0, which DFS interprets as unvisited—so it might work accidentally. But this is fragile.]
  // Actually, the critical error is in BFS implementation: it prints nodes as it enqueues them in BFS(), but tbfs() calls BFS on each node in que[] which was filled by previous BFS calls—this is not standard BFS and leads to incorrect ordering.
  DFS(point[0],0);
  printf("\n");
  memset(flag, 1, sizeof(flag)); // @@ [Again, before second BFS, flag should be set to 1 for all valid nodes (except op), but the code doesn't properly reinitialize. Moreover, the BFS logic itself is fundamentally flawed.]
  flag[op] = 0; // @@ [Since op is deleted, it should not be visited, so flag[op] should not be 1. But the BFS function checks if flag[i]==1 to print. So we must ensure flag[op]!=1. However, the main flaw is the BFS algorithm design.]
  y = 0;
  tbfs(point[0],n);
  return 0;
}