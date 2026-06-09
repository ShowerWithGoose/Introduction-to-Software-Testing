#include<stdio.h>
#define maxsize 999
int top=-1; 
int isEmpty(int s[])
{
	return top==-1;
}
int isFull(int s[])
{
	return top==maxsize-1;
}
void push(int s[])
{
	int item;
	scanf("%d",&item);
	if(isFull(s))
	{
		printf("error ");
	}
	else
	s[++top]=item;
}
void pop(int s[])
{
	if(isEmpty(s))
	printf("error ");
	else
	printf("%d ",s[top--]);
}

int main()
{
	int s[1000]={0};
	int jud;
	while(scanf("%d",&jud)!=EOF)
	{
		if(jud==1)
		{
			push(s);
		}
		else if(jud==0)
		{
			pop(s);
		}
		else
		return -1;
	 } 
 } 

