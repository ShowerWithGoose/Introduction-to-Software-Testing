#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
	int coe;
	int index;
	struct node *link;
};
typedef struct node *Pnode;
typedef struct node Node;
Pnode insertNode(Pnode list,int coe,int index)
{
	Pnode p=list,q=NULL,r=NULL;
	r=(Pnode)malloc(sizeof(Node));
	r->coe=coe;
	r->index=index;
	r->link=NULL;
	if(list==NULL) return r;
	for(p=list;p!=NULL&&p->index>index;q=p,p=p->link);
	if(p!=NULL&&p->index==index)
	{
		p->coe+=coe;
	}
	else if(p==list)
	{
		r->link=p;
		return r; 
	}
	else
	{
		q->link=r;
		r->link=p;
	}
	return list;
}
int main()
{
	Pnode line=NULL,ans=NULL;
	int coe,index;
	char c;
	int index_=1000000;
	do 
	{
		scanf("%d%d%c",&coe,&index,&c);
		line=insertNode(line,coe,index);
	}while(c!='\n');
	do 
	{
		scanf("%d%d%c",&coe,&index,&c);
		Pnode q=NULL;
		for(q=line;q!=NULL;q=q->link)
		{
			ans=insertNode(ans,(q->coe)*coe,(q->index)+index);
		}
	}while(c!='\n');
	Pnode r;
	for(r=ans;r!=NULL;r=r->link)
	{
		printf("%d ",r->coe);
		printf("%d ",r->index);
	}
	return 0;
}

