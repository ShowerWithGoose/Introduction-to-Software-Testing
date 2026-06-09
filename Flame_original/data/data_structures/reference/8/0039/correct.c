#include <stdio.h>
#include <stdlib.h>
#define MaxV    110
int  Visited[MaxV]={0}; //标记数组
typedef struct  edge //边结点
{
   int adj;
   struct edge *next;
}Elink;

typedef struct  ver
{
   Elink *link;
}Vlink;
Vlink  G[MaxV]; //顶点组

typedef struct qnode
{
    int num;
}Queue;
Queue Q[MaxV];
int Qtotal = 0, front = 0, rare = -1;

Elink  *insertEdge(Elink *head, int avex);
Elink  *Sort(Elink *head); //最小的在前面
void travelDFS(Vlink  G[], int n); //深度优先遍历
void DFS(Vlink  G[], int v);    //深度优先递归
void CleanVisited(int j);
void travelBFS(Vlink  G[], int n); //广度优先遍历
void BFS(Vlink  G[], int v);    //广度优先递归
void inQueue(int v);    //入队
int outQueue();         //出队
void DeleteV(int v,int Vnum);    //删除顶点
void DeleteV(int v, int Vnum)
{
    int i;
    Elink  *p, *pre=NULL;
    Visited[v] = -1;    //标记
    for(i=0; i<Vnum; i++)
    {
        pre = NULL; //初始化pre
        if(Visited[i] != -1)
        {
            for(p = G[i].link; p !=NULL; p = p->next)
            {
                if(p->adj == v)  //删除链结p
                {
                    if(pre == NULL)  //头链结需要删除，pre仍为空
                        G[i].link = p->next;
                    else    //把p->next接到pre后面，pre不变
                        pre->next = p->next;
                }
                else    //pre向后
                    pre = p;
            }
        }
    }
}
int main()
{
    int Vnum, Enum, i, v1, v2;
    scanf("%d %d",&Vnum,&Enum);
    for(i=0; i<Enum; i++)
    {
        scanf("%d %d",&v1,&v2);
        G[v1].link=insertEdge(G[v1].link, v2);
        G[v2].link=insertEdge(G[v2].link, v1);
    }
    for(i=0; i<Vnum; i++)
        G[i].link=Sort(G[i].link);
    travelDFS(G, Vnum);
    printf("\n");
    CleanVisited(Vnum);
    travelBFS(G, Vnum);
    printf("\n");
    CleanVisited(Vnum);
    while( (scanf("%d",&v1))!=EOF )
        DeleteV(v1,Vnum);
    travelDFS(G, Vnum);
        printf("\n");
    CleanVisited(Vnum);
    travelBFS(G, Vnum);
    return 0;
}

Elink  *insertEdge(Elink *head, int avex)
{
    Elink *e,*p;
    e =(Elink *)malloc(sizeof(Elink));
    e->adj = avex; e->next = NULL;
    if(head == NULL)
    {
        head=e;
        return head;
    }
    for(p=head; p->next != NULL; p=p->next);
    p->next = e;
    return head;
}

Elink  *Sort(Elink *headptr) //最小的在前面   头指针不为空的链表冒泡
{
    Elink *pre=NULL, *flag=NULL, *p = headptr, *temp;//pre代表前一个指针，flag用作循环变量
    int num;    //pre变量
    while(p != flag)
    {
        num=0;
        while((p->next) != flag)
        {
            if(p->adj > (p->next)->adj) //循环比较相邻两个的大小，按从小到大的排序
            {
                temp = (p->next);    //将所指向的第二指针头存储
                (p->next) = (p->next->next);    //将第三指针头接在第一指针头的后面
                temp->next = p;    //将第一指针头放在第二指针的后面
                if(num>0)   //此时pre才不为空
                    pre->next = temp;
                pre = temp;   //移动pre,向后移一位
                if(num == 0)    //若是头指针，将改变链表的头指针
                    headptr = temp;
            }
            else    //若不满足大小关系。两者都往移一位
            {
                pre = p;
                p = (p->next);
            }
            num++;//pre标记
        }
        flag = p;    //将flag每次都往前移一位，使次数尽量保证少
        p = headptr; //将p重新改为headptr链表头
    }
    return headptr;//返回排好序的链表
}

void travelDFS(Vlink  G[], int n) //深度优先遍历
{
    int i;
    for(i=0; i<n; i++)
    {
        if( Visited[i] == 0 && G[i].link!=NULL )
            DFS(G,i);
    }
}

void DFS(Vlink  G[], int v)    //深度优先
{
    Elink  *p;
    Visited[v] = 1; //标识某顶点被访问过
    printf("%d ",v);
    for(p = G[v].link; p !=NULL;  p=p->next)
    {
        if( Visited[p->adj] == 0 && G[p->adj].link!=NULL )
            DFS(G, p->adj);
    }
}

void CleanVisited(int j)    //数组归位
{
    int i;
    for(i=0; i<=j; i++)
    {
        if(Visited[i] == 1) //如果为-1，则为删除顶点
            Visited[i]=0;
    }
}

void travelBFS(Vlink  G[], int n) //广度优先遍历
{
    int i;
    for(i=0; i<n; i++)
    {
        if( Visited[i] == 0 && G[i].link!=NULL )
            BFS(G,i);
    }
}

void BFS(Vlink  G[], int v)    //广度优先 访问后入队 出队访问链结点
{
    Elink  *p;
    printf("%d ",v);
    Visited[v] = 1; //标识某顶点被访问过
    inQueue(v);  //入队
    while( front <= rare ) //队不为空
    {
        v = outQueue();  //取出队头元素
        p = G[v].link;  //获取该顶点第一个邻接顶点
        for(; p != NULL; p = p->next ) //访问该顶点下的每个邻接顶点
        {
            if( Visited[p->adj] == 0 )
            {
                printf("%d ",p->adj); //访问当前顶点
                Visited[p->adj] = 1; //标识某顶点被访问过
                inQueue(p->adj);
            }
        }
    }
}

void inQueue(int v)
{
    Q[++rare].num = v;
}

int outQueue()
{
    int v;
    v = Q[front++].num;
    return v;
}



