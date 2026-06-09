#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//课件上的代码也是真尼玛乱 到底什么类型压 臭傻逼 
int Visited[100] = {0}, deletarg, point[111][2];
int Q[1000];
int front = 0, rear = -1;
 
int cmp(const void *p1, const void *p2)
{
	int *a = (int *)p1;
	int *b = (int *)p2;
	return a[0]-b[0];
}
typedef struct  edge{ 
       int  adj;
       struct edge  *next;
}ELink;
typedef struct ver{
       int  vertex;
       ELink  *link;
}VLink;
VLink  G[111];

ELink  *insertEdge(ELink *head, int avex)//得生成有序链表 
{
    ELink *e,*p, *q = NULL;
    e =(ELink *)malloc(sizeof(ELink));
    e->adj= avex; e->next = NULL;
    if(head == NULL)  { //head=e; return head; }
		return e;
	}
    //for(p=head; p->next != NULL&& avex > p->adj; q = p,p=p->next)
    for(p=head; p != NULL&& avex > p->adj; q = p,p=p->next)
        ;
    if( p == head)
	{  
	    e->next = p;
	    return e;
    }
    else
    {
    	q->next = e;
    	e->next = p;  
    	return head;
	}
    
}
int isempty()
{
	return (rear == front-1);
}
void enqueue(int q[], int item)
{
	q[++rear] = item;
}
int dequeue(int q[])
{
	 if(isempty())                    
        printf("Empty queue!");
        else
        {
        	return q[front++];
		}
      
}

void DFS(VLink  G[ ], int v)
{
    ELink  *p;
    Visited[v] = 1; //标识某顶点被访问过
    printf("%d ", v); 
    for(p = G[v].link; p !=NULL;  p=p->next)
         if( !Visited[p->adj] )//为啥有的反了？ 
             DFS(G, p->adj);
}
void  travelDFS(VLink  G[ ], int n)
{
    int i;
    //for(i=0; i<n; i++) Visited[i] = 0 ;
    for(i=0; i<n; i++)
        if( !Visited[i] ) DFS(G, i);
}

void BFS(VLink  G[ ], int v)
{
    ELink  *p;
    front = 0;rear = -1;
    Visited[v] = 1; //标识某顶点已入队
    enqueue(Q, v);
    while( !isempty()){
         v = dequeue(Q);  //取出队头元素
         printf("%d ", v); //访问当前顶点
         for(p=G[v].link; p!=NULL; p=p->next ) //访问该顶点的每个邻接顶点
             if( !Visited[p->adj] ) {
                    Visited[p->adj] = 1; //标识某顶点入队
                    enqueue(Q, p->adj);
           }
     }
}
void  travelBFS(VLink  G[ ], int n)
{
    int i;
    //for(i=0; i<n; i++) Visited[i] = 0 ;
    for(i=0; i<n; i++)
        if( !Visited[i] ) BFS(G, i);
}


int main()
{
	int npoint = 0, nduan = 0, i, v1, v2;
	scanf("%d%d", &npoint, &nduan);
	for (i = 0; i < nduan; i++)
	{
		//scanf("%d%d", &point[i][0], &point[i][1]);
		scanf("%d %d",&v1,&v2);
        G[v1].link=insertEdge(G[v1].link, v2);
        G[v2].link=insertEdge(G[v2].link, v1);
	}
	//qsort(point, nduan, 8, cmp);
	/*for (i = 0; i < nduan; i++)
	{
		//scanf("%d%d", &v1, &v2);
		//G[point[i][0]].link=insertEdge(G[point[i][0]].link, point[i][1]);//link是NULL 跟开玩笑一样搞喜 先4后3什么鬼 
     		//G[v2].link=insertEdge(G[v2].link, v1);
		//G[point[i][0]].link=insertEdge(G[point[i][0]].link, point[i][1]);//link是NULL 跟开玩笑一样搞喜 先4后3什么鬼 
     	//G[v2].link=insertEdge(G[v2].link, v1);
     	G[point[i][0]].link=insertEdge(G[point[i][0]].link, point[i][1]);
     	G[point[i][1]].link=insertEdge(G[point[i][1]].link, point[i][0]);
	}*/
	scanf("%d", &deletarg);
	memset(Visited, 0, sizeof(Visited));
	travelDFS(G, npoint);//这还跟读入顺序有关 做你妈 
	printf("\n");
	memset(Visited, 0, sizeof(Visited));
	travelBFS(G, npoint);//这还跟读入顺序有关 做你妈 
	printf("\n");
	
	
	memset(Visited, 0, sizeof(Visited));
	Visited[deletarg] = 1;
	travelDFS(G, npoint);
	printf("\n");
	memset(Visited, 0, sizeof(Visited));
	Visited[deletarg] = 1;
	travelBFS(G, npoint);
	printf("\n");
	return 0;
}


