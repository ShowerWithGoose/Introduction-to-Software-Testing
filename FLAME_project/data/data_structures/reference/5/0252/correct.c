#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Struct 
{
	long long co;
	long long power;
	struct Struct *link;
};
struct Struct *insert(struct Struct *list,long long coe,long long pow)
{
	struct Struct *p,*q,*r;
	r=(struct Struct *)malloc(sizeof(struct Struct));
	r->co=coe;
	r->power=pow;
	r->link=NULL;
	if(list==NULL)
	return r;
	else
	{
		for(p=list;p!=NULL&&(pow<p->power);q=p,p=p->link);//找到要插入的位置p 
		
		if(p==NULL)
		{
			q->link=r;
			return list; 
		}
		if(pow==p->power)
		{
			p->co+=coe;
			return list;
		}
		else 
		{
			if(p==list)
			{
				r->link=p;
				return r;
			}
			else
			{
				q->link=r;
				r->link=p;
				return list;
			}
		}
	}
}
int main()
{
	struct Struct *list,*list1,*list2,*p,*p1,*p2,*r1,*r2;
	long long int a,n;
	char c;
	list1=p1=NULL;
	do
	{
		r1=(struct Struct*)malloc(sizeof(struct Struct));
		scanf("%lld%lld%c",&a,&n,&c);
		r1->co=a;
		r1->power=n;
		r1->link=NULL;
		if(list1==NULL)
		{
			list1=p1=r1;
		}
		else
		{
			p1->link=r1;
			p1=p1->link;
		}
	}
	while(c!='\n');
	list2=p2=NULL;
	do
	{
		r2=(struct Struct*)malloc(sizeof(struct Struct));
		scanf("%lld%lld%c",&a,&n,&c);
		r2->co=a;
		r2->power=n;
		r2->link=NULL;
		if(list2==NULL)
		{
			list2=p2=r2;
		}
		else
		{
			p2->link=r2;
			p2=p2->link;
		}
	}
	while(c!='\n');
	list=p=NULL; 
	for(p1=list1;p1!=NULL;p1=p1->link)
	{
		for(p2=list2;p2!=NULL;p2=p2->link)
		{	
			list=insert(list,(p1->co)*(p2->co),(p1->power)+(p2->power));
		}
	}
	for(p=list;p!=NULL;p=p->link)
	{
		printf("%lld %lld ",p->co,p->power);
	}
	return 0;
}

