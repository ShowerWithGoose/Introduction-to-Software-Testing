#include<stdio.h>
typedef struct Tree{
	int data;
	struct tree *l;//×ó 
	struct tree *r;//ÓÒ 
	int d;//Éî¶È 
}tree;
typedef struct Tree* treep;
treep root=NULL;

treep insert(treep p,int m,int d)
{
	d++;
	if(p==NULL)
		{
			p = (treep)malloc(sizeof(tree));
			p->data = m;
			p->l = NULL;
			p->r = NULL;
			p->d = d;
		}
	else if(m<p->data)
		p->l = insert(p->l,m,d);
	else if(m>=p->data)
		p->r = insert(p->r,m,d);
	return p;
		
}
void leaf(treep p)
{
	if(p!=NULL)
	{
		if(p->l==NULL&&p->r==NULL)
			printf("%d %d\n",p->data,p->d);
		leaf(p->l);
		leaf(p->r);
	}
}
int main()
{
	int n,m,i,d=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&m);
		root = insert(root,m,d);
	}
	leaf(root);
	return 0;
}

