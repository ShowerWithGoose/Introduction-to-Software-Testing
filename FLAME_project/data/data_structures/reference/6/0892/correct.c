#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
int m,n;
struct list{
	int x;
	struct list* next;
};
struct list* first=NULL,*last=NULL;//记录首元素,尾元素的位置 
void insert()
{
	struct list* p;
	p=(struct list*)malloc(sizeof(struct list));
	if(first==NULL)
	{
		p->x=n;
		last=first=p;
	}
	else
	{
		p->x=n;
		last->next=p;
		last=p;
	}
}
void out()
{
	struct list* p,*r;
    //p=(struct list*)malloc(struct list);
    if(first==NULL)
    {
    	printf("error ");
	}
	else if(first==last)
	{
		printf("%d ",last->x);
		p=last;
		free(p);
		first=last=NULL;
	}
	else
	{
		printf("%d ",last->x);
		for(p=first;p->next!=last;p=p->next);
		r=p->next;
		free(r);
		last=p;
	}
}
int main()
{
	while(scanf("%d",&m)!=EOF)
	{
		if(m==1)
		{
			scanf("%d",&n);
			insert();
		}
		else if(m==0)
		{
			out();
		}
		else 
		{
			break;
		}
	}
	return 0;
}

