#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct elinks{
	int adjvex;
	struct elinks *next;
}elink;
typedef struct vlinks{
	int num;
	elink* link;
}vlink;
vlink v[105];
int visited[105]={0};
int queue[105],front=0,rear=104,count=0;
void travel_dfs(vlink v[],int n);
void dfs(vlink v[],int i);
void dfs(vlink v[],int i);
void travel_bfs(vlink v[],int n);
int main()
{
	int i,n,m;//n为顶点个数，m为边的个数 
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++) v[i].num=i;
    //扫描图 
    for(i=0;i<m;i++)
    {
    	int a,b;
    	scanf("%d%d",&a,&b);
    	elink *p,*q;
    	p=(elink*)malloc(sizeof(elink));
    	p->adjvex=b;
    	p->next=NULL;
    	if(v[a].link==NULL) v[a].link=p;
    	else
    	{
    		int flag=0;
    		elink *t;
    		for(t=q=v[a].link;q!=NULL;t=q,q=q->next)
    		{
    			if(q->adjvex>b)
    			{
    				flag=1;
    				if(q==v[a].link)
    				{
    					v[a].link=p;
    					p->next=q;
					}
					else
					{
						t->next=p;
						p->next=q;
					}
					break;
				}
			}
    		if(flag==0) t->next=p;
		}
    	p=(elink*)malloc(sizeof(elink));
    	p->adjvex=a;
    	p->next=NULL;
    	if(v[b].link==NULL) v[b].link=p;
    	else
    	{
    		int flag=0;
    		elink *t;
    		for(t=q=v[b].link;q!=NULL;t=q,q=q->next)
    		{
    			if(q->adjvex>a)
    			{
    				flag=1;
    				if(q==v[b].link)
    				{
    					v[b].link=p;
    					p->next=q;
					}
					else
					{
						t->next=p;
						p->next=q;
					}
					break;
				}
			}
    		if(flag==0) t->next=p;
		}
	}
	//扫描图完成 
	/*for(i=0;i<n;i++)
	{
		printf("%d: ",i);
		elink *p=v[i].link;
		for(;p!=NULL;p=p->next) printf("%d ",p->adjvex);
		printf("\n");
	}*///打印一下图感受一下 
	int cut;
	scanf("%d",&cut);
	travel_dfs(v,n);
	printf("\n");
	travel_bfs(v,n);
	printf("\n");
	//建立新图 
	//adjvex是这条边的另一个顶点在数组中的位置 
	vlink v1[105];
	int n1=0;
	for(i=0;i<n;i++)
	{
		if(i!=cut) v1[n1++]=v[i]; 
	}
	for(i=0;i<n1;i++)
	{
		elink *p=v1[i].link,*q;
		for(q=p;p!=NULL;q=p,p=p->next)
		{
			if(p->adjvex==cut) 
			{
				if(p==v1[i].link)
				{
					v1[i].link=p->next;
				}
				else q->next=p->next;
			}
			else if(p->adjvex>cut) p->adjvex--;
		}
	} 
	/*for(i=0;i<n1;i++)
	{
		printf("%d: ",v1[i].num);
		elink *p=v1[i].link;
		for(;p!=NULL;p=p->next) printf("%d ",p->adjvex);
		printf("\n");
	}*///打印一下图感受一下 
	travel_dfs(v1,n1);
	printf("\n");
	travel_bfs(v1,n1);
	return 0;
}
void travel_dfs(vlink v[],int n)//顶点数组为v，共有n个顶点 
{
	int i;
	for(i=0;i<n;i++) visited[i]=0;
	dfs(v,0);
}
void dfs(vlink v[],int i)
{
	elink *p;
	printf("%d ",v[i].num);
	visited[i]=1;
	for(p=v[i].link;p!=NULL;p=p->next)
	{
		if(!visited[p->adjvex]) dfs(v,p->adjvex);
	}
}
void bfs(vlink v[],int i)
{
	elink*p;
	printf("%d ",v[i].num);
	visited[i]=1;
	rear=0;
	queue[rear]=i;
	count++;
	while(count!=0)
	{
		int j=queue[front];
		front++;
		count--;
		p=v[j].link;
		for(;p!=NULL;p=p->next)
		{
			if(!visited[p->adjvex])
			{
				printf("%d ",v[p->adjvex].num);
				visited[p->adjvex]=1;
				rear++;
				queue[rear]=p->adjvex;
				count++;
			}
		}
	}
}
void travel_bfs(vlink v[],int n)
{
	front=0;rear=104;count=0;
	int i;
	for(i=0;i<n;i++) visited[i]=0;
	for(i=0;i<n;i++) if(!visited[i]) bfs(v,i);
}


