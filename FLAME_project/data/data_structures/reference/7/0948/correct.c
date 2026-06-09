#include<stdio.h>
#include<stdlib.h>
struct node{
	int num;
	struct node *lchild,*rchild;
};
typedef struct node BTNode;
typedef struct node* BTNodeptr;
BTNodeptr root=NULL;
int depth=1;
//===========非递归算法的二叉查找树的建立======= 
void insert(int item)
{
	BTNodeptr p,q;
	p=(BTNodeptr)malloc(sizeof(BTNode));
	p->num=item;
	p->lchild=NULL;
	p->rchild=NULL;
	if(root==NULL)
	{
		root=p;
	}
	else
	{
		q=root;
		while(1)
		{
			if(item<q->num)
			{
				if(q->lchild==NULL)
				{
					q->lchild=p;
					break;
				}
				else
				{
					q=q->lchild;
				}
			}
			else if(item>=q->num)
			{
				if(q->rchild==NULL)
				{
					q->rchild=p;
					break;
				}
				else
				{
					q=q->rchild;
				}
			}
			
		}
	}
}
//=============================================

//===========二叉链表后序遍历==========
void postorder(BTNodeptr t)
{
	if(t!=NULL)
	{
		depth++;
		postorder(t->lchild);
		
		postorder(t->rchild);
		depth--;
		if(t->lchild==NULL&&t->rchild==NULL)
		{
			printf("%d %d\n",t->num,depth);
		}/*访问t指向的结点*/
	}
	
} 
//=======================================

int main()
{
	int n;
	int i,num;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&num);
		insert(num);
	}
	postorder(root);
	return 0;
}
 

