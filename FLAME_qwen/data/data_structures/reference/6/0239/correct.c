#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define  max 100
int s[max];
int top=-1;
void initstack()
{
	top=-1;
}
void push(int x,int s[])
{
	
	if(top==max-1)
	printf("error ");
	else 
	{
		s[++top]=x;
	}
}
void pop(int s[])
{
	if(top==-1)
	printf("error ");
	else 
	{
		printf("%d ",s[top]);
		top--;
	}
}
int main()
{
	
	int ss[1050],x,num=0;
	while(~scanf("%d",&x))
	{
		if(x!=-1)
		{
			ss[num]=x;
			num++;
		}
		else if(x==-1)
		break;
	}
	int i=0;
//	printf("%d\n",num);
	while(i<num)
	{
		if(ss[i]==1)
		{
			push(ss[i+1],s);
			i+=2;
		}
		else if(ss[i]==0)
		{
			pop(s);
			i++;
		}
	}
	
	return 0;
}

