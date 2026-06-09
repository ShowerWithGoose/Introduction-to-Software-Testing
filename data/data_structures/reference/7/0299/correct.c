#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct DATE
{
	int number;
	int hight;
	struct DATE *leftchild;
	struct DATE *rightchild;
};
typedef struct DATE date;
date *insert(date *p,int num,int hightofdate)
{
	if(p==NULL)
	{
		p=(date*)malloc(sizeof(date));
		p->number =num;
		p->hight =hightofdate;
		p->leftchild =p->rightchild =NULL;
		return p;
	}
	hightofdate++;
	if(num<(p->number ))
		p->leftchild =insert(p->leftchild ,num,hightofdate);
	if(num>=(p->number ))
		p->rightchild =insert(p->rightchild ,num,hightofdate);
	return p;
}
void *visit(date *p)
{
	if(p->leftchild ==NULL&&p->rightchild ==NULL)
		printf("%d %d\n",p->number ,p->hight );
	if(p->leftchild !=NULL)
		visit(p->leftchild );
	if(p->rightchild !=NULL)
		visit(p->rightchild );
}
int main()
{
	date *root=NULL;
	int innumber,hightofroot=1;
	int n;
	scanf("%d",&n);
	for(;n>0;n--)
	{
		scanf("%d",&innumber);
		root=insert(root,innumber,hightofroot);
	}
	visit(root);
	
	
	
} 

