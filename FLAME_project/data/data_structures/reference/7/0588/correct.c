#include <stdio.h>
#include <stdlib.h>
typedef struct BTNode{
	int val;
	int layer;
	struct BTNode *lchild,*rchild;
}BTNode;
typedef BTNode* nodeptr;
nodeptr root,p,q;
void insert(nodeptr q);
void inorder(nodeptr root);

int main()
{
	int a,n;
	scanf("%d",&a);
	while(a--)
	{
		scanf("%d",&n);
		q = (nodeptr)malloc(sizeof(BTNode));
		q->val = n;q->lchild = NULL;q->rchild = NULL;
		insert(q);
	}
	
	inorder(root);
	
	return 0;
}

void insert(nodeptr q)
{ 
	p=root;
	q->layer = 1;
	if(root == NULL){
		root = q;
	}
	else{
		while(1)
		{
			if(q->val>=p->val)
			{
				if(p->rchild!=NULL){
					p = p->rchild;
					q->layer++;
				}
				else
				{
					q->layer++;
					p->rchild = q;
					break;
				}
			}
			else
			{
				if(p->lchild!=NULL){
					p = p->lchild;
					q->layer++;
				}
				else
				{
					q->layer++;
					p->lchild = q;
					break;
				}
			}
		}
	}
}

void inorder(nodeptr root)
{
	if(root!=NULL)
	{
		inorder(root->lchild);
		
		if(root->lchild==NULL&&root->rchild==NULL)
		{
			printf("%d %d\n",root->val,root->layer);
		}
		
		inorder(root->rchild);
	}
	
}

