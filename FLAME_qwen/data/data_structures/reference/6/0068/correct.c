#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>//快排 
#define eps 1e-8
#define pi 3.14
#define eof EOF
int a[100],top=0;
int isempty(void);
int isnull(void);

int main()
{	
	int flag;
	while(1)
	{
		scanf("%d",&flag);
		if(flag==1)
		{
			if(isfull()==1)//满了还要加 
			{
				printf("error ");
			}
			else if(isfull()==0)
			{
				scanf("%d",&a[top]);
				top++;
			}
		}
		else if(flag==0)
		{
			if(isempty()==1)//空了还要出
			{
				printf("error ");
			}
			else if(isempty()==0)
			{
				printf("%d ",a[top-1]);
				top--;
			}
		}
		else if(flag==-1)
		{
			break;
		}
		
	}
}
int isempty(void)
{
	if(top==0)
	return 1;//kong 
	else 
	return 0;
}
int isfull(void)
{
	if(top==101)
	return 1;//manle
	else 
	return 0;
}

