#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>



struct tnode{
	int num;
	int height;
	struct tnode *left,*right;
	
}; 
int i,j,k;
struct tnode *root=NULL;
int temp;
void insert(int temp)
{struct tnode *p,*q;
p=(struct tnode*)malloc(sizeof(struct tnode));
p->num=temp;
p->height=1;
p->left=NULL;
p->right=NULL;
if(root==NULL)
root=p;
else 
{q=root;
	while(1)
	{
		if(temp<q->num){
			if(q->left==NULL){
				q->left=p;
				p->height++;
				break;
			}
			else{
			q=q->left;
			p->height++;	
			}
			
		}
		else if (temp>=q->num){
			if(q->right==NULL){
				q->right=p;
				p->height++;
				break;
			}
			else
			{q=q->right;
			p->height++;
			}
			
		}
		 
	}
}
}
void visit(struct tnode* t)
{if(t->left==NULL&&t->right==NULL)
{printf("%d %d\n",t->num,t->height);
}
}
void inorder(struct tnode* t)
{if(t!=NULL)
{inorder(t->left);
	visit(t);
	inorder(t->right);
}
}

int main()
{
int n;
scanf("%d",&n);
	for(i=0;i<n;i++)
	{scanf("%d",&temp);
	insert(temp);
	}
	
	inorder(root);
}

