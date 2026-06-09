#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
#define eps 1e-10
#define array_len(x) (sizeof(x) / sizeof(x[0]))
typedef long long ll;
typedef double D;

typedef struct edge{
    int adjvex;
    struct edge *next;
}e_link;

typedef struct ver {
    int num;
    e_link *link;
}v_link;
v_link v[100];
int visit[100];

void create(int a,int b);
void DFS(int start);
void travel_DFS(int n,int judge_delete);
void BFS(int start);
void travel_BFS(int n,int judge_delete);

int main() {
    int num_v,num_e;
    scanf("%d%d",&num_v,&num_e);
    for(int i=0;i<num_v;i++){
        v[i].num=i;
        v[i].link=NULL;
    }
    int a,b;

    for(int i=0;i<num_e;i++){
        scanf("%d%d",&a,&b);
        create(a,b);
        create(b,a);
    }
    int delete; // @@ [Using 'delete' as a variable name is invalid in C++ and may cause issues with some compilers or coding standards, though it's technically allowed in pure C. However, more critically, the traversal functions assume graph connectivity starting from vertex 0, but the current implementation loops over all vertices (for(int i=0;i<n;i++)) which violates requirement #3: "traversal should start from vertex 0". This causes extra traversals if the graph is connected, leading to incorrect output format (multiple components printed even when graph is connected).]
    scanf("%d",&delete);
    travel_DFS(num_v,-1);
    travel_BFS(num_v,-1);
    travel_DFS(num_v,delete);
    travel_BFS(num_v,delete);
    return 0;
}

void create(int a,int b){
    e_link *p,*q;
    p=(e_link*) malloc(sizeof(e_link));
    p->adjvex=b;
    p->next=NULL;
    if(!v[a].link){
        v[a].link=p;
    }
    else{
        q=v[a].link;
        e_link *last=NULL;
        int bool=0;
        while(q!=NULL){
            if(q->adjvex<p->adjvex){ // @@ [This comparison is backwards: it should insert in ascending order, but this condition inserts p after nodes with smaller adjvex. The loop continues while q->adjvex < p->adjvex, so insertion happens when q->adjvex >= p->adjvex. However, the logic for maintaining sorted order is flawed because it doesn't correctly handle insertion at the end or middle in all cases. Specifically, if all existing adjvex are less than p->adjvex, 'last' becomes the last node, but then 'bool' remains 0 and 'last->next=p;' executes — however, if the list has only one element and p->adjvex is larger, 'last' is never set (remains NULL), leading to dereferencing NULL in 'last->next=p;'. This causes undefined behavior (likely crash).]
                last=q;
                q=q->next;
            }
            else{
                if(last!=NULL){
                    p->next=q;
                    last->next=p;
                    bool=1;
                    break;
                }
                else{
                    p->next=q;
                    v[a].link=p;
                    bool=1;
                    break;
                }
            }
        }
        if(bool==0){
            last->next=p; // @@ [If the while loop runs to completion (i.e., all existing neighbors have smaller indices than b), then 'last' points to the last node. But if the list was empty, this code wouldn't run because of the 'if(!v[a].link)' above. However, if the list has elements and we exit the loop normally, 'last' is valid. BUT: if the first element is already >= p->adjvex, the else branch runs and sets bool=1, so this line is skipped. The real issue is when the list is non-empty and all elements are < p->adjvex: then 'last' is set properly. However, there's another bug: if the list has one element and p->adjvex is greater, then in the first iteration: q->adjvex < p->adjvex → last=q, q=q->next (now NULL), loop ends, bool=0, then last->next=p → OK. So maybe not always NULL. But the bigger issue is that the insertion does NOT guarantee ascending order because the comparison is done against p->adjvex which is fixed, but the logic may still work. However, the critical error is in traversal starting point.]
        }
    }
}

//正常版本的DFS（深度优先算法）

//void DFS(int start){
//    e_link *p;
//    printf("%d ",v[start].num);
//    visit[start]=1;
//    for(p=v[start].link;p!=NULL;p=p->next){
//        if(!visit[p->adjvex]){
//            DFS(p->adjvex);
//        }
//    }
//}
//
//void travel_DFS(int n){
//    for(int i=0;i<n;i++){
//        visit[i]=0;
//    }
//    for(int i=0;i<n;i++){
//        if(visit[i]==0)
//            DFS(i);
//    }
//    printf("\n");
//}

void DFS(int start){
    e_link *p;
    printf("%d ",v[start].num);
    visit[start]=1;
    for(p=v[start].link;p!=NULL;p=p->next){
        if(!visit[p->adjvex]){
            DFS(p->adjvex);
        }
    }
}

