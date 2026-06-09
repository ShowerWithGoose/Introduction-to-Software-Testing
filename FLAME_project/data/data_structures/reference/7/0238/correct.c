#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Date{
	int num;
	struct Date* lchild;
	struct Date* rchild;
}date;

date* insert(date* p,int a)
{
	if(p==NULL)
	{
		p = (date*)malloc(sizeof(date));
		p->lchild = NULL;
		p->rchild = NULL;
		p->num=a;
	}
	else
	{
		if(p->num<=a)
		{
			p->rchild=insert(p->rchild,a);
		}
		else 
		{
			p->lchild=insert(p->lchild,a);
		}
	}
	return p;
}
void find(date* p,int i)
{
	if(p->lchild==NULL&&p->rchild==NULL)
	{
		printf("%d %d\n",p->num,i);
		return ;
	}
	i++;
	if(p->lchild!=NULL)
	find(p->lchild,i);
	if(p->rchild!=NULL)
	find(p->rchild,i);
	return ;
}
int main()
{
	int n,i;
	int i_num;//i_num是输入时传入的值 
	date* root=NULL;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&i_num);
		root=insert(root,i_num);
	}
	find(root,1);
	return 0;
 } 

