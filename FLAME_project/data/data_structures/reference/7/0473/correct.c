#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
typedef struct god
{
	int data;
	struct god *lson,*rson;
}link;
link *root;
int n;
link *node(int num)
{
	link *p = (char *)malloc(sizeof(link));
	p->data = num;
	p->lson = NULL;
	p->rson = NULL;
	return p;
}
void add(link *u,int num)
{
	if(num < u->data)
	{
		if(u->lson != NULL) add(u->lson,num);
		else u->lson = node(num);
	}
	else
	{
		if(u->rson != NULL) add(u->rson,num);
		else u->rson = node(num);
	}
}
void print(link *u,int deep)
{
	if(u->lson == NULL && u->rson == NULL)
	{
		printf("%d %d\n",u->data,deep);
		return;
	}
	if(u->lson != NULL) print(u->lson,deep+1);
	if(u->rson != NULL) print(u->rson,deep+1);
	
}
int main()
{
	int a;
	scanf("%d%d",&n,&a);
	root = node(a);
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&a);
		add(root,a);
	}
	print(root,1);
	return 0;
}

