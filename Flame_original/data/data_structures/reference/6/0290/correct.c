#include<stdio.h>
int TOP;
void initStack()
{
	TOP=-1;
}
int isEmpty()
{
	return TOP==-1;
}
int isFull()
{
	return TOP==99;
}
void push(int s[],int item)
{
	if(isFull())
		printf("error ");
	else
		s[++TOP]=item;
}
void pop(int s[])
{
	if(isEmpty())
		printf("error ");
	else
		printf("%d ",s[TOP--]);
}
int main()
{
	int s[100]={};
	initStack(); 
	int n,m;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==1)
		{
			scanf("%d",&m);
			push(s,m);
		}
		else if(n==0)
		{
			pop(s);
		}
		else if(n==-1)
			break;
	}
	return 0;
}

