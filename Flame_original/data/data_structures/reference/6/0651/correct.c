#include<stdio.h>
#include<stdlib.h>
struct zhan{
	int data;
	struct zhan* link;
};
struct zhan stack;
typedef struct zhan* Nodeptr;
Nodeptr p;
struct zhan* Top;
int isEmpty()
{
	return Top==NULL;
}
void initStack()
{
	Top==NULL;
}
void push(int );
void pop();
int main()
{
	int flag;
	int m;
	while(1)
	{
		scanf("%d",&flag);
		if(flag==1)
		{
			scanf("%d",&m);
			push(m);
		}
		if(flag==0)
		{
			pop();
		}
		if(flag==-1)
		{
			break;
		}
	}
	return 0;
}
void push(int m)
{
	if((p=(Nodeptr)malloc(sizeof(struct zhan)))==NULL)
	{
		printf("error ");
	}
	else
	{
		p->data=m;
		p->link=Top;
		Top=p;
	}
}
void pop()
{
	int n;
	if(isEmpty())
	{
		printf("error ");
	}
	else
	{
		p=Top;
		n=Top->data;
		Top=Top->link;
		free(p);
		printf("%d ",n); 
	}
}