void travel_DFS(int n,int judge_delete){
    for(int i=0;i<n;i++){
        visit[i]=0;
    }
    if(judge_delete>=0)
        visit[judge_delete]=1;
    for(int i=0;i<n;i++){ // @@ [Requirement #3 states: "the traversal should start from vertex 0". But this loop starts from i=0 and calls DFS(i) for every unvisited vertex. Since the graph is connected (per requirement #2), this will only call DFS(0) once — BUT only if vertex 0 is not deleted. However, if vertex 0 were deleted (which it isn't per requirement #4), but more importantly, the problem says "start from vertex 0", meaning ONLY start from 0, not iterate through all vertices. This loop is designed for disconnected graphs, but the problem states the graph is connected. However, the bigger issue is that even in a connected graph, this loop is unnecessary and could cause problems if the graph wasn't connected — but per spec it is. Still, the correct approach is to ONLY start from 0, not loop. So this loop should be replaced with just: if (visit[0] == 0) DFS(0); — but since graph is connected and 0 is not deleted, visit[0] will be 0 initially. However, the current code works for connected graphs? Let's see: i=0, visit[0]=0 → DFS(0) → marks all as visited → loop ends. So output is correct. So maybe not an error here. But wait: what if the deleted vertex is not 0, and graph remains connected — yes, so DFS(0) covers all. So this loop is redundant but harmless. However, the REAL error is in BFS duplicate print and queue management.]
        if(visit[i]==0)
            DFS(i);
    }
    printf("\n");
}

//正常版本的BFS（广度优先算法）
//int queue[300];
//void BFS(int start){
//    e_link *p;
//    int w=0;
//    int front=0,count=0,rear=0;
//    printf("%d ",v[start].num);
//    visit[start]=1;
//    visit[start]=1;
//    queue[rear]=start;
//    count++;
//    rear=front+count;
//    while(front!=rear){
//        start=queue[front];
//        front++;
//        for(p=v[start].link;p!=NULL;p=p->next){
//            if(visit[p->adjvex]==0){
//                printf("%d ",v[p->adjvex].num);
//                visit[p->adjvex]=1;
//                queue[rear]=p->adjvex;
//                count++;
//                rear=front+count;
//            }
//        }
//    }
//}
//
//void travel_BFS(int n){
//    for(int i=0;i<n;i++){
//        visit[i]=0;
//    }
//    for(int i=0;i<n;i++){
//        if(visit[i]==0)
//            BFS(i);
//    }
//}

int queue[300];
void BFS(int start){
    e_link *p;
    int w=0;
    int front=0,count=0,rear=0;
    printf("%d ",v[start].num);
    visit[start]=1;
    visit[start]=1; // @@ [Duplicate assignment: harmless but unnecessary. Not the main error.]
    queue[rear]=start;
    count++;
    rear=front+count;
    while(front!=rear){
        start=queue[front];
        front++;
        for(p=v[start].link;p!=NULL;p=p->next){
            if(visit[p->adjvex]==0){
                printf("%d ",v[p->adjvex].num);
                visit[p->adjvex]=1;
                queue[rear]=p->adjvex;
                count++;
                rear=front+count; // @@ [This queue management is unconventional and error-prone. Typically, rear is incremented directly (rear++). Here, rear = front + count, but count is the total number of elements ever enqueued. This might work, but let's see: initially, rear=0, count=1 → rear=0+1=1. Then when adding a new element: count becomes 2, rear = front (which is 1 after dequeue) + 2 = 3. But the queue array index should be rear=1 for the second element. This causes elements to be placed at wrong indices, possibly skipping slots or overwriting. For example: after enqueueing start (index 0), rear=1. Then dequeue (front becomes 1), then enqueue neighbor: count=2, rear = 1+2=3 → queue[3]=neighbor. But queue[1] and [2] are unused. Then next dequeue: front=1, but queue[1] is uninitialized! So when front increments to 2, it reads garbage. This leads to undefined behavior — likely printing wrong vertices or crashing. This is a critical error in BFS implementation.]
            }
        }
    }
}

void travel_BFS(int n,int judge_delete){
    for(int i=0;i<n;i++){
        visit[i]=0;
    }
    if(judge_delete>=0)
        visit[judge_delete]=1;
    for(int i=0;i<n;i++){ // @@ [Same issue as in travel_DFS: looping over all vertices instead of just starting from 0. But as reasoned earlier, for connected graphs it's harmless. However, combined with the broken BFS queue logic, the output will be wrong.]
        if(visit[i]==0)
            BFS(i);
    }
    printf("\n");
}