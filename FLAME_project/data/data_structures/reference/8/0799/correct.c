#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*使用邻接表，邻接表中链表有序存储，懒惰删除*/
struct Vertex{
	int number;
	int isDelete,hasVisited;
	struct Vertex *next;
}Graph[110];
typedef struct Vertex* Vnode;

void enterGraph(int start,int end)
{
	/*边从start到end*/
	Vnode ptr=&Graph[start],tmp;
	Graph[start].number=start;
	for(;ptr->next!=NULL&&ptr->next->number<end;ptr=ptr->next);
	tmp=ptr->next;
	ptr->next=(Vnode)malloc(sizeof(struct Vertex));
	ptr->next->isDelete=0;
	ptr->next->number=end;
	ptr->next->hasVisited=0;
	ptr->next->next=tmp;
}

void DFS(int now)
{
	/*记得是从零开始*/
	printf("%d ",now);
	Graph[now].hasVisited=1;
	Vnode ptr=Graph[now].next;
	for(;ptr!=NULL;ptr=ptr->next){
		if(!Graph[ptr->number].isDelete&&!Graph[ptr->number].hasVisited){
			DFS(ptr->number);
		}
	}
}

void BFS(int start)
{
	Vnode Queue[110]={0};
	Vnode now,ptr;
	int head=0,tail=0;
	Queue[0]=&Graph[start];
	Graph[start].hasVisited=1;
	while(head<=tail){
		now=Queue[head++];
		printf("%d ",now->number);
		for(ptr=Graph[now->number].next;ptr!=NULL;ptr=ptr->next){
			if(!Graph[ptr->number].isDelete&&!Graph[ptr->number].hasVisited){
				Queue[++tail]=&Graph[ptr->number];
				Graph[ptr->number].hasVisited=1;  //入队就要置已访问为1，相当于 预定 ，否则会重复入队 
			}
		}
	}
}

void init_visited(int V)
{
	for(int i=0;i<V;i++){
		Graph[i].hasVisited=0;
	}
}

int main()
{
	int V,E,D,start,end;
	scanf("%d %d",&V,&E);
	for(int i=0;i<E;i++){
		scanf("%d %d",&start,&end);
		enterGraph(start,end);
		enterGraph(end,start);  //无向图！！ 
	}
	scanf("%d",&D);
	DFS(0);
	init_visited(V);
	printf("\n");
	BFS(0);
	init_visited(V);
	printf("\n");
	Graph[D].isDelete=1;
	DFS(0);
	init_visited(V);
	printf("\n");
	BFS(0);
	init_visited(V);
	printf("\n");
	return 0;
}

