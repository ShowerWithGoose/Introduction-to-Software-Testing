#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXV 200
typedef struct edge
{
    int adjvex;
    struct edge*Enext;
}Enode,*Enodeptr;//边结点类型
typedef struct ver
{
    int vertex;
    struct edge*Vnext;
}Vnode;//顶点类型

Vnode G[MAXV];
int Visited[MAXV];
int Q[MAXV];//队
int Front=0,Rear=MAXV-1,count=0;
int n;//顶点数


void opera(int target,int pos)//将target插到顶点pos的邻接链表中
{
    Enodeptr p;
    Enodeptr tmp;
    tmp=(Enodeptr)malloc(sizeof(Enode));
    tmp->adjvex=target;
    tmp->Enext=NULL;
    if(G[pos].Vnext==NULL||target<(G[pos].Vnext->adjvex))
    {
        tmp->Enext=G[pos].Vnext;
        G[pos].Vnext=tmp;
    }
    else
        for(p=G[pos].Vnext;;p=p->Enext)
            if(p->Enext==NULL||target<(p->Enext->adjvex))
            {
                tmp->Enext=p->Enext;
                p->Enext=tmp;
                break;
            }
}

void DFS(Vnode G[], int v)//从某个顶点出发，进行深度遍历
{
    Enodeptr p;
    Visited[v] = 1;
    printf("%d ",v);
    for(p = G[v].Vnext; p !=NULL;  p=p->Enext)
         if( !Visited[p->adjvex] )
             DFS(G, p->adjvex);
}

void  travelDFS(Vnode G[ ], int num)//对图进行深度遍历
{
    int i;
    for(i=0; i<num; i++)
    {
        if(G[i].Vnext==NULL)
            continue;
        if(!Visited[i]) 
            DFS(G, i);
    }
}
        

void enQueue(int Q[],int target)//入队
{
    Rear = (Rear+1) % MAXV; 
    Q[Rear]=target;
    count++;
}

int deQueue(int Q[])//取出队尾的元素
{
    int e;
    e=Q[Front];
    count--;                   
    Front = (Front+1) % MAXV;
    return e;
}

int emptyQ(int Q[])//判断队列是否为空
{
    return count==0;
}

void BFS(Vnode  G[], int v)//从某个顶点出发对图进行广度遍历
{
    Enodeptr p;
    printf("%d ",v);
    Visited[v] = 1; //标识某顶点被访问过
    enQueue(Q, v);         // 入口的第一个顶点入队
    while( !emptyQ(Q))//  循环，直到队空为止
    {   
        v = deQueue(Q);  //取出队头元素
        p = G[v].Vnext;         //获取该顶点第一个邻接顶点
        for(; p != NULL ; p = p->Enext ) //访问该顶点下的每个邻接顶点
            if( !Visited[p->adjvex] ) 
            {
                if(G[p->adjvex].Vnext!=NULL)
                    printf("%d ",p->adjvex);
                Visited[p->adjvex] = 1; //标识某顶点被访问过
                enQueue(Q, p->adjvex); //邻接顶点依次分别入队
            }
    }
}

void  travelBFS(Vnode  G[ ], int num)//对图进行广度遍历
{
    int i;
    for(i=0; i<num; i++)
    {
        if(G[i].Vnext==NULL)
            continue;
        if( !Visited[i] ) 
            BFS(G, i);
    }       
}

void delete_node(Enodeptr p)//删除单链表中的结点
{
    Enodeptr tmp;
    tmp=p->Enext;
    if(tmp==NULL)
    {
        p->Enext=NULL;
        free(tmp);
    }
    else
    {
        p->Enext=tmp->Enext;
        free(tmp);
    }
}

Delete(int target)//删除图中的顶点
{
    int i;
    Enodeptr p;
    G[target].Vnext=NULL;//先让对应的顶点数组的元素为空
    for(i=0;i<n;i++)
    {
        if(i==target)
            continue;
        if(G[i].Vnext->adjvex == target)//删除单链表的头指针
        {
            p=G[i].Vnext;
            G[i].Vnext=p->Enext;
            free(p);
        }          
        else
            for(p=G[i].Vnext;p->Enext!=NULL;p=p->Enext)
                if(p->Enext->adjvex==target)
                {
                    delete_node(p);
                    break;
                }
                    
    }
}

int main()
{
    int e,target;//n为顶点数,e为边的个数
    int i,a,b;
    Enodeptr p;
    scanf("%d%d",&n,&e);
    for(i=0;i<n;i++)
        G[i].vertex=i;
    for(i=0;i<e;i++)
    {
        scanf("%d%d",&a,&b);
        opera(a,b);
        opera(b,a);
    }
    scanf("%d",&target);

    travelDFS(G,n);
    printf("\n");   
    memset(Visited,0,sizeof(Visited));   
    travelBFS(G,n);
    printf("\n");   
    memset(Visited,0,sizeof(Visited));

    Delete(target);
    /*for(i=0;i<n;i++)
    {
        printf("%d: ",G[i].vertex);
        for(p=G[i].Vnext;p!=NULL;p=p->Enext)
            printf("%d ",p->adjvex);
        printf("\n");
    }*/
    Front=0,Rear=MAXV-1,count=0;
    travelDFS(G,n);
    memset(Visited,0,sizeof(Visited));
    printf("\n");
    travelBFS(G,n);
    system("pause");
    return 0;
}


