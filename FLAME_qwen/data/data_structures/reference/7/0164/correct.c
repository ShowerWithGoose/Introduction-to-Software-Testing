#include<stdio.h>
#include<stdlib.h>
struct setnode{
	int data;
	struct setnode*lt,*rt;
};
typedef struct setnode tree;
tree* createtree(tree*t,int n)
{
	if(t==NULL) 
	{
		t=(tree*)malloc(sizeof(tree));
		t->data=n;
		t->lt=NULL;
		t->rt=NULL;
	}
	else
	{
		if(n<t->data) t->lt=createtree(t->lt,n);
		if(n>=t->data) t->rt=createtree(t->rt,n);
	}
	return t;
}
void visitleaf(tree*t,int height)
{
if(t!=NULL)
{
	if(t->lt==NULL&&t->rt==NULL) printf("%d %d\n",t->data,height);
	else
	{
		height++;
		visitleaf(t->lt,height);
		visitleaf(t->rt,height);
	}
}
}
int main()
{
	tree*t=NULL;
	int num,i,n,height=1;
	scanf("%d",&num);
//	printf("%d\n",num);
	for(i=0;i<num;i++)
	{
		scanf("%d",&n);
//		printf("%d\n",n);
		t=createtree(t,n);
	}
	visitleaf(t,height);	
	return 0;
}

