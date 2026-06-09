#include<stdio.h>// (无向)图的遍历模板 邻接表实现插入删除遍历 
#include<stdlib.h>
#include<string.h>
#define MAXN 1005
#define MOD 1005
//深度优先遍历和广度优先遍历 
typedef struct edge//边结点结构
{	
       //int  eno; 	//边序号 不需要 
       int  adjvex;	//邻接顶点
       int  weight;	//边的权重 
       struct edge  *next;
} Edge;

typedef struct ver 
{	 //顶点结构，邻接表下标即为顶点序号
       struct edge  *link;//无实在意义 
} Ver;

Ver list[MAXN]; //rlist[MAXN];//邻接表和逆向邻接表 
int flag[MAXN], Queue[MAXN], front, rear, len;//无向图要设置标记 

void dfs(int num);

void bfs(int num);

void remov(int num);

void del(int n);

void queue_init();

void ins(int pre, int nxt, Ver arr[]);

void judge();

int main()
{
	//freopen("graphSearch_in.txt", "r", stdin);
	int i, n, m, pre, nxt, loc;
	//Edge *p = NULL, *q = NULL, *r = NULL;
	for (i = 0; i <= 205; i++)
	{
		list[i].link = NULL;
		//rlist[i].link = NULL;//初始化 
	}
	scanf("%d%d", &n, &m);
	for (i = 1; i <= m; i++)
	{	
		scanf("%d%d", &pre, &nxt);
		ins(pre, nxt, list);
		ins(nxt, pre, list);
		//ins(nxt, pre, rlist);//ins_back
	}//完成图的建立 
	
	scanf("%d", &loc);
	
	memset(flag, 0, sizeof(flag));
	dfs(0);//1
	printf("\n");
	memset(Queue, 0, sizeof(Queue));
	queue_init();//记得存队列模板 
	memset(flag, 0, sizeof(flag));
	bfs(0);//2
	printf("\n");
	//删去某个节点 
	remov(loc);
	memset(flag, 0, sizeof(flag));
	dfs(0);//1
	printf("\n");
	memset(Queue, 0, sizeof(Queue));//充值
	queue_init();
	memset(flag, 0, sizeof(flag));
	bfs(0);//2
	printf("\n");
	
	del(n);//
	return 0;
	//fclose(stdin);
}

void dfs(int num)
{
	flag[num] = 1;
	printf("%d ", num);
	Edge *p = list[num].link;
	while (p != NULL)
	{
		if (flag[p->adjvex] == 0)
		{
			dfs(p->adjvex);//继续遍历 
		}
		
		p = p->next;
	}
} 

void bfs(int num)
{
	Edge *p = NULL;
	int top;
	len++;
	judge();
	rear = (rear + 1) % MOD;
	Queue[rear] = num;
	while (len > 0)
	{			
		top = Queue[front];
		printf("%d ", top);
		len--;
		judge();
		front = (front + 1) % MOD;
		p = list[top].link;
		flag[top] = 1;
		while (p != NULL)
		{
			if (flag[p->adjvex] == 0)
			{
				flag[p->adjvex] = 1;//放入遍历的队列中 
				len++;
				judge();
				rear = (rear + 1) % MOD;
				Queue[rear] = p->adjvex;
			}
			p = p->next;
		}
	}
}

void remov(int num)
{
	Edge *p = list[num].link, *q = NULL, *r = NULL, *t = NULL;
	list[num].link = NULL;
	while (p != NULL)
	{
		q = p;
		p = p->next;
		r = list[q->adjvex].link;
		t = NULL;
		while (r != NULL)
		{
			
			if (r->adjvex == num)
			{
				break;
			}
			t = r;
			r = r->next;
		}
		if (r != NULL)
		{
			if (t == NULL)
			{
				list[q->adjvex].link = r->next;
				free(r); 
			}
			else
			{
				t->next = r->next;
				free(r);
			}	 
		}
		free(q);//删除出度
	}
	//销毁入度和出度 
}

void del(int n)//图的销毁 
{
	Edge *p = NULL, *q = NULL;
	int i;
	for (i = 0; i <= n - 1; i++)
	{
		p = list[i].link;
		while (p != NULL)
		{
			q = p;
			p = p->next;
			free(q);//熟悉链表操作//提取模板 
		}
	}
}

void queue_init()
{
	len = 0;
	front = 0;
	rear = -1;
}

void ins(int pre, int nxt, Ver arr[])
{
	Edge *p = NULL, *q = NULL, *r = NULL;
		
	q = arr[pre].link;
	p = (Edge*)malloc(sizeof(Edge));
	p->adjvex = nxt;
	p->next = NULL;
	if (q == NULL)
	{
		arr[pre].link = p;
		return;
	}
	while (q != NULL)
	{
		if (p->adjvex <= q->adjvex)//稳定性 
		{
			break;
		}
		r = q;
		q = q->next;
	}
	if (r == NULL)//最前面 
	{
		p->next = q;
		arr[pre].link = p;
	}
	else
	{//r为q的前缀 
		p->next = q; 
		r->next = p;
	}
}

void judge()
{
	if (len > MOD)
	{
		printf("ERROR THE QUEUE IS FULL\n");
	}
	else if (len < 0)
	{
		printf("ERROR THE QUEUE IS EMPTY\n");
	}
}

/***
if (len > MOD)
{
	printf("ERROR THE QUEUE IS FULL\n");
}
***/

