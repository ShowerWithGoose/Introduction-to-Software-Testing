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
struct edge *insertEdge(struct edge *, int); // @@ The function appends edges at the end without maintaining ascending order. This violates the requirement to visit neighbors in ascending order.
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
    scanf("%d%d", &m, &n);
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
    return head;
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
    printf("%d ", v); // @@ Prints a trailing space after the last vertex. This does not match the expected output which has no trailing space.
    for(q=G[v];q!=NULL;q=q->next) { // @@ This loop iterates over neighbors with a moving pointer q, and inside it finds the smallest unvisited neighbor only from the sublist starting at q. This can miss neighbors that appear earlier in the list, leading to incomplete traversal.
        min=200;
        for(p=q;p!=NULL;p=p->next) {
            if(!Visited[p->adj]&&p->adj<min) {
                min=p->adj;
            }
        }
        if(min!=200) {
            DFS(G, min, mode);
        }
    }
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
        return;
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
    } // @@ This resets the visited array but does not reset the queue's front, rear, and count. The queue state from a previous BFS remains and may cause incorrect behavior in subsequent BFS calls.
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
            printf("%d ", v); // @@ Prints a trailing space after the last vertex. This does not match the expected output which has no trailing space.
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
        }
    }
}
void reset() {
    int i;
    for(i=0;i<m;i++) {
        Visited[i]=0;
    }
}