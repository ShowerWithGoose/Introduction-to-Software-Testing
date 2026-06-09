#include<stdio.h>

struct tree{
	int num;
	struct tree *left;
	struct tree *right;	
};

void visit(struct tree* p,int i)
{
	if(p->left!=NULL)
	visit(p->left,i+1);
	if(p->right!=NULL)
	visit(p->right,i+1);
	if(p->left==NULL&&p->right==NULL)
	{
		printf("%d %d\n",p->num,i);
	}
	return;
} 


int main()
{
	int n,i,m;
	scanf("%d",&n);
	struct tree*head,*p,*q;
	head=(struct tree*)malloc(sizeof(struct tree));
	head->left=NULL;
	head->right=NULL;
	scanf("%d",&(head->num));
	p=head;
	for(i=0;i<n-1;i++)
	{
		scanf("%d",&m);
		while((m<(p->num)&&p->left!=NULL)||(m>=(p->num)&&p->right!=NULL))
		{
			if((m<(p->num)&&p->left!=NULL))
			{
				p=p->left;
			}
			else
			{
				p=p->right;
			}
		}
		if(m<(p->num))
		{
			q=(struct tree*)malloc(sizeof(struct tree));
			q->left=NULL;
			q->right=NULL;
			q->num=m;
			p->left=q;
			p=head;
		}
		else if(m>=(p->num))
		{
			q=(struct tree*)malloc(sizeof(struct tree));
			q->left=NULL;
			q->right=NULL;
			q->num=m;
			p->right=q;
			p=head;
		}
	}
	visit(head,1);
	
	return 0;
}

