#include<stdio.h>
#include<stdlib.h>
struct zh* t;
struct zh stack;
struct zh{
	int shu;
	struct zh* link;
} s;

typedef struct zh* Nodeptr;






int ie()
{
	return t==NULL;
}
void chu()
{
	Nodeptr l;
	int i;
	if(ie())
	{
	
	printf("error ");
    }
	else
	{
		l=t;
		i=t->shu;
		t=t->link;
		free(l);
		printf("%d ",i);
	}
}
void k()
{
	t=NULL;
}


void ru(int m)
{
	Nodeptr p;
	if((p=(Nodeptr)malloc(sizeof(s)))==NULL)
	{
		printf("error ");
	}
	else
	{
	
	p->shu=m;
	p->link=t;
	t=p;
    }
}




int main()
{
	int flag;
	int n;
	k;
	while(1)
	{
	    scanf("%d",&flag);
	    if(flag==1)
	    {
	    	scanf("%d",&n);
	    	ru(n);
		}
		else if(flag==0)
		{
			chu();
		}
		else if(flag==-1)
		{
			break;
		}
	}
	return 0;
}

