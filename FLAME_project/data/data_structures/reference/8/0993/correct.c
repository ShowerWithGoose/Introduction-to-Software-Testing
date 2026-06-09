#include<stdio.h>           
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
int visit[10003];//1表示已经访问过 
int delet[10003];//1表示已经删除 
int tou = 0,wei = -1;
int queue[10003];
struct edge{
	int adjvex;
	struct edge* next;
};
struct vertex{
	struct edge* link;
}v[10003];
void insert(int vertex1,int vertex2)
{
	struct edge* t,*p = NULL,*rear = NULL;
	t = (struct edge*)malloc(sizeof(struct edge));
	t->next = NULL;
	t->adjvex = vertex2;
	if(v[vertex1].link==NULL) v[vertex1].link = t;
	else{
		for(p = v[vertex1].link;p != NULL;p = p->next)
		{
			if(p->adjvex > vertex2) break;
			rear = p;//rear之后插入 
		}
		if(rear==NULL)//插到表头
		{
			t->next = v[vertex1].link;
			v[vertex1].link = t;
		} 
		else if(rear!=NULL)
		{
			t->next = rear->next;
			rear->next = t;
		}
	}//先把2边接到1顶点的后面
	rear = NULL;
	t = (struct edge*)malloc(sizeof(struct edge));
	t->next = NULL;
	t->adjvex = vertex1;
	if(v[vertex2].link==NULL) v[vertex2].link = t;
	else{
		for(p = v[vertex2].link;p != NULL;p = p->next)
		{
			if(p->adjvex > vertex1) break;
			rear = p;//rear之后插入 
		}
		if(rear==NULL)//插到表头
		{
			t->next = v[vertex2].link;
			v[vertex2].link = t;
		} 
		else if(rear!=NULL)
		{
			t->next = rear->next;
			rear->next = t;
		}
	}//再把1边接到2顶点的后面
}
void dfs(struct vertex v[],int sub)
{
	struct edge* p;
	visit[sub] = 1;
	printf("%d ",sub);
	for(p = v[sub].link;p != NULL;p = p->next)
	{
		if(visit[p->adjvex]==0&&delet[p->adjvex]==0)
		dfs(v,p->adjvex);
	}
}
void travel_dfs(struct vertex v[],int n)
{
	int i;
	for(i = 0;i < n;i ++){
		if(visit[i] == 0&&delet[i] == 0) dfs(v,i);
	}
	printf("\n");
}
void travel_bfs(struct vertex v[],int n)
{
	int i,sub;
	struct edge* p;
	for(i = 0;i < n;i ++){
		if(delet[i] == 0&&visit[i] == 0) {
			queue[++wei] = i;
			visit[i] = 1;
			break;
		}
	}
	while(tou <= wei){
		printf("%d ",queue[tou]);
		sub = queue[tou];
		tou ++;
		for(p = v[sub].link;p!=NULL;p=p->next){
			if(visit[p->adjvex]==0&&delet[p->adjvex]==0)
			{
				visit[p->adjvex] = 1;
				queue[++wei] = p->adjvex;
			}
		}
	}
	printf("\n");
}
int main(int argc,char * argv[])
{
	int sum_vertex,sum_edge,dele;
	scanf("%d%d",&sum_vertex,&sum_edge);
	int i,vertex1,vertex2;
	for(i = 0;i <= 10003;i ++){
		v[i].link = NULL;
	}
	for(i = 1;i <= sum_edge;i ++){
		scanf("%d%d",&vertex1,&vertex2);
		insert(vertex1,vertex2);
	}
	scanf("%d",&dele);
	travel_dfs(v,sum_vertex);
	for(i = 0;i < sum_vertex;i ++){
		visit[i] = 0;
	}
	travel_bfs(v,sum_vertex);
	tou = 0;
	wei = -1;
	for(i = 0;i < sum_vertex;i ++){
		visit[i] = 0;
	}
	delet[dele] = 1;//删除操作
	travel_dfs(v,sum_vertex);
	for(i = 0;i < sum_vertex;i ++){
		visit[i] = 0;
	}
	travel_bfs(v,sum_vertex);
	return 0;
}











