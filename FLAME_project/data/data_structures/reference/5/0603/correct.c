#include<stdio.h>
#include<malloc.h>

int main()
{
	typedef struct node{
		int x;
		int z;
		struct node *link;
	}Lnode,*linklist;
	linklist p,r,q,list1=NULL,list2=NULL,list3=NULL;
	char a=48;
	while(a!='\n')
	{
		p=(linklist)malloc(sizeof(Lnode));
		scanf("%d%d",&p->x,&p->z);
		p->link=NULL;
		if(list1==NULL)list1=p;
		else r->link=p; 
		r=p;
		a=getchar();
	}
	a=48;
	while(a!='\n')
	{
			p=(linklist)malloc(sizeof(Lnode));
			scanf("%d%d",&p->x,&p->z);
			p->link=NULL;
			if(list2==NULL)list2=p;
			else r->link=p; 
			r=p;
			a=getchar();
	}
	p=list1;
	while(p!=NULL){
	q=list2;
		while(q!=NULL)
		{
		r=(linklist)malloc(sizeof(Lnode));
		r->x=p->x*q->x;
		r->z=p->z+q->z;
		r->link=NULL;
		if(list3==NULL)list3=r;
		else{
			linklist kp,kk=list3;
			while(1)
			{
				if(r->z>kk->z)//become tou-jie-dian
				{
					r->link=list3;
					list3=r;
					break;
				}
				if(r->z<kk->z)//use kp to remember,go
				{
					while(r->z<kk->z&&kk->link!=NULL){kp=kk;kk=kk->link;}
				}
				if(r->z==kk->z)//together,break
				{
					kk->x+=r->x;
					free(r);
					break;
				}
				if(r->z>kk->z)//use kp to insert,break;
				{
					r->link=kk;
					kp->link=r;
					break;
				}
				if(kk->link==NULL)//lianjie,become null,break
				{
					kk->link=r;
					r->link=NULL;
					break;
				}
			}
			}
		q=q->link;
		}
	p=p->link;
	}
	while(list3!=NULL)
	{
		printf("%d %d ",list3->x,list3->z);
		list3=list3->link;
	}
	return 0;
} 

