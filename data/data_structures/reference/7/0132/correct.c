#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

typedef struct leaf{
	int num;
	struct leaf *lchild,*rchild;
}leaf,*Pleaf;

int flag_right;

void find(Pleaf p,int depth)
{
	if(p->lchild==NULL&&p->rchild==NULL)
	{
		printf("%d %d\n",p->num,depth);
	}
	else
	{
		if(p->lchild!=NULL) find(p->lchild,depth+1);
		if(p->rchild!=NULL) find(p->rchild,depth+1);
	}
}

Pleaf InTree(Pleaf in,Pleaf start)
{
	
	if(in->num>=start->num)
	{
		if(start->rchild!=NULL) return InTree(in,start->rchild);
		else
		{
			flag_right=1;
			return start;
		}
	}
	else
	{
		if(start->lchild!=NULL) return InTree(in,start->lchild);
		else
		{
			flag_right=0;
			return start;
		}
	}
}

int main()
{
	//freopen("damn.txt","r",stdin);//
	
	int n,i;
	
	scanf("%d",&n);
	
	Pleaf q,start;
	
	q=(Pleaf)malloc(sizeof(leaf));
	q->lchild=q->rchild=NULL;q->num=0;
	
	start=q;
	scanf("%d",&q->num);
	q=(Pleaf)malloc(sizeof(leaf));
	q->lchild=q->rchild=NULL;q->num=0;
	
	for(i=1;i<n;i++)
	{
		scanf("%d",&q->num);
		Pleaf p=InTree(q,start);
		if(flag_right==1)
		{
			p->rchild=q;
		}
		else
		{
			p->lchild=q;
		}
		
		q=(Pleaf)malloc(sizeof(leaf));
	    q->lchild=q->rchild=NULL;q->num=0;
	}
	
	find(start,1);
	
	
	
	return 0;
}








