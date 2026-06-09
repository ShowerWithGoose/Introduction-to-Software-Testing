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
struct list* top=NULL,*last=NULL;//记录首元素,尾元素的位置 
void insert()
{
	struct list* p;
	p=(struct list*)malloc(sizeof(struct list));
	if(top==NULL)
	{
		p->x=n;
		last=top=p;
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
    if(top==NULL)
    {
    	printf("error ");
	}
	else if(top==last)
	{
		printf("%d ",last->x);
		p=last;
		free(p);
		top=last=NULL;
	}
	else
	{
		printf("%d ",last->x);
		for(p=top;p->next!=last;p=p->next);
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

