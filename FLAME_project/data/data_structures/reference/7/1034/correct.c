#include <stdio.h>
#include <stdlib.h>
int n;
int data[1000];
struct node {
	int data;
	struct node*left,*right;
};
struct leaf
{
	int data;
	int height;
}leafnode[100];
int i=0;
typedef struct node BTNode;
typedef struct node *BTNodeptr;
BTNodeptr ROOT=NULL;
void insert (int x)
{
	BTNodeptr p,q;
	p=(BTNodeptr)malloc(sizeof(BTNode));
	p->data=x;
	p->left=NULL;
	p->right=NULL;
	if(ROOT==NULL)
		ROOT=p;
	else{
		q=ROOT;
		while(1)
		{
			if(x<q->data)
			{
				if(q->left==NULL)
				{
					q->left=p;
					break;
				}
				else
					q=q->left;
			}
			else if(x>=q->data)
			{
				if(q->right==NULL)
				{
					q->right=p;
					break;
				}
				else
					q=q->right;
			}
		}
	}
}
void layer(BTNodeptr T)
{
	BTNodeptr stack1[100],p=T;
	int stack2[100];
	int depth=0,top=-1;
	if(T!=NULL)
		depth=1;
	do{
		while(p!=NULL)
		{
			stack1[++top]=p;
			stack2[top]=depth;
			p=p->left;
			depth++;
		}
		p=stack1[top];
		depth=stack2[top--];
		if(p->left==NULL&&p->right==NULL)
		{
			leafnode[i].data=p->data;
			leafnode[i].height=depth;
			i++;
		}
		p=p->right;
		depth++;
	}
	while(!(p==NULL&&top==-1));
}
int main(int argc, char *argv[]) {
	scanf("%d",&n);
	for (int k=0; k<n; k++)
	{
		scanf("%d",&data[k]);
		insert(data[k]);
	}
		layer(ROOT);
	for (int j=0; j<i; j++)
	{
		printf("%d %d\n",leafnode[j].data,leafnode[j].height);
	}
	return 0;
}
