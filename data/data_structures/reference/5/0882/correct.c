#include<stdio.h>
#include<stdlib.h>

typedef struct lnode{
	int a,index;
	struct lnode *next;
}lnode;

lnode* add(lnode *p3,lnode *pt)
{
	lnode *s,*ps,*tmp;
	int a,i;
	s=ps=NULL;
	while(p3!=NULL&&pt!=NULL)
	{
		if(p3->index == pt->index)
		{
			a = p3->a + pt->a;
			i = p3->index;
			p3=p3->next;
			pt=pt->next;
		}
		else if(p3->index > pt->index)
		{
			a=p3->a;
			i=p3->index;
			p3=p3->next;
		}
		else
		{
			a=pt->a;
			i=pt->index;
			pt=pt->next;
		}
		//算当项的系数与指数 
		if(a!=0)
		{
			tmp=(lnode*)malloc(sizeof(lnode*));
			tmp->a=a;
			tmp->index=i;
			tmp->next=NULL;
			if(s==NULL)
			s=ps=tmp;
			else
			ps->next=tmp;
			ps=tmp;
		} 
	}
	if(pt!=NULL)//把pt加完 
	{
		if(s==NULL)
		s=pt;
		else
		ps->next=pt;
	}
	else if(p3!=NULL)
	{
		if(s==NULL)
		s=p3;
		else
		ps->next=p3;
	}
	return s; 
}

int main()
{
	lnode *l1,*l2,*l3,*lt;
	lnode *p1,*p2,*p3,*pt;
	lnode *tmp;
	tmp=(lnode*)malloc(sizeof(lnode*));
	scanf("%d%d",&tmp->a,&tmp->index);
	l1=p1=tmp;
	while(getchar()!='\n')
	{
		tmp=(lnode*)malloc(sizeof(lnode*));//每一个节点都需要换地址，不然会改变上一个地址的值，不信等一下可以试试 
		scanf("%d%d",&tmp->a,&tmp->index);
		p1=p1->next=tmp;
	}
	p1->next=NULL;//第一个多项式输入 
	tmp=(lnode*)malloc(sizeof(lnode*));
	scanf("%d%d",&tmp->a,&tmp->index);
	l2=p2=tmp;
	while(getchar()!='\n')
	{
		tmp=(lnode*)malloc(sizeof(lnode*));//每一个节点都需要换地址，不然会改变上一个地址的值，不信等一下可以试试 
		scanf("%d%d",&tmp->a,&tmp->index);
		p2=p2->next=tmp;
	}
	p2->next=NULL;//第二个多项式
	p1=l1;
	p2=l2;
	p3=l3=NULL;
	while(p1!=NULL)
	{
		tmp=(lnode*)malloc(sizeof(lnode*));
		tmp->a = p1->a * p2->a;
		tmp->index = p1->index + p2->index;
		lt=pt=tmp;
		p2=p2->next;
		while(p2!=NULL)
		{
			tmp=(lnode*)malloc(sizeof(lnode*));
			tmp->a = p1->a * p2->a;
			tmp->index = p1->index + p2->index;
			pt=pt->next=tmp;
			p2=p2->next;
		}//lt是p1乘l2的多项式
		pt->next=NULL;
		pt=lt;
		l3=add(p3,pt);//lt与l3相加
		p3=l3; 
		p2=l2;
		p1=p1->next;
	}
	while(p3!=NULL)
	{
		printf("%d %d ",p3->a,p3->index);
		p3=p3->next;
	}
	return 0;
 } 

