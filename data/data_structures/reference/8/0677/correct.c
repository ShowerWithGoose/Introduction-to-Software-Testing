#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define maxv 1050
typedef struct edge{
	int adj;
	struct edge *next;
}Elink;
typedef struct ver{
	int ver;
	Elink *link;
}Vlink;
Vlink graph[maxv];
int visted[maxv];//已访问 
int queue[10*maxv];//广度优先队列 
int rear=-1,front=0,count=0;

void insert(int a,int b)
{
	Elink *p=(Elink*)malloc(sizeof(Elink));
	p->adj = b;
	p->next=NULL;
	Elink *head = graph[a].link;
	if(head==NULL){
		graph[a].link=p;
		return ;
	}else if(b<head->adj){
		p->next=graph[a].link;
		graph[a].link=p;
	}
	else{
		Elink* q;
		Elink* q0;
		for(q=head;q!=NULL;q0=q,q=q->next){
			if(b<q->adj){
				q0->next=p;	
				p->next=q;
				return ;
			}
		}
		q0->next=p;
	}
}
void deeporder(int num)//深度优先 
{
	Elink *temp = graph[num].link;
	visted[num]=1;
	printf("%d ",graph[num].ver);
	while(temp!=NULL)
	{
		if(visted[temp->adj]==0)
			deeporder(temp->adj);
		temp=temp->next;
	}
}
void enqueue(int a)//进队 
{
	queue[++rear] = a;
	count++;
	return ;
}
int dequeue()//出队 
{
	count--;
	return queue[front++];
}
void breathorder(int num)//广度优先 
{
	Elink *temp = graph[num].link;
	visted[num]=1;
	printf("%d ",graph[num].ver);
	enqueue(num);
	while(count>0)
	{
		num = dequeue();
		temp = graph[num].link;
		while(temp!=NULL)
		{
			if(visted[temp->adj]==0){
				printf("%d ",graph[temp->adj].ver);
				visted[temp->adj]=1;
				enqueue(temp->adj);
			}
			temp=temp->next;
		}
	}
}
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)//初始化 
	{
		graph[i].link=NULL;
		graph[i].ver=i;
	}
	for(int i=0;i<m;i++)//创建邻接链表 
	{
		int a,b;
		scanf("%d %d",&a,&b);
		insert(a,b);
		insert(b,a);
	}
	
	for(int i=0;i<n;i++)
		if(visted[i]==0)
			deeporder(i);//深度遍历 
	putchar(10);
	for(int i=0;i<n;i++)//初始化 
		visted[i]=0;
	for(int i=0;i<n;i++)
		if(visted[i]==0)
			breathorder(i);//广度遍历 
	putchar(10);

	int op;
	scanf("%d",&op);
	for(int i=0;i<n;i++){//去除op 
		if(i!=op)
			visted[i]=0;      
		else
			visted[i]=1;
	}
	rear=-1,front=0,count=0;//初始化 
	for(int i=0;i<105;i++)
		queue[i]=0;

	for(int i=0;i<n;i++)
		if(visted[i]==0)
			deeporder(i);//深度遍历

	putchar(10);
	for(int i=0;i<n;i++)//去除op
		if(i!=op)
			visted[i]=0;
		else         
			visted[i]=1;
	
	for(int i=0;i<n;i++)
		if(visted[i]==0)
			breathorder(i);//广度遍历      
	return 0;
}                      


