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
e =(ELink *)malloc(sizeof(ELink));
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
scanf("%d",&n); // @@ [The input format expects two integers (n and m) on the first line, but this only reads one. This causes misalignment in reading edges.]
for(i=0; i<n; i++){
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
for(i=0; i<n; i++){
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
for (i = 0; i < n; i++)
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
for (i = 0; i < n; i++)
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
while (!emptyQ(Q)) {
v = deQueue(Q); //取出队头元素
p = G[v].link; //获取该顶点第一个邻接顶点
//访问该顶点下的每个邻接顶点
for (; p != NULL; p = p->next)
if (!Visite[p->adj]) {
    if(v!=x)
printf("%d ",p->adj); //访问当前顶点 // @@ [This condition checks 'v != x', but it should check 'p->adj != x' to avoid printing the deleted vertex.]
Visite[p->adj] = 1; //标识某顶点被访问过
enQueue(Q, p->adj);
}
}
}
int main()
{
    int m;
    scanf("%d",&m);    // @@ [Only reads 'm' (number of edges), but should read both 'n' (vertices) and 'm' (edges). This causes all subsequent logic to use wrong 'n'.]
    createGraph(a);
    
    travelDFS(a, m);
    printf("\n");
    travelBFS(a, m);
    printf("\n");
    scanf("%d",&x);
    create(c);
    travelDFS(c, m);
    printf("\n");
    travelBFS(c, m);
}