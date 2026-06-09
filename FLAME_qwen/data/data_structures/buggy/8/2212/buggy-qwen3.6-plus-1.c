#include <stdio.h>
#define MaxV 256
int x=-1;
typedef struct edge{ 
int adj;
int wei;
struct edge *next;
}ELink;

typedef struct ver{
ELink *link;
}VLink;

ELink *insertEdge(ELink *head, int avex)
{
ELink *e,*p;
e =(ELink *)malloc(sizeof(ELink)); // @@ Missing #include <stdlib.h> for malloc, causes compilation error
e->adj= avex; e->wei=1; e->next=NULL;
if(head == NULL){head=e; return head;}
for(p=head;p->next != NULL; p=p->next)
{
    if(p->next->adj>e->adj)//从小到大排序 
    {
        e->next=p->next;
        p->next=e;
        goto A;
    }
}
;
p->next = e; 
A:
    return head;
}
int b[MaxV][2],n;
void createGraph(VLink graph[])
{ 
int i,v1,v2;
scanf("%d",&n); // @@ Input format is "n m", but only reads n here. Should read both in main, and loop should iterate m times.
for(i=0; i<n; i++){ // @@ Should iterate m times (number of edges), not n times (number of vertices)
scanf("%d%d",&v1,&v2);
b[i][0]=v1;
b[i][1]=v2; 
graph[v1].link=insertEdge(graph[v1].link, v2);
graph[v2].link=insertEdge(graph[v2].link, v1);
}
}
void create(VLink graph[])
{ 
int i;
for(i=0; i<n; i++){ // @@ Should iterate over the number of edges, not vertices. Also, m is not accessible here.
if(b[i][0]!=x&&b[i][1]!=x){
graph[b[i][0]].link=insertEdge(graph[b[i][0]].link, b[i][1]);
graph[b[i][1]].link=insertEdge(graph[b[i][1]].link, b[i][0]);}
}
}
int Visited[100] = {0}; //标识顶点是否被访问过，N为顶点数

void travelDFS(VLink G[], int n){
int i;
for (i = 0; i < n; i++)
Visited[i] = 0;
for (i = 0; i < n; i++) // @@ Problem specifies traversal starts from vertex 0. Should just call DFS(G, 0) directly instead of looping.
if (!Visited[i])
DFS(G, i);
}

void DFS(VLink G[], int v)
{
ELink *p;
Visited[v] = 1; //标识某顶点被访问过
if(v!=x)
printf("%d ",v);//访问某顶点
for (p = G[v].link; p != NULL; p = p->next)
if (!Visited[p->adj])
DFS(G, p->adj);
}

VLink a[100],c[100];
int Visite[100] = {0}; //标识顶点是否被访问，N为顶点数

void travelBFS(VLink G[], int n)
{
int i;
for (i = 0; i < n; i++)
Visite[i] = 0;
for (i = 0; i < n; i++) // @@ Problem specifies traversal starts from vertex 0. Should just call BFS(G, 0) directly instead of looping.
if (!Visite[i])
BFS(G, i);
}

#define MAXSIZE     1000
int  Q[MAXSIZE];
int  Front, Rear,Count;

void  initQueue(void)
{
    Front = 0;
    Rear = MAXSIZE-1;
    Count = 0;
}

int  emptyQ()
{
    return Count == 0;
}
int  isFull(void)
{
    return Count == MAXSIZE;
}

void enQueue(int queue[ ], int item)
{
    if(isFull())                       /* 队满，插入失败 */
        printf("Full queue!");
    else{                              /* 队未满，插入成功 */
        Rear = (Rear+1) % MAXSIZE;
        queue[Rear]=item;
        Count++;
    }
}

int  deQueue(int queue[ ])
{
    int e;
        e=queue[Front];
        Count--;
        Front = (Front+1) % MAXSIZE;
        return e;

    return 0;
}

void BFS(VLink G[], int v){
ELink *p;
initQueue();
if(v!=x)
printf("%d ",v); //访问当前顶点
Visite[v] = 1; //标识某顶点被访问过
enQueue(Q, v);
while (!emptyQ(Q)) { // @@ emptyQ() is defined with no parameters, but called with Q here. Causes compilation error.
v = deQueue(Q); //取出队头元素
p = G[v].link; //获取该顶点第一个邻接顶点
//访问该顶点下的每个邻接顶点
for (; p != NULL; p = p->next)
if (!Visite[p->adj]) {
    if(v!=x) // @@ Checks the dequeued vertex v instead of the neighbor p->adj. Should be if(p->adj != x)
printf("%d ",p->adj); //访问当前顶点
Visite[p->adj] = 1; //标识某顶点被访问过
enQueue(Q, p->adj);
}
}
}
int main()
{
    int m;
    scanf("%d",&m); // @@ Input format is "n m", should read both n and m here. n is global, m should be global or passed correctly.
    createGraph(a);
    
    travelDFS(a, m); // @@ Passes m (number of edges) as the vertex count n. Should pass the actual number of vertices.
    printf("\n");
    travelBFS(a, m); // @@ Same as above, passes m instead of vertex count.
    printf("\n");
    scanf("%d",&x);
    create(c);
    travelDFS(c, m); // @@ Same as above, passes m instead of vertex count.
    printf("\n");
    travelBFS(c, m); // @@ Same as above, passes m instead of vertex count.
}