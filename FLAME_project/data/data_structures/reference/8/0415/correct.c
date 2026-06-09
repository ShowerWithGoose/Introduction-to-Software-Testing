#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxver 101
struct edge//边表 
{
	int adj;
	struct edge *next;
	struct edge *before;
};
typedef struct edge edge;
struct ver//点 
{
	int data;
	edge *link;//接在表头上 
};
typedef struct ver ver;
ver a[101];
void addedge(int u,int v)//有序加边操作
{
	edge *p=(edge *)malloc(sizeof(edge));
	p->adj=v;
	p->next=p->before=NULL;
	edge *q=a[u].link;//按大小顺序插入 
	if(q==NULL)
	{
		a[u].link=p;
		return ;
	}
	if(a[u].link->adj>v)//插在最前面
	{
		p->next=a[u].link;
		a[u].link->before=p;
		a[u].link=p;
		return ;
	} 
	while(q!=NULL)
	{
		if((q->next==NULL) && (v>q->adj))//插在最后 
		{
			q->next=p;
			p->before=q;
			return ;
		}
		if(q->adj>v)//将p插在q->before和q之间 
		{
			q->before->next=p;
			p->before=q->before;
			p->next=q;
			q->before=p;
			return ;
		}
		q=q->next;
	}
}
void clear()//初始化表头
{
	for(int i=0;i<=100;i++)
	{
		a[i].data=i;
		a[i].link=NULL;
	}
} 
int hash[101];//记录结点的遍历情况 
void dfs(int n)//深搜 
{
	if(hash[n]==1) return ;
	hash[n]=1;
	printf("%d ",n);
	edge *p=a[n].link;
	while(p!=NULL)
	{
		dfs(p->adj);
		p=p->next;
	}
}
int size;
int homo[10001];
void bfs()//广搜
{
	int i=1;//访问指针
	int j=1;//存储指针 
	while(size!=0)
	{
		if(hash[homo[i]]==1)//被访问过
		size--,i++;
		else //没被访问过 
		{
			hash[homo[i]]=1;//刻上印记
			printf("%d ",homo[i]);
			size--;
			edge *p=a[homo[i]].link;
			while(p!=NULL)
			{
				if(hash[p->adj]!=1) homo[++j]=p->adj,size++;
				p=p->next;
			}
			i++;
		} 
	}
	return ;
} 
void del(int u)
{
	for(int i=0;i<101;i++)
	{
		edge *q=a[i].link;
		if(q==NULL) continue;
		while(q->adj!=u)
		{
			q=q->next;
			if(q==NULL) break;
		} 
		if(q==NULL) continue;
		if((q->before==NULL) && (q->next==NULL) ) a[i].link=NULL;
		else if(q->before==NULL)//在队首 
		{
			q->next->before=NULL;
			a[i].link=q->next;
			free(q);
		}
		else if(q->next==NULL)//在队尾
		{
			q->before->next=NULL;
			free(q);
		} 
		else //在中间 
		{
			q->before->next=q->next;
			q->next->before=q->before;
			free(q);
		}
	}
	return ;
}
int main()
{
	int u,v;
	clear();
	while(scanf("%d",&u)!=EOF)//初始化建图 
	{
		if(scanf("%d",&v)==EOF) break;
		else addedge(u,v),addedge(v,u);	
	}
	//现在有的u是应该删除的结点 
	dfs(0);//第一次深搜 
	printf("\n");
	memset(hash,0,sizeof(hash));
	size=1;
	bfs();
	printf("\n");
	memset(hash,0,sizeof(hash));
	memset(homo,0,sizeof(homo));
	del(u);
	dfs(0);//第二次深搜 
	printf("\n");
	memset(hash,0,sizeof(hash));
	size=1;
	bfs();
	printf("\n");
	memset(hash,0,sizeof(hash));
	memset(homo,0,sizeof(homo));
	return 0;
} 

