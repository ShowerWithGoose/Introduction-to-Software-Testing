#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAXSIZE   200
typedef struct edge{
       int  num;
       struct edge *next;
 }Elink;

typedef struct ver{
      int   vertex;
      Elink *link;
}Vlink; 

int  Q[MAXSIZE];
int  Front=0, Rear=MAXSIZE-1,Count=0;
void enQueue(int queue[ ], int item)//入队 
{
       if(Count==MAXSIZE)                       /* 队满，插入失败 */  
             printf("Full queue!");
       else{
             Rear = (Rear+1) % MAXSIZE; 
             queue[Rear]=item;
             Count++;
                                             /* 队未满，插入成功 */ 
       }
 }
int  deQueue(int queue[ ])//出队 
{ 
  int  e;
       if(Count==MAXSIZE)
             printf("Empty queue!");     /* 队空，删除失败 */
       else{
             e=queue[Front];
             Count--;                             /* 队非空，删除成功 */
       Front = (Front+1)%MAXSIZE;
       return e;
       }
}



int Visited[110]={0};
void DFS(Vlink G[ ], int v)
{
    Elink  *p;
    Visited[v] = 1; //标识某顶点被访问过
    printf("%d ",v); //访问某顶点
    for(p = G[v].link; p !=NULL;  p=p->next)
         if( !Visited[p->num] )
             DFS(G, p->num);
}
void BFS(Vlink  G[ ], int v)
{
    Elink  *p;
    Visited[v] = 1; //标识某顶点已入队
    enQueue(Q, v);
    while( Count!=0){
         v = deQueue(Q);  //取出队头元素
         printf("%d ",v); //访问当前顶点
         for(p=G[v].link; p!=NULL; p=p->next ) //访问该顶点的每个邻接顶点
             if( !Visited[p->num] ) {
                    Visited[p->num] = 1; //标识某顶点入队
                    enQueue(Q, p->num);
           }
     }
}
struct edge* AdjustList(struct edge* prehead)//链表冒泡排序,按X的幂次从小到大排序 //prehead->link=head
{//配合画图进行解读很直观
	struct edge *p, *q,*tail;

	tail = NULL;

	while ((prehead->next->next) != tail)//如果5个数,第2个数都确定了,那么第1个数百分百也已经确定,首先确定的数是第5个数(最后一个数)
	{
		p = prehead;
		q = prehead->next;
		while (q->next != tail)//while循环结束后,调整已经完毕
		{
			if ((q->num) > (q->next->num))//比较数据 
			{
				p->next = q->next;
				q->next = q->next->next;
				p->next->next = q;//整体思路为先判断exp大小,满足后结点小时,让
				q = p->next;//结点连接完成后,将q返回至新的首结点
			}
			q = q->next;//p,q前往下一结点继续判断
			p = p->next;
		}
		tail = q;//将结束指针往前一格,经历一次遍历后,改变一个数的位置, 例如1 5 4 3 2 将2还原到5 需要三次遍历,每次遍历中不仅仅让2的位置变了,也让2后面的数变成递增的形式,也是满足了题目需求
		//即一次遍历确定一个数的位置
	}
	return prehead->next; 
}
int main()
{
	int n,m,i;
	int a,b;//边 
	int del;
	scanf("%d%d",&n,&m);//n--顶点数  m--边数 
	Vlink G[110];
	Elink *e,*p,*pre;
	for(i=0;i<=n-1;i++)
	G[i].link=NULL;
	for(i=1;i<=m;i++)
	{	
		scanf("%d%d",&a,&b);
		e=(struct edge *)malloc(sizeof(struct edge));
		e->num=b;
		e->next=NULL; 
		if(G[a].link==NULL)
		G[a].link=e;
		else
		{	
			for(p=G[a].link;p->next!=NULL;p=p->next)
			;
			p->next=e;
		}
	
		e=(struct edge *)malloc(sizeof(struct edge));
		e->num=a;
		e->next=NULL; 
		if(G[b].link==NULL)
		G[b].link=e;
		else
		{	
			for(p=G[b].link;p->next!=NULL;p=p->next)
			;
			p->next=e;
		}
		
	}	

	for(i=0;i<=n-1;i++)//排序 
	{	
		pre=(struct edge*)malloc(sizeof(struct edge));
		pre->next=G[i].link;
		G[i].link=AdjustList(pre); 
	}
	DFS(G,0);
	printf("\n");
	memset(Visited,0,sizeof(Visited));//将visited里元素清零 
	BFS(G,0);
	printf("\n");
	memset(Visited,0,sizeof(Visited));
	
	scanf("%d",&del);

	for(i=0;i<=n-1;i++)
	{	
		if(i==del)
		continue;
		
		p=(struct edge* )malloc(sizeof(struct edge));
		pre=(struct edge* )malloc(sizeof(struct edge));
		p=G[i].link; 
		pre->next=p;
		for(;p!=NULL;p=p->next,pre=pre->next)
		{	
			if(p->num==del)
			{	//printf("%d founded ",i);
				if(p==G[i].link)
				{	
					G[i].link=p->next;
					free(p);
					//printf("%d a\n",i);
					break;
					
				}
				else
				{	pre->next=p->next;
					free(p);
					//printf("%d b\n",i);
					break;
				}
			}
		}	
	} 

	DFS(G,0);
	printf("\n");
	memset(Visited,0,sizeof(Visited));//将visited里元素清零 
	BFS(G,0);
	printf("\n");
return 0;
} 

