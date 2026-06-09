#include<stdio.h>
#include<stdlib.h>

struct node{
	int num;
	struct node *lch;
	struct node *rch;
};

typedef struct node BTnode;
typedef struct node* BTptr; 

BTptr insert(BTptr p,int item)
{
	if(p==NULL)
	{
		p=(BTptr)malloc(sizeof(BTnode));
		p->num=item;
		p->lch=NULL;
		p->rch=NULL;
	}
	else if(item<p->num)
	{
		p->lch=insert(p->lch,item);	
	}
	else
	{
		p->rch=insert(p->rch,item);
	}
	return p;
}

void fend(BTptr p,int rear)
{
	if(p->lch==NULL&&p->rch==NULL)
	{
		printf("%d %d\n",p->num,rear);
	}
	else if(p->lch==NULL&&p->rch!=NULL)
	{
		rear++;
		fend(p->rch,rear);
	}
	else if(p->rch==NULL&&p->lch!=NULL)
	{
		rear++;
		fend(p->lch,rear);
	}
	else
	{
		rear++;
		fend(p->lch,rear);
		fend(p->rch,rear);
	}
}

int main()
{
	int i,item,cnt;
	scanf("%d",&cnt);
	BTptr root=NULL,pst;
	int flag=0;
	for(i=0;i<cnt;i++)
	{
		scanf("%d",&item);
		root=insert(root,item);
		if(flag==0) pst=root;
		flag=1;
	}//二叉树建立成功 
	
	fend(pst,1);
	
	return 0;
 } 

