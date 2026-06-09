#include <stdio.h>
#include <stdlib.h>
struct node
{
	int deep;
	int num;
	struct node *ls;
	struct node *rs;
};
typedef struct node node;
typedef node *nptr;
nptr root;
int size;
nptr getnode(int m)
{
	nptr p=(nptr)malloc(sizeof(node));
	p->deep=0;
	p->num=m;
	p->ls=p->rs=NULL;
	return p;
}
int compare(int m,int n)
{
	if(m>=n) return 1;
	else return 0;
}
void insert(int m)//插入树的结点 
{
	if(size==0)
	{
		size=1;
		nptr p=getnode(m);
		p->deep=1;
		root=p;
	}
	else
	{
		size++;
		nptr p=getnode(m);
		nptr q=root;
		int flag=0;
		while(1)
		{
			if(compare(p->num,q->num)==1)
			{
				if(q->rs==NULL) 
				{
					p->deep=q->deep+1;
					q->rs=p;
					flag=1;
				}
				else q=q->rs;
			}
			else
			{
				if(q->ls==NULL)
				{
					p->deep=q->deep+1;
					q->ls=p;
					flag=1;
				}
				else q=q->ls;
			}
			if(flag==1) break;
		}
	}
}
void dfs(nptr m)//深搜？ 
{
	if(m==NULL) return ;
	if((m->ls==NULL) && (m->rs==NULL)) 
	{
		printf("%d %d\n",m->num,m->deep);
		return;
	}
	dfs(m->ls);
	dfs(m->rs);
	return ;
} 
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
	{
		int m;
		scanf("%d",&m);
		insert(m);
	}
	dfs(root);
	return 0;
}

