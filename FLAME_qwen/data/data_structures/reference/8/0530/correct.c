#include <stdio.h>
#include <stdlib.h>
typedef struct first {
	int goal;
	struct first* next;
}edge,*ptredge;
typedef struct second {
	ptredge link;
}head;
head in[110] = { NULL };
int visit[110] = { 0 };
int queue[110] = { 0 }, rear = -1, front = 0;
void insert(int start, int end);
void travelDFS(int n);
void travelBFS(int n);
void DFS(int v);
void BFS(int v);

int main()
{
	ptredge p;
	int num_point, num_edge,st ,end,i,num_del;
	scanf("%d %d", &num_point, &num_edge);
	for (i = 0; i < num_edge; i++)
	{
		scanf("%d %d", &st, &end);
		insert(st, end);
		insert(end, st);
	}
	scanf("%d", &num_del);//以上步骤没毛病
	//表创建完毕
	travelDFS(num_point);
	memset(visit, 0, sizeof(visit));
	travelBFS(num_point);
	memset(visit, 0, sizeof(visit));
	//删除操作
	visit[num_del] = 1;
	travelDFS(num_point-1);
	memset(visit, 0, sizeof(visit));
	visit[num_del] = 1;
	travelBFS(num_point-1);
	memset(visit, 0, sizeof(visit));
	return 0;
}
void insert(int start, int end)
{
	if (in[start].link == NULL)
	{
		in[start].link = (ptredge)malloc(sizeof(edge));
		in[start].link->goal = start;
		in[start].link->next = NULL;
	}
	ptredge p,q;
	p = (ptredge)malloc(sizeof(edge));
	p->goal = end; p->next = NULL;
	if (in[start].link->next == NULL)
		in[start].link->next = p;
	else//要求有序插入
	{
		for (q = in[start].link; q->next != NULL; q = q->next)
			if(p->goal < q->next->goal)
			{ 
				p->next = q->next;//由小到大插入
				q->next = p;
				return;
			}
		q->next = p;
	}
}

void travelDFS(int n)
{
	int i;
	for (i = 0; i < n; i++)
		if (!visit[i])
			DFS(i);
	printf("\n");
}

void travelBFS(int n)
{
	int i;
	for (i = 0; i < n; i++)
		if (!visit[i])
			BFS(i);
	printf("\n");
}

void DFS(int v)
{
	ptredge p;
	visit[v] = 1;
	printf("%d ", v);
	for (p = in[v].link; p != NULL; p = p->next)
		if(!visit[p->goal])
			DFS(p->goal);
}

void BFS(int v)
{
	ptredge p;
	visit[v] = 1;
	printf("%d ", v);
	queue[++rear] = v;
	while (front <= rear)
	{
		v = queue[front++];
		p = in[v].link;
		for(;p!=NULL;p=p->next)
			if (!visit[p->goal])
			{
				queue[++rear] = p->goal;
				printf("%d ", p->goal);
				visit[p->goal] = 1;
			}
	}
}
