#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
struct node
{
	int n;
	struct node *rlink,*llink;
	int l;
};
typedef struct node *Nodeptr;
typedef struct node Node;
int shendu=1;
Nodeptr insert(Nodeptr p,int n,int shendu)
{
	if(p==NULL)
	{
		p=(Nodeptr)malloc(sizeof(Node));
		p->n=n;
		p->llink=p->rlink=NULL;
		p->l=shendu;
	}
	else if(n<p->n)
		p->llink=insert(p->llink,n,shendu+1);
	else
		p->rlink=insert(p->rlink,n,shendu+1);
	return p;
}
void bianli(Nodeptr p)
{
	if(p->llink!=NULL)
	bianli(p->llink);
	if(p->llink==NULL&&p->rlink==NULL)
	printf("%d %d\n",p->n,p->l);
	if(p->rlink!=NULL)
	bianli(p->rlink);
}
int main()
{
	int i,n,m;
	scanf("%d ",&m);
	Nodeptr root=NULL;
	for(i=0;i<m;i++)
	{
		scanf("%d",&n);
		root=insert(root,n,1);
	}
	bianli(root);
	return 0;
}

