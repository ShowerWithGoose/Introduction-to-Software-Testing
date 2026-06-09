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
    int delete; // @@ [Using 'delete' as a variable name is invalid in C++ and may cause issues with some compilers or coding standards, though it's technically allowed in pure C. However, the real issue is that the traversal functions always start from vertex 0 but iterate over all unvisited vertices, which violates requirement #3: "the traversal should start from vertex 0" and only traverse the connected component containing 0. Since the graph is connected, this isn't the main bug. The actual critical error is in the BFS function where 'visit[start]=1;' is duplicated, but more importantly, both DFS and BFS are called in a loop over all vertices, which is wrong because the problem states to start from vertex 0 only.]
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
    for(int i=0;i<n;i++){ // @@ [This loop causes traversal to start from every unvisited vertex, but the problem requires starting ONLY from vertex 0. Since the graph is connected, this would still work if vertex 0 is first, but if vertex 0 is marked as deleted (which it won't be per requirement #4), or if the loop starts elsewhere, it's wrong. However, since i starts at 0 and the graph is connected, it might seem okay, but the specification says "start from vertex 0", not "start from the lowest unvisited vertex". So this loop is incorrect—it should just call DFS(0) directly if 0 is not deleted.]
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
    visit[start]=1; // @@ [Duplicate assignment—harmless but unnecessary. Not the main bug.]
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
    for(int i=0;i<n;i++){ // @@ [Same error as in travel_DFS: should not loop over all vertices. Must start only from vertex 0. The problem states: "the traversal should start from vertex 0". This loop will start BFS from vertex 0 (since i=0 first and graph is connected), so output might appear correct, but it's logically wrong and would fail if the graph weren't connected (though the problem states it is). However, the bigger issue is that after deletion, if vertex 0 were disconnected (but problem says graph remains connected), but per spec, vertex 0 is never deleted. Still, the code structure violates the explicit instruction to start from 0 only.]
        if(visit[i]==0)
            BFS(i);
    }
    printf("\n");
}