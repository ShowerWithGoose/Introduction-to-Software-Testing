#include<stdio.h>
struct knot{
	int id;
	struct knot *connect[105];
	int visited;
};
struct knot Knot[105];
struct knot *p;
void build(int id1,int id2);
void DFS(struct knot *p);
void BFS(struct knot *q);
struct knot *queue[10000];
int front=0;
int rear=-1;	
int n,e;
int main()
{

	int i,j,k;
    int id1,id2,delid;
    int count;
	scanf("%d %d",&n,&e);
	for(i=0;i<n;i++)	
	{
		Knot[i].id=i;
		Knot[i].visited=0;
	}
	for(i=0;i<e;i++)
	{
		scanf(" %d %d",&id1,&id2);
		build(id1,id2);
	}
	scanf("%d",&delid);
	DFS(&Knot[0]);
	putchar('\n');
	for(i=0;i<n;i++) Knot[i].visited=0;
	BFS(&Knot[0]);
	putchar('\n');
	for(i=0;i<n;i++) Knot[i].connect[delid]=NULL;
	for(i=0;i<n;i++) Knot[i].visited=0;
	DFS(&Knot[0]);
	putchar('\n');
	front=0;rear=-1;
	for(i=0;i<n;i++) Knot[i].visited=0;
	BFS(&Knot[0]);
	return 0;	
 }
void build(int id1,int id2)
{
	Knot[id1].connect[id2]=&Knot[id2];
	Knot[id2].connect[id1]=&Knot[id1];
	return;
} 
void DFS(struct knot *p)
{
	int i;
	printf("%d ",p->id);
	p->visited=1;
	for(i=0;i<n;i++)	
	if(p->connect[i]!=NULL&&p->connect[i]->visited==0) DFS(p->connect[i]);
	return;
}
void BFS(struct knot *p)
{
    int i;
	p->visited=1;
    queue[++rear]=p;
    while(front<=rear)
    {
    	printf("%d ",queue[front]->id);
    	front++;
    	for(i=0;i<n;i++)
    	{
    		if(queue[front-1]->connect[i]!=NULL&&queue[front-1]->connect[i]->visited==0)
    		{
    			queue[front-1]->connect[i]->visited=1;
    		    queue[++rear]=queue[front-1]->connect[i];
			}		
		}
	}
	return;
}



