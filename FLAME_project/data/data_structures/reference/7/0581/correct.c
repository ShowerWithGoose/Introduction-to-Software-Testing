#include <stdio.h>

struct node{
	int num,l;
	struct node *left,*right; 
}*h,*p,*q;

int m=1;

void ins(struct node *p, int n)
{
	m++;
	if(n<p->num)
	{
		if(p->left==NULL)
		{
			q=(struct node*)malloc(sizeof(struct node));
			q->num=n;
			q->l=m;
			q->left=NULL;
			q->right=NULL;
			p->left=q;
		}
		else
		{
			ins(p->left,n);
		}
	}
	else
	{
		if(p->right==NULL)
		{
			q=(struct node*)malloc(sizeof(struct node));
			q->num=n;
			q->l=m;
			q->left=NULL;
			q->right=NULL;
			p->right=q;
		}
		else
		{
			ins(p->right,n);
		}
	}
}

void out(struct node *p)
{
	if(p==NULL) return;
	if(p->left==NULL&&p->right==NULL)
	{
		printf("%d %d\n",p->num,p->l);
		return;
	}
	out(p->left);
	out(p->right);
}

int main()
{
	int N;
	int n=0;
	int i;
	scanf("%d",&N);
	scanf("%d",&n);
	h=(struct node*)malloc(sizeof(struct node));
	h->num=n;
	h->l=1;
	h->left=NULL;
	h->right=NULL;
	for(i=1;i<N;i++)
	{
		m=1;
		scanf("%d",&n);
		ins(h,n);
	}
	out(h);
	return 0;
}

