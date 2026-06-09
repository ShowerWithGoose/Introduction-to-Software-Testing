#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct line{
	int num;
	struct line *link;
};
struct d{
	struct line *head;
};
struct d list[110];
int now[110]={0};
void insert(int s,int e)
{
	struct line *p,*q,*r;
	r=(struct line *)malloc(sizeof(struct line));
	r->num=e;
	r->link=NULL;
	if(now[s]==0)
	{
		list[s].head=(struct line *)malloc(sizeof(struct line));
		list[s].head->link=r;
		now[s]=1;
	}
	else
	{
		q=list[s].head;
		p=list[s].head->link;
		while(p!=NULL && e>p->num)
		{
//			printf("%d %d\n",e,p->num);
			q=q->link;
			p=p->link;
		}
		if(p!=NULL)
		{
			r->link=p;
			q->link=r;
		}
		else
			q->link=r;
	}
}
int visit[110]={0};
void DFS(int s)
{
	struct line *p;
	visit[s]=1;
	printf("%d ",s);
	for(p=list[s].head->link;p!=NULL;p=p->link)
		if(visit[p->num]==0)
			DFS(p->num);
}
void BFS()
{
	struct line *p;
	int queue[110]={0},end,i;
	queue[0]=1;
	end=1;
	while(queue[0]!=0)
	{
		visit[queue[0]-1]=1;
		for(p=list[queue[0]-1].head->link;p!=NULL;p=p->link)
		{
			if(visit[p->num]==0)
			{
				visit[p->num]=1;
				queue[end]=p->num+1;
				end++;
			}
		}
		printf("%d ",queue[0]-1);
		for(i=0;i<end;i++)queue[i]=queue[i+1];
		end--;
	}
}
int main()
{
	int i=0,s,e,de;
	struct line *p,*q,*r;
	while(1)
	{
		scanf("%d",&s);
		if(scanf("%d",&e)!=EOF)
		{
			insert(s,e);
			insert(e,s);
		}
		else
			break;
	}
	de=s;
	DFS(0);
	printf("\n");
	memset(visit,0,110);
	BFS();
	printf("\n");
	memset(visit,0,110);
	for(p=list[de].head->link;p!=NULL;p=p->link)
		for(r=list[p->num].head,q=list[p->num].head->link;q!=NULL;r=r->link,q=q->link)
			if(q->num==de)
			{
				r->link=q->link;
				free(q);
				break;
			}
	DFS(0);
	printf("\n");
	memset(visit,0,110);
	BFS();
	return 0;
 } 

