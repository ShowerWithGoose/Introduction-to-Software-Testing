#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include<math.h>
typedef struct nod
{
	int date,high;
	struct nod *lift,*right;
}node;
node *top=NULL;
int h=1,n;
void createtree();
void readtree(node*);
void addnode(int);
void read(node*);
int main()
{
	scanf("%d",&n);
	createtree();
	readtree(top);
	return 0;
}

void createtree()
{
	int a,i;

	for(i=0;i<n;i++)
	{scanf("%d",&a);
	if(top==NULL)
	{
		top=(node*)malloc(sizeof(node));
		top->high=1;
		top->date=a;
		top->lift=NULL;
		top->right=NULL;
	}
	else
	{
		addnode(a);
	}
	}
	return;
}

void addnode(int a)
{
	node *p,*q;
	int flag;
	for(p=top;;p=q)
	{
		if(a<p->date)
		{q=p->lift,flag=1;}
		else
		{q=p->right,flag=2;}
		if(q==NULL)
		{
			q=(node*)malloc(sizeof(node));
			q->lift=NULL;
			q->right=NULL;
			q->date=a;
			q->high=p->high+1;
			if(flag==1)
			p->lift=q;
			else
			p->right=q;
			break;
		}	
	}
	return;
}

void readtree(node* t)
{
	if(t!=NULL)
	{
		read(t);
		readtree(t->lift);
		readtree(t->right);
	}
	return;
}

void read(node* t)
{
	if(t->lift==NULL&&t->right==NULL)
	printf("%d %d\n",t->date,t->high);
}




