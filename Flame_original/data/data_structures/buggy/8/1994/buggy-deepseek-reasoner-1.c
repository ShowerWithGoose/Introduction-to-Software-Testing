#include <stdio.h>
#include <stdlib.h>

//图的邻接表定义
#define MaxV 256
typedef struct edge{
    int  adj;
    int  wei;
    struct edge  *next;
} ELink;

typedef struct ver{
    ELink  *link;
} VLink;
VLink  G[MaxV];

int V, E; 

void createGraph(VLink graph[]);

void  travelDFS(VLink  G[ ], int n, int delV);
void  travelBFS(VLink  G[ ], int n, int delV);

int main(int argc, const char * argv[]) {
    
    scanf("%d %d",&V,&E);
    
    createGraph(G);
    
    travelDFS(G,V,-1);
    travelBFS(G,V,-1);
    
    int k;
    scanf("%d",&k);
    
    travelDFS(G,V,k);
    travelBFS(G,V,k);
    
    return 0;
}

在链表尾插入一个节点 // @@ [语法错误，非法的C标识符]

ELink  *insertEdge(ELink *head, int avex)
{
    ELink *e,*p,*q = NULL;
    e =(ELink *)malloc(sizeof(ELink));
    e->adj= avex; e->wei=1; e->next = NULL;
    if(head == NULL) 
        return e;
    for(p=head; p != NULL && avex > p->adj;  q = p, p = p->next) 
        ;
    if( p == head){ 
        e->next = p;
        return e;
    }
    else {           
        q->next = e;
        e->next = p;
        return head;
    }
}

void createGraph(VLink graph[])
{
    for(int i=0;i<E;i++)
    {
        int v1,v2;
        scanf("%d %d",&v1,&v2);
        graph[v1].link=insertEdge(graph[v1].link, v2);
        graph[v2].link=insertEdge(graph[v2].link, v1);
    }
}


int Visited[MaxV]={0}; 


void DFS(VLink  G[ ], int v)
{
    ELink  *p;
    Visited[v] = 1; 
    printf("%d ", v);
    
    for(p = G[v].link; p !=NULL;  p=p->next)
        if( !Visited[p->adj] )
            DFS(G, p->adj);
}

void  travelDFS(VLink  G[ ], int n, int delV)
{
    int i;
    for(i=0; i<n; i++)
        Visited[i] = 0 ;
    if(delV >= 0)  
        Visited[delV] = 1;
    for(i=0; i<n; i++)
        if( !Visited[i] ) DFS(G, i);
    printf("\n");
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
int  isEmpty(void)
{
    return Count == 0;
}
int  isFull(void)
{
    return Count == MAXSIZE;
}
void enQueue(int queue[ ], int item)
{
    if(isFull())                      
        printf("Full queue!");
    else{                             
        Rear = (Rear+1) % MAXSIZE;
        queue[Rear]=item;
        Count++;
    }
}
int  deQueue(int queue[ ])
{
    int e;
    if(isEmpty())                    
        printf("Empty queue!");
    else{                           
        e=queue[Front];
        Count--;
        Front = (Front+1) % MAXSIZE;
        return e;
    }
    return 0;
}


void BFS(VLink  G[ ], int v)
{
    ELink  *p;
    initQueue();  
    Visited[v] = 1; 
    enQueue(Q, v);
    while( !isEmpty()){
        v = deQueue(Q);  
        printf("%d ",v);
       
        for(p=G[v].link; p!=NULL; p=p->next ) 
            if( !Visited[p->adj] ) {
                Visited[p->adj] = 1; 
                enQueue(Q, p->adj);
            }
    }
}

void  travelBFS(VLink  G[ ], int n, int delV)
{
    int i;
    for(i=0; i<n; i++)
        Visited[i] = 0 ;
    if(delV >= 0)  
        Visited[delV] = 1;
    for(i=0; i<n; i++)
        if( !Visited[i] )
            BFS(G, i);
    printf("\n");
}

------ // @@ [语法错误，非法的C语句]
Please directly output the complete annotated source code. Ensure that the number of lines in the source code remains unchanged; do not change the original code structure, formatting, or content in any way, do not cut off any part. This means you should not reformat the code, add or remove newlines, modify spacing, or insert additional comments except for the explicit error markers. // @@ [语法错误，非法的C语句]
Here is an example: // @@ [语法错误，非法的C语句]
the original line: // @@ [语法错误，非法的C语句]
        int a = 1; // @@ [语法错误，非法的C语句]
the annotated line: // @@ [语法错误，非法的C语句]
        int a = 1; // @@ [the reason for the error] // @@ [语法错误，非法的C语句]
 // @@ [语法错误，非法的C语句] (此行是空行，但原文本中有一个空行？实际用户消息中在"the annotated line:"之后有一个空行，然后"**Important:**..."，这里我们按用户提供的代码块处理。由于无法精确得知空行，我们假设每行都有内容。为了安全，我们将后续所有非空行都标记。)
**Important:** Enclose your entire source code output in a markdown code block with language specifier "c". That is, start with