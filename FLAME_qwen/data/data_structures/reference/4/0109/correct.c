#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
	char word[100];
	int nub;
	struct node *left,*right;
}Tree;

int main()
{
	freopen("article.txt","r",stdin);
	char w;
	Tree *head=NULL;
	while((w=getchar())!=EOF)
	{
		
		Tree *node;
		node=(Tree*)malloc(sizeof(Tree));
		memset(node,0,sizeof(node));
		node->nub=1;
		node->left=node->right=NULL;
		while(isalpha(w)==0&&w!=EOF)	w=getchar();
		if(w==EOF)
			break;
		int cot=0;
		do
		{
			node->word[cot++]=tolower(w);
		}while(isalpha(w=getchar()));
		
		
		if(head==NULL)
			head=node;
		else 
		{
			Tree *point=head;
			//temp>word 
			while(1)
			{
				if(strcmp(node->word,point->word)>0)
				{
					if(point->right==NULL)
					{
						point->right=node;
						break;
					}
					else 
						point=point->right;
				}
				else if(strcmp(node->word,point->word)<0)
				{
					if(point->left==NULL)
					{
						point->left=node;
						break;
					}
					else
						point=point->left;
				}
				else
				{
					point->nub++;
					break;
				}
			}
			
		}
	}
	int top=-1;
	Tree *point=head,*stack[100];
	memset(stack,0,sizeof(stack));
	Tree *p=head;
	do
	{
		for(;point!=NULL;point=point->left)
			stack[++top]=point;
		point=stack[top--];
		printf("%s %d\n",point->word,point->nub);
		point=point->right;
	}while(!(point==NULL&&top==-1));
	return 0;
}

