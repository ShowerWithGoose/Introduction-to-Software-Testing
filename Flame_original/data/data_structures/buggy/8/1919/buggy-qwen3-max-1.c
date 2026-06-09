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
    int delete; // @@ [Using 'delete' as a variable name is invalid in C++ and may cause issues with some compilers or coding standards, though it's technically allowed in pure C. However, more critically, the traversal functions assume graph connectivity starting from 0, but the current DFS/BFS implementations loop over all vertices (for(int i=0;i<n;i++)) which violates requirement #3: "traversal should start from vertex 0". This causes extra traversals if the graph is connected, leading to wrong output format (multiple components printed even when graph is connected).]
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
            if(q->adjvex<p->adjvex){
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
            last->next=p;
        }
    }
}

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
    for(int i=0;i<n;i++){ // @@ [This loop violates requirement #3: traversal must start from vertex 0 only. Since the graph is connected, this loop will attempt to start DFS from every unvisited vertex, but after marking the deleted vertex as visited, it might still start from 0 correctly. However, if vertex 0 is not the first unvisited (which it always is unless deleted, and deletion excludes 0), it's okay—but the problem states the graph remains connected after deletion and deletion ≠ 0, so only one component exists. Still, the loop is unnecessary and incorrect per spec: must start ONLY from 0. Should be: if(visit[0]==0) DFS(0);]
        if(visit[i]==0)
            DFS(i);
    }
    printf("\n");
}

int queue[300];
void BFS(int start){
    e_link *p;
    int w=0;
    int front=0,count=0,rear=0;
    printf("%d ",v[start].num);
    visit[start]=1;
    visit[start]=1; // @@ [Redundant assignment: visit[start] is set to 1 twice. While harmless, it's unnecessary. More importantly, the BFS implementation uses a non-standard queue management (using count and rear=front+count) which may work but is error-prone. However, the critical issue is the same as in DFS: the calling function travel_BFS loops over all vertices instead of starting only from 0.]
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
                rear=front+count;
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
    for(int i=0;i<n;i++){ // @@ [Same error as in travel_DFS: must start traversal only from vertex 0, not loop through all vertices. The problem requires starting from 0, and the graph is connected, so only one traversal is needed starting at 0. This loop causes incorrect behavior if there were multiple components, but even in connected graphs, it's against spec. Should only call BFS(0) if 0 is not deleted (and it isn't, per input constraints).]
        if(visit[i]==0)
            BFS(i);
    }
    printf("\n");
}