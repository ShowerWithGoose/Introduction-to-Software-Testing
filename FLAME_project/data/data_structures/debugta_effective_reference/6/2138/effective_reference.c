#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
int request,x;
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
		p->x=x;
		last=first=p;
	}
	else
	{
		p->x=x;
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
	while(scanf("%d",&request)!=EOF)
	{
		if(request==1)
		{
			scanf("%d",&x);
			insert();
		}
		else if(request==0)
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

