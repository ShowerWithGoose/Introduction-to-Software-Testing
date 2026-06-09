#include <stdio.h>
#include <malloc.h>
typedef struct node{
	int k;
	int a;
	struct node *link;
}Node,*Nodeptr;
Nodeptr create1()
{
	Nodeptr list,p,q;
	char c;
	int k1;
	int a1;
	list=NULL;
	do{
		scanf("%d%d",&k1,&a1);
		q=(Nodeptr)malloc(sizeof(Node));
		q->a=a1;
		q->k=k1;
		q->link=NULL;
		if(list==NULL)
		{
			list=p=q;
		}
		else
		{
			p->link=q;
		}
		p=q;
	}while(c=getchar()!='\n');
	return list;
}
int main()
{
	Nodeptr list1,list2,p,q,flag;
	list1=create1();
	int k1;
	int a1;
	int i,j;
	char c;
	scanf("%d%d",&k1,&a1);
	list2=NULL;
	for(flag=list1;flag!=NULL;flag=flag->link)
	{
		q=(Nodeptr)malloc(sizeof(Node));
		q->a=(flag->a)+a1;
		q->k=(flag->k)*k1;
		q->link=NULL;
		if(list2==NULL)
		{
			list2=p=q;
		}
		else
		{
			p->link=q;
		}
		p=q;
	}
	Nodeptr flag2,flag2left;
	while(c=getchar()!='\n')//一直读取 
	{
		scanf("%d%d",&k1,&a1);
		for(flag=list1;flag!=NULL;flag=flag->link) //遍历list1 
		{
			q=(Nodeptr)malloc(sizeof(Node));
			q->k=k1*(flag->k); 
			q->a=a1+(flag->a); 
			q->link=NULL;
			for(flag2=list2;flag2!=NULL;flag2=flag2->link) //开始插入 (遍历list2) 
			{
				if((flag2->a)==(q->a))//合并 
				{
					flag2->k=(flag2->k)+(q->k);
					break;
				}
		        if((flag2->a)<(q->a)) //插入 
				{
					if(flag2==list2)
					{
						q->link=list2;
						list2=q;
						break;
					}
					else
					{
						flag2left->link=q;
						q->link=flag2;
						break;
				    }
				}
				flag2left=flag2;
			}
			if(flag2==NULL)
			{
				flag2left->link=q;				
			}
		}
	}
	for(flag2=list2;flag2!=NULL;flag2=flag2->link)
	{
		printf("%d %d ",flag2->k,flag2->a);	
	}
	return 0;
}



