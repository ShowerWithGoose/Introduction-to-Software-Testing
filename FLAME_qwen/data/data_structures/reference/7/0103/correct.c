#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int number;
	struct Node* left;
	struct Node* right;
}node;
typedef struct Node* nodeptr;
nodeptr treemake(int n);
void frontprint(nodeptr head,int n);
void deletetree(nodeptr head);
int main()
{
	int n;
	scanf("%d",&n);
	nodeptr head;
	head=treemake(n);
	frontprint(head,1);
	deletetree(head);
	return 0;
}
nodeptr treemake(int n)
{
	int num;
	nodeptr head,p,t,next; 
	scanf("%d",&num);	
	p=(nodeptr)malloc(sizeof(struct Node));
	p->number=num;
	p->left=NULL;
	p->right=NULL;
	head=p;
	int cnt=1;
	for(cnt=1;cnt<n;cnt++)
	{
		scanf("%d",&num);
		p=(nodeptr)malloc(sizeof(struct Node));
		p->number=num;
		p->left=NULL;
		p->right=NULL;
		t=head;
		while(1)
		{
			if(num>=t->number)
			{
				next=t->right;
				if(next==NULL)
				{
					t->right=p;
					break;
				}	
				else 
					t=next;
			}
			else
			{
				next=t->left;
				if(next==NULL)
				{
					t->left=p;
					break;
				}
				else
					t=next;
			}			
		}
	}	
	return head;	
}
void frontprint(nodeptr head,int n)
{
	if(head==NULL)
		return;
	if(head->left==NULL&&head->right==NULL)
	{
		printf("%d %d\n",head->number,n);
		return;
	}		
	frontprint(head->left,n+1);
	frontprint(head->right,n+1);
}
void deletetree(nodeptr head)
{	
	if(head==NULL)
		return;
	deletetree(head->left);
	deletetree(head->right);
	free(head);
}

