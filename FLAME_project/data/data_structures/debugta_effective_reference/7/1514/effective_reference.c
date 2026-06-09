#include<stdio.h>
typedef struct node
{
	int num;
	int level;
	struct node *left,*right;
}Tree;


int main()
{
	int n;
	Tree *root=NULL;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int aim;
		int len=1;
		scanf("%d",&aim);
		Tree *temp=(Tree*)malloc(sizeof(Tree));
		temp->num=aim;
		temp->left=temp->right=NULL;
		if(root==NULL)
		{
			temp->level=len;
			root=temp;
		}
		else
		{
			Tree *point=root;
			while(1)
			{
				if(aim<point->num)
				{
					len++; 
					if(point->left==NULL)
					{
						temp->level=len;
						point->left=temp;
						break;
					}
					else
						point=point->left;
				}
				else if(aim>=point->num)
				{
					len++;
					if(point->right==NULL)
					{
						temp->level=len;
						point->right=temp;
						break;
					}
					else
						point=point->right; 
				}
					
			}
		}
	}
	int top=-1;
	Tree *point=root;
	Tree *stack[100];
	memset(stack,0,sizeof(stack));
	do
	{
		for(;point!=NULL;point=point->left)
			stack[++top]=point;
		point=stack[top--];
		if(point->left==NULL&&point->right==NULL)
			printf("%d %d\n",point->num,point->level);
		point=point->right;
	}while(!(point==NULL&&top==-1));
	
	return 0;
}


