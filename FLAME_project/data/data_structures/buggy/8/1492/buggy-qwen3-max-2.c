#include<stdio.h>
#include<stdlib.h>
#define MaxV 256
struct edge {
    int adj;
    struct edge *next;
};
int m, cancel, min=200;//m为顶点个数，cancel为删除顶点 
int front, rear=-1, count;
void enQueue(int);//入队 
int deQueue();//出队 
struct edge *graph[MaxV];
int Visited[200];//标识是否访问 
int queue[200];
void createGraph(struct edge *[]);
struct edge *insertEdge(struct edge *, int);
void reset();
void travelDFS(struct edge *[], int);//深度优先 
void DFS(struct edge *[], int, int);//深度优先子算法 
void travelBFS(struct edge *[], int);//广度优先
void BFS(struct edge *[], int, int); //广度优先子算法 
int main() {
    createGraph(graph);
    int i;
    struct edge *p;
    /*for(i=0;i<9;i++) {
        for(p=graph[i];;p=p->next) {
            printf("%d", p->adj);
            if(p->next!=NULL) {
                printf(" ");
            } else {
                printf("\n");
                break;
            }
        }
    }测试创建表*/ 
    travelDFS(graph, 0);
    reset();
    //m=200;
    travelBFS(graph, 0);//测试通过 
    reset();
    //m=200;
    scanf("%d", &cancel);
    travelDFS(graph, 1);
    reset();
    //m=200;
    travelBFS(graph, 1);//测试通过 
    //reset();
    return 0;
}
void createGraph(struct edge *graph[]) {
    int i, n, v1, v2;
    scanf("%d%d", &m, &n); @@ [The input order is wrong: it should read 'n m' (vertices edges), but reads 'm n'. This causes m to be the number of vertices and n the number of edges, but later code uses m as vertex count correctly. However, in the test case input "3 3", m becomes 3 (correct vertex count), so this may not be the direct cause of WA, but still a potential confusion. However, the real issue lies elsewhere.]
    for(i=0;i<n;i++) {
        scanf("%d%d", &v1, &v2);
        graph[v1]=insertEdge(graph[v1], v2);
        graph[v2]=insertEdge(graph[v2], v1);
    }
}
struct edge *insertEdge(struct edge *head, int avex) {
    struct edge *e, *p;
    e=(struct edge *)malloc(sizeof(struct edge));
    e->adj=avex;
    e->next=NULL;
    if(head==NULL) {
        head=e;
        return head;
    }
    for(p=head;p->next!=NULL;p=p->next) {
        ;
    }
    p->next=e;
    return head; @@ [This insertion does NOT maintain adjacency list in ascending order. The problem requires visiting adjacent vertices in ascending order, but this appends new edges at the end, so the adjacency list is in input order, not sorted. This breaks the traversal order requirement.]
}
void travelDFS(struct edge *G[], int mode) {//mode为遍历模式，0为删前，1为删后 
    int i;
    for(i=0;i<m;i++) {
        if(!Visited[i]) {
            DFS(G, i, mode);
        }
    }
    printf("\n");
}
void DFS(struct edge *G[], int v, int mode) {
    struct edge *p, *q;
    min=200;
    Visited[v]=1;
    if(mode==1&&v==cancel) {
        return;
    }
    printf("%d ", v);
    for(q=G[v];q!=NULL;q=q->next) {
        min=200;
        for(p=q;p!=NULL;p=p->next) {
            if(!Visited[p->adj]&&p->adj<min) {
                min=p->adj;
            }
        }
        if(min!=200) {
            DFS(G, min, mode);
        }
    } @@ [This DFS implementation does not traverse neighbors in ascending order correctly. It tries to find the smallest unvisited neighbor in the entire remaining list each time, but after visiting one, it doesn't continue with the next smallest from the original list. Also, it may revisit nodes or skip some due to flawed logic. The standard DFS should iterate through neighbors in sorted order and recursively visit unvisited ones.]
}
void enQueue(int item) {
    if(count==200) {
        printf("Full queue!");
    } else {
        rear++;
        queue[rear]=item;
        count++;
    }
}
int deQueue() {
    int e;
    if(count==0) {
        printf("Empty queue!");
        return; @@ [Missing return value type consistency: function returns int, but returns nothing in error case. Should return a dummy value or handle differently, but more critically, this may cause undefined behavior. However, in given test case, queue won't be empty when dequeuing, so maybe not the direct cause.]
    } else {
        e=queue[front];
        count--;
        front++;
        return e;
    }
}
void travelBFS(struct edge *G[], int mode) {
    int i;
    for(i=0;i<m;i++) {
        Visited[i]=0;
    }
    for(i=0;i<m;i++) {
        if(!Visited[i]) {
            BFS(G, i, mode);
        }
    }
    printf("\n");
}
void BFS(struct edge *G[], int v, int mode) {
    struct edge *p;
    int flag;
    Visited[v]=1;
    enQueue(v);
    while(count>0) {
        flag=1;
        v=deQueue();
        if(mode==0||v!=cancel) {
            printf("%d ", v);
        } else {
            continue;
        }
        while(flag>0) {
            min=200;
            flag=0;
            for(p=G[v];p!=NULL;p=p->next) {
                if(!Visited[p->adj]&&p->adj<min) {
                    min=p->adj;
                }
            }
            if(min!=200) {
                Visited[min]=1;
                enQueue(min);
                flag=1;
            }
        } @@ [This BFS implementation is fundamentally flawed. Instead of enqueuing all unvisited neighbors in sorted order, it only enqueues the smallest unvisited neighbor repeatedly until none left. This misses other neighbors and does not perform standard BFS. The inner while loop tries to find one min per iteration, but doesn't enqueue all unvisited neighbors. Correct BFS should iterate through all neighbors (in sorted order) and enqueue each unvisited one once.]
    }
}
void reset() {
    int i;
    for(i=0;i<m;i++) {
        Visited[i]=0;
    }
}