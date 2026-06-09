#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
int N;
int line; 
#define MaxV 256
int Q[1000],front,rear,count;
typedef struct edge{ 
int adj;
struct edge *next;
}Elink;
typedef struct ver{
Elink *link;
}Vlink;
Vlink G[MaxV];
int Visited[120] = {0};
int emptyQ(void)
{
    return count==0;
 }
void enQueue(int queue[],int v)
{
    rear+=1;
    queue[rear]=v;
    count++;
 } 
int deQueue(int queue[])
{
    int m;
    m=queue[front];
    count--;
    front+=1;
    return m;
}
void DFS(Vlink G[], int v)
{
Elink *p;
Visited[v] = 1; //标识某顶点被访问过
VISIT(G, v); //访问某顶点
for (p = G[v].link; p != NULL; p = p->next)
if (!Visited[p->adj])
DFS(G, p->adj);
}
void BFS(Vlink G[], int v){
Elink *p;
 Visited[v] = 1;
 int i;
 VISIT(G, v);//访问当前顶点//标识某顶点被访问
front=0;
rear=999; // @@ [error: rear should be initialized to -1 (or 0) to avoid out-of-bounds write; setting to 999 causes first enQueue to write to Q[1000] which is outside the array of size 1000]
count=0;
enQueue(Q, v);
while (!emptyQ()) {
v = deQueue(Q); //取出队头元素
//访问该顶点下的每个邻接顶点
for (p=G[v].link; p != NULL; p = p->next)
if (!Visited[p->adj]) {
VISIT(G, p->adj); //访问当前顶点
Visited[p->adj] = 1; //标识某顶点被访问过
enQueue(Q, p->adj);
}
}
}
void travelDFS(Vlink G[], int n){
int i;
for (i = 0; i < n; i++)
Visited[i] = 0;
for (i = 0; i < n; i++)
if (!Visited[i])
DFS(G, i);
printf("\n");
}
void travelBFS(Vlink G[], int n)
{
int i;
for (i = 0; i < n; i++)
Visited[i] = 0;
for (i = 0; i < n; i++)
if (!Visited[i])
BFS(G, i);
printf("\n");
}
void travelDFS1(Vlink G[], int n,int k){
int i;
for (i = 0; i < n; i++)
Visited[i] = 0;
Visited[k]=1;
for (i = 0; i < n; i++)
if (!Visited[i])
DFS(G, i);
printf("\n");
}
void travelBFS1(Vlink G[], int n,int k)
{
int i;
for (i = 0; i < n; i++)
Visited[i] = 0;
Visited[k]=1;
for(i=0;i<1000;i++)
Q[i]=0;
for (i = 0; i < n; i++)
if (!Visited[i])
BFS(G, i);
printf("\n");
}
void VISIT(Vlink G[],int v)
{
    printf("%d ",v);
}
Elink *insertEdge(Elink *head,int avex)
{
    Elink *e,*p,*q=NULL;
    e =(Elink *)malloc(sizeof(Elink));
    e->adj= avex; 
    e->next=NULL;
    if(head == NULL){
    head=e;
    return head;
    }
for(p=head;p!= NULL&&avex>p->adj;q=p, p=p->next);
if(p==head)
{
    e->next=p;
    return e;
}
else
{
q->next=e;    
e->next = p; 
return head;    
}
}
int main(int argc, const char * argv[])
{
    scanf("%d",&N);
    scanf("%d\n",&line);
    int point;
    int i;
    int v1,v2;
    for(i=0;i<line;i++)
    {
        scanf("%d %d",&v1,&v2);
        G[v1].link=insertEdge(G[v1].link,v2);
        G[v2].link=insertEdge(G[v2].link,v1);
    }
    scanf("%d",&point);
    Elink *p;
    //for(i=0;i<N;i++)
    {
    //    for (p = G[i].link; p != NULL; p = p->next)
        {
            //printf("%d ",p->adj);
        }
    //    printf("\n"); 
    }
    travelDFS(G, N);
    travelBFS(G,N);
    travelDFS1(G,N,point);
    travelBFS1(G,N,point);
    return 0;
}