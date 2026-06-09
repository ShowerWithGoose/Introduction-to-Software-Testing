#include<stdio.h>
#include<stdlib.h>
struct _bst{
	int data;
	struct _bst *lc, *rc;
};
typedef struct _bst  bst, *pbst;

pbst createTree(pbst p, int item)
{
	if(p==NULL)
	{
		p=(pbst)malloc(sizeof(bst));
		p->data=item;
		p->lc=p->rc=NULL;
	}
	else if(p->data>item)
		p->lc=createTree(p->lc, item);
	else if(p->data<=item)
		p->rc=createTree(p->rc, item);
		
	return p;
}

void put(pbst p, int floor)
{
	if(p!=NULL)
	{
		put(p->lc, floor+1);
		if(p->lc==NULL && p->rc==NULL)
			printf("%d %d\n", p->data, floor);
		put(p->rc, floor+1);
	}
}

int main()
{
	int item, i, n;
	pbst root=NULL;
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		scanf("%d", &item);
		root=createTree(root, item);
	}
	put(root, 1);	
}

