#include<stdio.h>
#include<malloc.h>
#define maxsize 100
typedef struct STACK{
	int*base;
	int*top;
	int stacksize;
}stack;
void initstack(stack*s)
{
	s->base=(int*)malloc((maxsize)*sizeof(int));
	s->top=s->base;
	s->stacksize=maxsize;
}
int pushstack(stack*s,int *e)
{
	if(s->top-s->base==s->stacksize)
	return 0;
    *s->top++=*e;
    return 1;
}
int popstack(stack*s,int*e)
{
	if(s->top==s->base)
	return 0;
	*e=*--s->top;
	return 1;
}
int main()
{    
     int a,b;
     int e;
     stack s;
	initstack(&s);
	while(1)
	{
	scanf("%d",&a);
	   if(a==-1)
	   break;
		if(a==1)
		{
			scanf("%d",&b);
			if(pushstack(&s,&b)==0)
			{
				printf("error ");
			}
			continue;
		}
		if(a==0)
		{    
		if(popstack(&s,&e)==0)
			{
			printf("error ");
			continue;
		}
		else
		{
		printf("%d ",e);
		continue;
	     }	
		 } 
 }
}



