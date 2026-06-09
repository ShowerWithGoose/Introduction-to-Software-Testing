#include<stdio.h>
#include<string.h>
#define MAXSIZE 100
int stack[MAXSIZE];
int top=-1;
int move,subject;
int isempty(int stack[]);
int isfull(int stack[]);
int k=0;
struct output{
	int Item;
	int flag;
};
typedef struct output out;
out result[1000];
void push(int a)
{
	scanf("%d",&subject);
	if(isfull(stack))
	{
	result[k++].flag=1;
	}
	else
	stack[++top]=subject;
}
void pop(int a)
{
	if(isempty(stack))
	{
	result[k++].flag=1;
	}
	else
	result[k++].Item=stack[top--];
}
int main()
{
    while(scanf("%d",&move),move!=-1)
	{
		switch(move){
			case 0:pop(subject);break;
			case 1:push(subject);break;
		}
	}
	int i;
	for(i=0;i<k;i++)
	{
		if(result[i].flag==1)
		{
			printf("error ");
		}
		else
		printf("%d ",result[i].Item);
	}
	return 0;
}
int isempty(int stack[])
{
	return top==-1;
}
int isfull(int stack[])
{
	return top==MAXSIZE-1;
}

