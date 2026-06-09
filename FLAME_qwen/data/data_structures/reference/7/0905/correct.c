#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *lchild,*rchild;
	int height;
}TREE,*TreeLink;
TreeLink root=NULL;
int search(int item)
{
	int h;
	TreeLink p,q;
	p=(TreeLink)malloc(sizeof(TREE));
	p->data =item;
	p->lchild =NULL;
	p->rchild =NULL;
	if(root==NULL)
	{
		root=p;
		root->height =1;
	}
	else
	{
		q=root;
		h=1;
		while(1)
		{
			if(item<q->data )
			{
				if(q->lchild ==NULL){
					h++;
					q->lchild =p;
					p->height =h;
					break;
				}else{
					q=q->lchild;
					h++;
				}
			}
			else if(item>=q->data )
			{
				if(q->rchild ==NULL)
				{
					h++;
					q->rchild =p;
					p->height =h;
					break;
				}else{
					h++;
					q=q->rchild ;
				}
			}
			
		}
	}
	
	return h;
}
int order(TreeLink p)
{
	if(p!=NULL)
	{
		if(p->lchild ==NULL&&p->rchild ==NULL)printf("%d %d\n",p->data ,p->height );
		order(p->lchild );
		order(p->rchild );
	}
	return 1;
}
int main()
{	
	int i,n,item,ee;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&item);
	ee=	search(item);
	//printf("%d\n",ee);
	}
	//printf("%d",root->data );
//	printf("%d\n",root->lchild->height   );
	//root=root->rchild ;
	//printf("%d\n",root->lchild->height   );
int x=	order(root);
	return 0;	
}
