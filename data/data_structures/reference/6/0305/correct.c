#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define MAX 1024
struct op{
	int xx[MAX];
	int top;
}s;
typedef struct op okx;
void initop(okx *s){
	s->top=-1;
}
int isempty(okx *s){
	return s->top==-1;
}
int isfull(okx *s){
	return s->top==MAX-1;
}
int push_op(okx *s,int data)
{
	if(isfull(s))
	printf("error ");
	else
	{
		s->top++;
		s->xx[s->top]=data;
	}
	return 1;
}
int run_op(okx *s,int item)
{
	if(isempty(s))
	printf("error ");
	else
	{
		item=s->xx[s->top];
		printf("%d ",item);
		s->top--;
	}
	return 1;
}
int main()
{
	initop(&s);
	int m,item;
	while(1)
	{
		scanf("%d",&m);
		switch(m)
		{
			case 1:{
				scanf("%d",&item);
				push_op(&s,item);
				break;
			}
			case 0:{
				run_op(&s,item);
				break;
			}
			case -1:{
				return 0;
			}
		}
	}
}




