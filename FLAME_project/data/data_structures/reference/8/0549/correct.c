#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
#define REP(i,a,b) for(register int i=a;i<=b;i++)
#define PER(i,a,b) for(register int i=a;i>=b;i--)
#define maxsize 100

typedef struct ENode
{
    int adjert;
    struct ENode *next;
} ENode;

typedef struct Node
{
    int num;
    ENode *next; 
}Node;

int BFSqueue[maxsize];
char Visited[maxsize];

void BFS(Node *,int);
void DFS(Node *,int);

void InsertNode(Node *,int,int);
void DeleteNode(Node *,int);

void OrderInsert(Node *,int);
int InsertQueue(int);
int OutQueue();


int Head=0,Rear=99,count=0;

int main()
{
	//读入顶点个数和边的个数 
    int node_number,side_number; 
    scanf("%d %d",&node_number,&side_number);
    Node NodeList[100]={0,NULL};
    
    //将结点的连接存储到图当中 
    int i; 
    for(i=0;i<=side_number-1;i++)//下标从0开始 
    {
    	//读入始末点，并将边插入到图（链表）当中 
        int node_from,node_to;
        scanf("%d %d",&node_from,&node_to);
        InsertNode(NodeList,node_from,node_to);
    }
    
    //输出删除给定结点前 按照深度优先遍历 
    DFS(NodeList,0);
    printf("\n"); 
    memset(Visited,0,100);
    
    //输出删除给定结点前 按照广度优先遍历
    BFS(NodeList,0);
    printf("\n");
    memset(Visited,0,100);
    
    //删除给定节点 
    int Delete;
    while(~scanf("%d",&Delete))
    DeleteNode(NodeList,Delete);
        
    //输出删除给定结点后 按照深度优先遍历 
    DFS(NodeList,0);
    printf("\n");
    memset(Visited,0,100);
    
    //输出删除给定节点后 按照广度优先遍历 
    BFS(NodeList,0);
    printf("\n");
}


void InsertNode(Node *NodeList,int node_from,int node_to)
{
    NodeList[node_from].num=node_from;
    NodeList[node_to].num=node_to;
    OrderInsert(&NodeList[node_from],node_to);
    OrderInsert(&NodeList[node_to],node_from);
    return;
}

void OrderInsert(Node *Head,int Insert)
{
    ENode *p,*ptr=NULL;
    
    //找到需要插入的位置 
    for (p=Head->next;p!=NULL&&p->adjert<Insert;ptr = p,p = p->next);
    
    if (p==NULL&&ptr!=NULL)//链表尾插入
    {
        ptr->next=(ENode*)calloc(1,sizeof(ENode));
        ptr->next->adjert=Insert;
    }
	else if (p==NULL&&ptr == NULL)//空表插入
    {
        Head->next=(ENode *)calloc(1,sizeof(ENode));
        Head->next->adjert=Insert;
    }
    else if (p->adjert>Insert)
    {
        if(ptr!=NULL)//中间插入
        {
            ENode *node_new=(ENode *)calloc(1,sizeof(ENode));
            ptr->next=node_new;
            node_new->adjert=Insert;
            node_new->next=p;
        }
        else
        {
            ENode *node_new=(ENode *)calloc(1,sizeof(ENode));
            node_new->next=Head->next;
            Head->next=node_new;
            node_new->adjert=Insert;
        }
    }
    return;
}

void DeleteNode(Node *NodeList,int Delete)
{
    NodeList[Delete].next = NULL;
    int i;
    for (i=0;i<=99;i++)
    {
        ENode *p=NodeList[i].next;
		ENode *ptr=NULL;
        while(p!=NULL)
        {
            if (p->adjert==Delete)
            {
                if (ptr==NULL)//链表头删除
                {
                    ptr=p;
                    NodeList[i].next=ptr->next;
                    free(p);
                }
                else
                {
                    ptr->next=p->next;
                    free(p);
                }
                break;
            }
            ptr=p;
            p=p->next;
        }
    }
    return;
}

void BFS(Node *NodeList,int start)
{
    Visited[start]=1;
    printf("%d ",NodeList[start].num);
    ENode *p=NodeList[start].next;
    while(p!=NULL)
    {
        if (Visited[NodeList[p->adjert].num]==0)
        {
            Visited[NodeList[p->adjert].num]=1;
            InsertQueue(NodeList[p->adjert].num);
        }
        p = p->next;
    }
    int next=OutQueue();
    if (next!=-1)
    BFS(NodeList,next);
}

int InsertQueue(int Insert)
{
    if (count != 100)
    {
    	Rear++;
        Rear=(Rear)%100;
        BFSqueue[Rear]=Insert; 
        count++;
        return 1;
    }
    return 0;
}

int OutQueue()
{
    if (count>0)
    {
        count--;
        Head=Head%100;
        return BFSqueue[Head++];
    }
    return -1;
}

void DFS(Node *NodeList,int start)
{
    Visited[start]=1;
    printf("%d ",NodeList[start].num);
    ENode *p=NodeList[start].next;
    while(p!=NULL)
    {
        if(Visited[p->adjert]==0)
        DFS(NodeList,p->adjert);
        p = p->next;
    }
    return;
}

