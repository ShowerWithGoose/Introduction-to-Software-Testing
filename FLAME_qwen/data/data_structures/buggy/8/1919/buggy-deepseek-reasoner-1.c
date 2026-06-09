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
    int delete;
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
    printf("%d ",v[start].num); // @@ Potential formatting: trailing space may be rejected; use leading space for subsequent vertices.
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
    for(int i=0;i<n;i++){
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
    visit[start]=1;
    queue[rear]=start;
    count++;
    rear=front+count; // @@ Error: incorrect queue index calculation; should be rear++ instead of recomputing from front and count.
    while(front!=rear){
        start=queue[front];
        front++;
        for(p=v[start].link;p!=NULL;p=p->next){
            if(visit[p->adjvex]==0){
                printf("%d ",v[p->adjvex].num);
                visit[p->adjvex]=1;
                queue[rear]=p->adjvex; // @@ Error: rear index may be incorrectly computed, leading to gaps or overwriting.
                count++;
                rear=front+count; // @@ Error: same as above; should simply be rear++.
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
    for(int i=0;i<n;i++){
        if(visit[i]==0)
            BFS(i);
    }
    printf("\n");
}