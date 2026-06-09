#include<stdio.h>
#include<stdlib.h>
int ctime=0;
int maxtime=0;
struct f{
	int n;
	int time;
	struct f *left,*right,*parent;
};
struct f *T=NULL,*p,*q;
struct f *search(int a,struct f *p)
{
	if(p!=NULL)
	{
		if(a<p->n)
		{
			p->left=search(a,p->left);
			p->left->parent=p;
		}
		else
		{
			p->right=search(a,p->right);
			p->right->parent=p;
		}
	}
	else
	{
		p=(struct f *)malloc(sizeof(struct f));
		p->n=a;
		p->left=NULL;
		p->right=NULL;
		p->parent=NULL;
		p->time=0;
	}
	return p;
}
int back(struct f *p)
{
	if(T!=NULL)
	{
		if(p!=T)
		p->time=p->parent->time+1;
		if(p->left!=NULL)
		{
			maxtime=back(p->left);
		}
		if(p->right!=NULL)
		{
			maxtime=back(p->right);
		}
		if(p->left==NULL&&p->right==NULL)
		{
			printf("%d %d\n",p->n,p->time+1);
		}
		return maxtime;
	}
}
/*int pri(struct f *p)
{
	if(p->parent!=NULL)
		pri(p->parent);
	printf("%d ",p->n);
	return 0;
}
int out(struct f *p)
{
	if(T!=NULL)
	{
		
		if(p->left!=NULL)
		{
			cmptime++;
			out(p->left);
		}
		if(p->right!=NULL)
		{
			cmptime++;
			out(p->right);
		}
		if(p->time==maxtime)
		{
			pri(p);
			return 0;
		}
		return 0;
	}
}*/
int main()
{
	int x,n,i=0;
	char c;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		T=search(x,T);
	}
	maxtime=back(T);
	//out(T);
	return 0;
}

