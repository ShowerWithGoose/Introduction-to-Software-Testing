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
            last->next=p; // @@ [Error: When the while loop exits because q becomes NULL (i.e., p->adjvex is greater than all existing nodes), last may still be NULL if the list was empty (but that case is handled by the if(!v[a].link) branch). However, if the list is non-empty and p->adjvex is greater than all nodes, the loop will iterate until q is NULL, and last will point to the last node. This line is correct in that case. But there is a potential issue: if the list has only one node and p->adjvex is less than that node, the else branch will execute with last==NULL, setting v[a].link=p and bool=1, so this line won't execute. The real error is that the while loop condition does not handle the case where p->adjvex is greater than all existing nodes correctly because when q becomes NULL, last points to the last node, and this line appends p. However, the logic for inserting in ascending order is flawed because it does not handle the case where p->adjvex is less than the first node correctly (it does, via the else branch with last==NULL). The main issue is that the variable name "bool" conflicts with the standard library type _Bool or bool in C, which may cause compilation errors in some environments. Additionally, the function does not ensure that edges are stored in strictly ascending order for traversal, but the problem requires visiting adjacent vertices in ascending order. The insertion logic is overly complex and may not correctly maintain sorted order in all cases, but the most immediate error is the use of "bool" as a variable name, which can conflict with the standard bool type if <stdbool.h> is included (though it's not included here, it's still a reserved identifier in C99 and later).]
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
    for(int i=0;i<n;i++){
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
    visit[start]=1; // @@ [Error: Duplicate line, sets visit[start] to 1 twice, which is redundant but not harmful. However, the variable 'w' is declared but never used, which is a minor issue.]
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
    for(int i=0;i<n;i++){
        if(visit[i]==0)
            BFS(i);
    }
    printf("\n");
}