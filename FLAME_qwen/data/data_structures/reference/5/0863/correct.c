#include<stdio.h>
#include<stdlib.h>
typedef struct node* List;
struct node{
	long long codf;//系数 
	long long expon;//指数 
	List next;
};

List Read()
{
	long long num;long long cnt;char c1,c2;
	List first,second,third;

	scanf("%lld%c%lld%c",&num,&c1,&cnt,&c2);
	first=(List)malloc(sizeof(struct node));
	first->codf  =num;
	first->expon =cnt;
	first->next =NULL;
	second=first;
	if(c2!=' ')return first;
	while(scanf("%lld%c%lld%c",&num,&c1,&cnt,&c2)!=EOF)
	{

		third=(List)malloc(sizeof(struct node));
		third->codf  =num;
		third->expon =cnt;
		third->next =NULL;
		second->next =third;
		second=third;
		if(c2!=' ')break;
	}
	return first;
}

void Print(List L)
{
	
	if(L==NULL)
	return ;
	else 
	{
		while(L!=NULL)
	{
		if(L->codf !=0)
			printf("%lld %lld ",L->codf,L->expon  );
		L=L->next ;
	
	}	printf("\n");
	}
	
}
List multi(List p1,List p2)
{
	List i,j;List list=NULL;List point;
	List z,k;int flag=0;
	for(i=p1;i!=NULL;i=i->next )
	{
		for(j=p2;j!=NULL;j=j->next )
		{
			point=(List)malloc(sizeof(struct node));
			point->codf =i->codf *j->codf ;
			point->expon=i->expon +j->expon ;
			point->next =NULL;
			if(list==NULL)
			{
				list=point;
			}else
			{
				for(z=list;z!=NULL;k=z,z=z->next )
				{
					if(z->expon<point->expon )
					{
						break;
					}
					else if(z->expon == point->expon )
					{
						z->codf +=point->codf ;
						flag=1;
						break;
					}
				}
				if(flag==0)
				{
					k->next =point;
					point->next =z;
					
				}flag=0;
					
			}
		}
	}return list;
}
int main()
{
	List p1,p2; List p3;
	p1=Read();
//	Print(p1);

	p2=Read();
//	Print(p2);

	p3=multi(p1,p2);
	Print(p3);
}

