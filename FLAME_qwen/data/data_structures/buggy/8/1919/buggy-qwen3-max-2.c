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
    int delete; // @@ [Using 'delete' as a variable name is invalid in C++ and may cause issues with some compilers or tools treating it as a keyword; though valid in pure C, it's poor practice and may lead to compilation errors in strict environments.]
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
        int bool=0; // @@ ['bool' is not a reserved keyword in C, but using it as an integer variable is confusing and may conflict if <stdbool.h> is included elsewhere; however, the real issue is that this insertion logic does not maintain adjacency list in ascending order correctly due to flawed insertion logic. Specifically, when inserting into the middle, it breaks the loop but doesn't handle all cases properly, especially when the new node should go at the end after a larger node.]
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
            last->next=p; // @@ [If the loop ends because q becomes NULL (i.e., we reached the end), then 'last' points to the last node, so appending p is correct. However, if the list was empty, this code wouldn't run because of the earlier 'if(!v[a].link)' check. But there's a logical flaw: if all existing adjvex values are less than b, then the while loop exits with q==NULL and bool remains 0, and last is set, so this line runs — which is okay. However, the bigger problem is that the insertion doesn't guarantee ascending order because comparisons are done against p->adjvex which is fixed, but the traversal condition may skip proper placement. Also, note that multiple edges could be inserted out-of-order depending on input sequence.]
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
    printf("%d ",v[start].num); // @@ [This prints a space after every vertex, including the last one, which violates the output format requirement of space-separated vertices without trailing space.]
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
    for(int i=0;i<n;i++){ // @@ [The problem states traversal must start from vertex 0, but this loop starts from i=0 and calls DFS(i) only if unvisited. Since the graph is connected and we mark deleted vertex as visited, this will work only if vertex 0 is not deleted (which is guaranteed). However, it still unnecessarily iterates over all vertices. More critically, if the graph were disconnected (but problem says it's connected), this would traverse components. But per spec, always start at 0, so this loop is incorrect—it should just call DFS(0) directly.]
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
    printf("%d ",v[start].num); // @@ [Same issue: trailing space after last vertex.]
    visit[start]=1;
    visit[start]=1; // @@ [Redundant assignment; no functional error but unnecessary.]
    queue[rear]=start;
    count++;
    rear=front+count;
    while(front!=rear){
        start=queue[front];
        front++;
        for(p=v[start].link;p!=NULL;p=p->next){
            if(visit[p->adjvex]==0){
                printf("%d ",v[p->adjvex].num); // @@ [Trailing space again.]
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
    for(int i=0;i<n;i++){ // @@ [Same issue as in travel_DFS: should start only from vertex 0, not iterate through all vertices. The problem specifies starting from vertex 0.]
        if(visit[i]==0)
            BFS(i);
    }
    printf("\n");
}