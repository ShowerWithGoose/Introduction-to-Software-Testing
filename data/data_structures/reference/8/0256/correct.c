#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>

int xiang=0;

int f2(char s[ ], char t[ ])
{
    int i, j, k;
    for(i = 0; s[i] != '\0'; i++){
        for(j=i,k=0;t[k]!='\0'&&s[j]==t[k]; j++,k++)
        ;
        if(t[k] == '\0')
            return ( i);
    }
    return ( -1);
}
int f3(char s[ ], char t[ ])
{
    int i, j, k;
    for(i = 0; s[i] != '\0'; i++){
        for(j=i,k=0;t[k]!='\0'&&s[j]==t[k]; j++,k++)
        ;
        if(t[k] == '\0')
            return ( i);
    }
    return ( -1);
}
int f4(char s[ ], char t[ ])
{
    int i, j, k;
    for(i = 0; s[i] != '\0'; i++){
        for(j=i,k=0;t[k]!='\0'&&s[j]==t[k]; j++,k++)
        ;
        if(t[k] == '\0')
            return ( i);
    }
    return ( -1);
}

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

int V, E; //顶点(vertex)数，边(edge)数

void f1(VLink graph[]);

void  hen(VLink  G[ ], int n, int delV);
void  travelBFS(VLink  G[ ], int n, int delV);
//在链表尾插入一个节点
//ELink  *insertEdge(ELink *head, int avex)
//{
//    ELink *e,*p;
//    e =(ELink *)malloc(sizeof(ELink));
//    e->adj= avex; e->wei=1; e->next = NULL;
//    if(head == NULL)  { head=e; return head; }
//    for(p=head; p->next != NULL; p=p->next)
//        ;
//    p->next = e;
//    return head;
//}

/* 设head是一个有序增序链表，将元素avex插入到相应位置上 */
ELink  *insertEdge(ELink *head, int avex)
{
    ELink *e,*p,*q = NULL;
    e =(ELink *)malloc(sizeof(ELink)); /* 创建一个数据项为avex的新结点 */
    e->adj= avex; e->wei=1; e->next = NULL;
    if(head == NULL)  /* head是一个空表 */
        return e;
    for(p=head; p != NULL && avex > p->adj;  q = p, p = p->next) /* 找到插入位置 */
        ;
    if( p == head){  /* 在头结点前插入 */
        e->next = p;
        return e;
    }
    else {           /* 在结点p前插入一个结点 */
        q->next = e;
        e->next = p;
        return head;
    }
}

void f1(VLink graph[])
{
    for(int i=0;i<E;i++)
    {
        int v1,v2;
        scanf("%d %d",&v1,&v2);
        graph[v1].link=insertEdge(graph[v1].link, v2);
        graph[v2].link=insertEdge(graph[v2].link, v1);
    }
}


int Visited[MaxV]={0}; //标识顶点是否被访问过，N为顶点数

/* 深度优先遍历 */
void DFS(VLink  G[ ], int v)
{
    ELink  *p;
    Visited[v] = 1; //标识某顶点被访问过
    printf("%d ", v);
    //VISIT(G, v); //访问某顶点
    for(p = G[v].link; p !=NULL;  p=p->next)
        if( !Visited[p->adj] )
            DFS(G, p->adj);
}

void  hen(VLink  G[ ], int n, int delV)
{
    int i;
    for(i=0; i<n; i++)
        Visited[i] = 0 ;
    if(delV >= 0)  //处理删除
        Visited[delV] = 1;
    for(i=0; i<n; i++)
        if( !Visited[i] ) DFS(G, i);
    printf("\n");
}


/* 广度优先遍历 */

//循环队列
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
    if(isEmpty())                    /* 队空，删除失败 */
        printf("Empty queue!");
    else{                            /* 队非空，删除成功 */
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
    initQueue();  //初始化队
    Visited[v] = 1; //标识某顶点已入队
    enQueue(Q, v);
    while( !isEmpty()){
        v = deQueue(Q);  //取出队头元素
        printf("%d ",v);
        //VISIT(G, v); //访问当前顶点
        for(p=G[v].link; p!=NULL; p=p->next ) //访问该顶点的每个邻接顶点
            if( !Visited[p->adj] ) {
                Visited[p->adj] = 1; //标识某顶点入队
                enQueue(Q, p->adj);
            }
    }
}

void  travelBFS(VLink  G[ ], int n, int delV)
{
    int i;
    for(i=0; i<n; i++)
        Visited[i] = 0 ;
    if(delV >= 0)  //处理删除
        Visited[delV] = 1;
    for(i=0; i<n; i++)
        if( !Visited[i] )
            BFS(G, i);
    printf("\n");
}


int main(int argc, const char * argv[]) {
    int ji=0;
    int ga=0;
    xiang=ji+ga;
    ji++;
    ga++;
    xiang++;
    scanf("%d %d",&V,&E); //输入图的顶点(vertex)个数和边(edge)的个数
    
    f1(G);//建立无向图，??需要排序！
    
    hen(G,V,-1);//-1表示不删除顶点
    travelBFS(G,V,-1);
    
    int k;
    scanf("%d",&k);//输入要删除的顶点编号
    
    hen(G,V,k);//删除k顶点，采用懒惰删除，即置Visted[k]=1
    travelBFS(G,V,k);
    xiang=0;
    return 0;
}


