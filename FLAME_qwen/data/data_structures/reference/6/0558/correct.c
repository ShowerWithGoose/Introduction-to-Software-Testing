#include<stdio.h>
#include<stdlib.h>
#define max 101
struct stack
{
	int num[max];
	int top;
}s;
typedef struct stack stack;
void initstack(struct stack *s){s->top=-1;
}
int pushstack(struct stack *s, int num)
{
    if (isfullstack(s) != 0)
    {
        printf("error ");
        return 0;
    }
    s->num[++s->top]=num;
    return 1;
}
int popstack(struct stack *s)
{
	int pop;
    if (s->top == -1)
    {
        printf("error ");
        return 0;
    }
    pop = s->num[s->top--];
    printf("%d ",pop);
    return 1;
}
int isfullstack(struct stack *s)
{
	return s->top==max;
}
int main()
{


	int op,num;
	initstack(&s);
	while(1)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d",&num);
			pushstack(&s,num);
		}
		else if(op==0)
		popstack(&s);
		else if(op==-1)
		{
			break;
		}
	}
	return 0;
}


