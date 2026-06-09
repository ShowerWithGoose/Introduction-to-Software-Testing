#include<stdio.h> 
#define MAXSIZE 100
int STACK[MAXSIZE]={0};
int TOP;
void initStack()
{
	TOP=-1;
}
int isfull()
{
	if(TOP==MAXSIZE-1)
	{
	return 1;	
	}
	else 
	{
	return 0;	
	}
}
int isempty()
{
	if(TOP==-1)
	{
	return 1;	
	}
	else 
	{
	return 0;	
	}
}
void push(int item)
{
	if(isfull()==1)
	{
		printf("error ");
	}
	else if(isfull()==0){
		STACK[++TOP]=item;
	}
}
void pop()
{
	if(isempty()==1)
	{
		printf("error ");
	}
	else if(isempty()==0){
		printf("%d ",STACK[TOP--]);
	}
}
int main()
{
	int item[10000];
	int i=0;
	initStack();
    while(scanf("%d",&item[i])!=EOF){
		
		if(item[i]!=0&&item[i]!=-1&&item[i]!=1)
		{
			isfull();
			push(item[i]);
		}
		if(item[i]==0)
		{
			isempty();
			pop();
			i++;
		}
		if(item[i]==-1)
		{
			break;
		}
		
	}
	return 0;
}

