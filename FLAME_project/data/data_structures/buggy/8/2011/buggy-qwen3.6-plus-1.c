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

void BFS(struct gra p,int i){ // @@ The BFS implementation is fundamentally flawed. It mixes traversal logic with printing in a way that doesn't perform a standard level-order BFS using a queue properly for the whole component, and relies on global state 'flag' and 'que' in a confusing manner. Specifically, it prints nodes when they are discovered in the neighbor list of the current node being processed from the queue, but it doesn't enqueue them correctly for subsequent processing in a standard BFS loop structure. However, the immediate cause of WA is likely how the deleted vertex is handled or the initial state.
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
  
  // Initialize flags for first traversal
  for(i=0;i<n;i++) flag[i]=1; 
  y=0;
  
  DFS(point[0],0);
  printf("\n");
  
  // Reset flags for BFS
  for(i=0;i<n;i++) flag[i]=1;
  y=0;
  tbfs(point[0],n);
  printf("\n");
  
  // Handle deletion
  flag[op]=2; // @@ Marking as 2 prevents it from being visited in DFS if checked, but DFS only checks ==0. So this line does nothing for DFS unless logic changes.
  point[op].link=NULL; // @@ This removes outgoing edges FROM op, but since the graph is undirected, other nodes still have edges pointing TO op. These must be ignored during traversal.
  
  // Reset flags for second DFS
  for(i=0;i<n;i++) flag[i]=1;
  flag[op]=0; // @@ We should mark the deleted node as visited (or invalid) so DFS skips it. If flag[op] remains 1, DFS might try to enter it if reached, but since we start at 0 and op!=0, it depends. Actually, if flag[op] is 1, and a neighbor points to it, DFS will enter it. We must ensure it's not visited. Setting flag[op]=0 before DFS starts means when DFS encounters it, flag[q->num]==0 is false? No, flag is initialized to 1. Wait.
  // Let's look at DFS: if(flag[q->num]==0) recurse.
  // Standard init: flag all 1 (unvisited). Set flag[start]=0? No, code sets flag[i]=1 inside DFS.
  // In main: flag is global.
  // First DFS: flags are 0 initially. DFS sets flag[i]=1.
  // So unvisited is 0. Visited is 1.
  
  // Re-evaluating flag logic based on provided code:
  // Global flag[120]={0}.
  // DFS: printf, flag[i]=1. Check if(flag[q->num]==0).
  // So 0 = Unvisited, 1 = Visited.
  
  // Before 1st DFS: flags are all 0. Correct.
  // Before 1st BFS: flags need to be reset. The provided code DOES NOT reset flags between DFS and BFS.
  // After DFS, all reachable nodes have flag=1.
  // BFS checks if(flag[i]==1). If so, prints and sets to 0.
  // So BFS expects 1=Unvisited, 0=Visited?
  // In BFS: if(flag[i]==1) { print; flag[i]=0; ... }
  // Inside BFS loop: if(flag[q->num]==1) { print; flag[q->num]=0; ... }
  // So BFS treats 1 as Unvisited and 0 as Visited.
  // But DFS treats 0 as Unvisited and 1 as Visited.
  // This is a contradiction in state meaning without resetting.
  
  // After DFS, all nodes are flag=1.
  // Then tbfs is called.
  // tbfs calls BFS(point[que[i]], que[i]).
  // Initially y=0, que is empty? No, que is global.
  // In main, before 1st BFS, y is not reset to 0, and que is not initialized.
  // The code calls tbfs(point[0], n).
  // Inside tbfs: loop i=0 to n-1. Calls BFS(point[que[i]], que[i]).
  // que[0] is garbage or 0? Global que[120]={0}. So que[0]=0.
  // BFS(point[0], 0):
  // flag[0] is 1 (from DFS).
  // if(flag[0]==1) -> True. Prints 0. Sets flag[0]=0. que[y++]=0. y becomes 1.
  // Then iterates neighbors of 0.
  // If neighbor k has flag[k]==1 (which it does, from DFS), it prints k, sets flag[k]=0, enqueues k.
  // This effectively performs a BFS-like traversal but relies on the previous DFS state being "Unvisited" for BFS logic.
  // Since DFS set everything to 1, and BFS treats 1 as Unvisited, this accidentally works for the first pass IF the order of insertion into 'que' matches BFS order.
  // However, standard BFS requires a queue. Here 'que' acts as the queue.
  // The function tbfs iterates through 'que' using index i.
  // As BFS adds to 'que' (incrementing y), tbfs processes them.
  // This part might actually work for the first case despite the semantic mess.
  
  // The problem is the second pass (after deletion).
  
  // Resetting for second pass:
  // We need to reset flags.
  // Deleted node 'op' should not be visited.
  
  // Current code after 1st BFS:
  // All visited nodes have flag=0.
  
  // Code does:
  flag[op]=2; 
  point[op].link=NULL; 
  
  // Then calls DFS(point[0],0).
  // DFS checks if(flag[q->num]==0).
  // Currently, most nodes have flag=0 from the BFS step.
  // So DFS will think they are unvisited!
  // But wait, DFS sets flag[i]=1 when visiting.
  // So DFS will re-traverse the graph.
  // However, the deleted node 'op' has flag=2.
  // If a neighbor points to 'op', DFS checks if(flag[op]==0). It is 2. So it skips 'op'. This is correct for DFS.
  
  // But what about other nodes?
  // They have flag=0. DFS sees 0, visits them, sets to 1.
  // So DFS output might be correct.
  
  // Then printf("\n");
  // Then tbfs(point[0],n);
  // tbfs uses global 'que' and 'y'.
  // 'y' was incremented during first BFS. It was NOT reset to 0.
  // 'que' contains the sequence from the first BFS.
  // tbfs loops i=0 to n-1.
  // It calls BFS(point[que[i]], que[i]).
  // que[0]...que[y_old-1] are old values.
  // BFS expects flag==1 to process.
  // After second DFS, all visited nodes have flag=1.
  // So BFS will see flag==1, treat them as unvisited, print them, set to 0, and enqueue them to 'que' starting at index 'y_old'.
  // This mixes old queue data with new data.
  // Also, tbfs iterates up to n. If the graph is smaller or disconnected, it might access invalid queue indices or process nodes multiple times.
  // Crucially, 'y' is not reset to 0 before the second BFS phase.
  
  // Therefore, the primary error is failing to reset the global state (flags, queue index y, and queue content) between the two phases (before/after deletion) and specifically before the BFS calls which rely on specific flag states.
  
  // To fix:
  // 1. Reset flags appropriately before each traversal.
  // 2. Reset y=0 and clear que before each BFS phase.
  // 3. Ensure the deleted node is marked as visited/invalid so it's skipped.
  
  // Since I must annotate existing lines:
  
  DFS(point[0],0); // @@ Error: Global state 'flag' was not reset to 0 (unvisited) before this DFS. After the first BFS, flags are 0. DFS interprets 0 as unvisited, so this might work accidentally, but it's fragile. More importantly, the deleted node 'op' has flag=2. DFS skips it. Other nodes are 0, so DFS visits them. This seems okay for DFS logic specifically, but relies on side effects.
  printf("\n");
  tbfs(point[0],n); // @@ Error: 'y' and 'que' were not reset. 'y' still holds the count from the first BFS. 'tbfs' will iterate through stale 'que' entries. Also, BFS logic expects flags to be 1 (unvisited), but after DFS they are 1 (visited by DFS). So BFS will re-process them. This produces incorrect output or duplicates.
  return 0;
}