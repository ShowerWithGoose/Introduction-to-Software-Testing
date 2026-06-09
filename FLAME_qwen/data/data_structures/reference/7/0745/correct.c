#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#define M 1000005
#define ll long long
#define ull unsigned long long
struct node{
	int data;
	struct node* left;
	struct node* right;
	int depth;
}tree;
typedef struct node treee;
typedef struct node* treeestr;
treeestr root = NULL;
void insertTree(int data,int deepth);
void search(treeestr t);
int main()
{
	int n,m,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&m);
		insertTree(m,1);
	}
	search(root);
	return 0;
}
void search(treeestr t)
{
	if(t!=NULL)
	{
		search(t->left);
		if(t->left==NULL&&t->right==NULL)
		{
			printf("%d %d\n",t->data,t->depth);
		}
		search(t->right);
	}
}
void insertTree(int data,int deepth)
{
	treeestr p,q;
	p=(treeestr)malloc(sizeof(treee));
	p->left=NULL;
	p->right=NULL;
	p->data=data;
	if(root==NULL)
	{
		root=p;
	}
	else 
	{
		q=root;

		while(1)
		{
			if(data<q->data)
			{
				if(q->left==NULL)
				{
					q->left=p;deepth++;break;	
				}
				else
				   {
				   	q=q->left;deepth++;
				   }
			}
			else if(data>=q->data)
			{
				if(q->right==NULL)
				{
					q->right=p;deepth++;break;
				}
				else
				{
					q=q->right;deepth++;
					}	
			}
			
		
		}
	}
	p->depth = deepth;
}




