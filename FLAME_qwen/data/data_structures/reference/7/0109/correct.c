#include<stdio.h>
typedef struct node
{
	int date;
	int high;
	struct node *left,*right;
}Tree;


int main()
{
	int n;
	Tree *head=NULL;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int temp;
		int len=1;
		scanf("%d",&temp);
		Tree *root=(Tree*)malloc(sizeof(Tree));
		root->date=temp;
		root->left=root->right=NULL;
		if(head==NULL)
		{
			root->high=len;
			head=root;
		}
		else
		{
			Tree *point=head;
			while(1)
			{
				if(temp<point->date)
				{
					len++; 
					if(point->left==NULL)
					{
						root->high=len;
						point->left=root;
						break;
					}
					else
						point=point->left;
				}
				else if(temp>=point->date)
				{
					len++;
					if(point->right==NULL)
					{
						root->high=len;
						point->right=root;
						break;
					}
					else
						point=point->right; 
				}
					
			}
		}
	}
	int top=-1;
	Tree *point=head;
	Tree *stack[100];
	memset(stack,0,sizeof(stack));
	do
	{
		for(;point!=NULL;point=point->left)
			stack[++top]=point;
		point=stack[top--];
		if(point->left==NULL&&point->right==NULL)
			printf("%d %d\n",point->date,point->high);
		point=point->right;
	}while(!(point==NULL&&top==-1));
	
	return 0;
}


