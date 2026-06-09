#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	int num;
	struct edge *Next;
} Node;

typedef struct edge
{
	int node_num;
	struct edge *Next;
} Edge;
Edge *EdgePtr_1,*EdgePtr_2;

typedef struct queue
{
	int node_num; 
	struct queue *Next;
} Queue; 

void create(Node [],int,int);
void depth_first_search(Node,int);
void breadth_first_search(Node,int);

int visited_flag[100];
Node node_array[101];
int del_node_num;

int main()
{
	int i,node_num,edge_num,node_1,node_2;
	scanf("%d %d",&node_num,&edge_num);
	for(i=0;i<=node_num-1;i=i+1)
	{
		node_array[i].num=i;
		node_array[i].Next=NULL;
	}
	for(i=1;i<=edge_num;i=i+1)
	{
		scanf("%d %d",&node_1,&node_2);
		create(node_array,node_1,node_2);
		create(node_array,node_2,node_1);
	}
	scanf("%d",&del_node_num);
	memset(visited_flag,0,sizeof(visited_flag));
	for(i=0;i<=node_num-1;i=i+1)
	{
	    if(visited_flag[i]==0)
	    {
			depth_first_search(node_array[i],-1);
		}	
	}
	printf("\n");
	memset(visited_flag,0,sizeof(visited_flag));
	for(i=0;i<=node_num-1;i=i+1)
	{
		if(visited_flag[i]==0)
		{
			breadth_first_search(node_array[i],-1);
		}
	}
	printf("\n");
	memset(visited_flag,0,sizeof(visited_flag));
	for(i=0;i<=node_num-1;i=i+1)
	{
		if(i==del_node_num) continue;
		if(visited_flag[i]==0)
		{
			depth_first_search(node_array[i],del_node_num);
		}	
	}
	printf("\n");
	memset(visited_flag,0,sizeof(visited_flag));
	for(i=0;i<=node_num-1;i=i+1)
	{
		if(i==del_node_num) continue;
		if(visited_flag[i]==0)
		{
			breadth_first_search(node_array[i],del_node_num);
		}
	}
}

void create(Node node_array[],int node_a,int node_b)
{
	if(node_array[node_a].Next==NULL)
	{
		EdgePtr_1=(Edge *) malloc(sizeof(Edge));
		EdgePtr_1->node_num=node_b;
		EdgePtr_1->Next=NULL;
		node_array[node_a].Next=EdgePtr_1;
	}
	else if(node_array[node_a].Next->node_num>node_b)
	{
		EdgePtr_2=(Edge *) malloc(sizeof(Edge));
		EdgePtr_2->node_num=node_b;
		EdgePtr_2->Next=node_array[node_a].Next;
		node_array[node_a].Next=EdgePtr_2;
	}
	else
	{
		EdgePtr_1=node_array[node_a].Next;
		while(EdgePtr_1->Next!=NULL)
		{
			if(EdgePtr_1->Next->node_num>node_b)
			{
				EdgePtr_2=(Edge *) malloc(sizeof(Edge));
				EdgePtr_2->node_num=node_b;
				EdgePtr_2->Next=EdgePtr_1->Next;
				EdgePtr_1->Next=EdgePtr_2;
				break;
			}
			EdgePtr_1=EdgePtr_1->Next;
		}
		if(EdgePtr_1->Next==NULL)
		{
			EdgePtr_2=(Edge *) malloc(sizeof(Edge));
			EdgePtr_2->node_num=node_b;
			EdgePtr_2->Next=NULL;
			EdgePtr_1->Next=EdgePtr_2;
		}
	}
}

void depth_first_search(Node node,int flag)
{
	Edge *EdgeTempPtr;
	visited_flag[node.num]=1;
	if(node.num==0)
	{
		printf("%d",node.num);
	}
	else 
	{
		printf(" %d",node.num);
	}
	EdgeTempPtr=node.Next;
	while(EdgeTempPtr!=NULL)
	{
		if(EdgeTempPtr->node_num==flag)
		{
			EdgeTempPtr=EdgeTempPtr->Next; 
			continue;
		}
		if(visited_flag[EdgeTempPtr->node_num]==0)
		{
			depth_first_search(node_array[EdgeTempPtr->node_num],flag);
		}
		EdgeTempPtr=EdgeTempPtr->Next; 
	}
}

void breadth_first_search(Node node,int flag)
{
	int t=0;
	Queue *QueuePtr_1,*QueuePtr_2,*QueuePtr_3;
	QueuePtr_1=(Queue *)malloc(sizeof(Queue));
	QueuePtr_1->node_num=node.num;
	QueuePtr_1->Next=NULL;
	while(QueuePtr_1!=NULL)
	{
		printf("%d ",QueuePtr_1->node_num);
		visited_flag[QueuePtr_1->node_num]=1;
		EdgePtr_1=node_array[QueuePtr_1->node_num].Next;
		while(EdgePtr_1!=NULL)
		{
			if(EdgePtr_1->node_num==flag) 
			{
				EdgePtr_1=EdgePtr_1->Next;
				continue;
			}
			else if(visited_flag[EdgePtr_1->node_num]==0)
			{
				t=t+1;
				if(t==1)
				{
					QueuePtr_2=(Queue *)malloc(sizeof(Queue));
					QueuePtr_2->node_num=EdgePtr_1->node_num;
					QueuePtr_2->Next=NULL;
					QueuePtr_1->Next=QueuePtr_2;
				}
				else
				{
					QueuePtr_3=(Queue *)malloc(sizeof(Queue));
					QueuePtr_3->node_num=EdgePtr_1->node_num;
					QueuePtr_3->Next=NULL;
					QueuePtr_2->Next=QueuePtr_3;
					QueuePtr_2=QueuePtr_3;
				}
				visited_flag[EdgePtr_1->node_num]=1;
				EdgePtr_1=EdgePtr_1->Next;
			}	
			else
			{
				EdgePtr_1=EdgePtr_1->Next;
			}
		}
		QueuePtr_1=QueuePtr_1->Next;
	}
} 

