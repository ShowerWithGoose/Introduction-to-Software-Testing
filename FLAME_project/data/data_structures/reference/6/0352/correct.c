#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
typedef struct shu
{
	int n;
	struct shu *ptr;
}stack;
stack *creat(int x)
{
	stack *tem=(stack *)malloc(sizeof(stack));
	tem->n=x;
	tem->ptr=NULL;
	return tem;
}
stack *push(stack *top,int x)
{
	stack *p=creat(x);
	p->ptr=top;
	top=p;
	return top;
}
stack *pop(stack *top)
{
	if(top->n!=0)
	{
		stack *t=top;
		top=top->ptr;
		printf("%d ",t->n);
		free(t);
	}
	else 
	{
		printf("error ");
	}
	return top;
}
int main()
{
	stack *top=creat(0);
	int caozuo,num;
	scanf("%d",&caozuo);
	while(caozuo!=-1)
	{
		//printf("%d\n",top->n); 
		if(caozuo==1)
		{
			scanf("%d",&num);
			top=push(top,num);
		}
		else if(caozuo==0)
		{
			top=pop(top);
		}
		scanf("%d",&caozuo);
	}
	return 0;
}


