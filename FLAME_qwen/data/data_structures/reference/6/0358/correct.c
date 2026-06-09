#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct stack{
	int top;
	int data[107];
}s;

int i,n,m,flag=0;
int main()
{	
	s.top=0;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==1)
		{
			scanf("%d",&m);
			if(s.top>=100)
			{
				printf("error ");
			}
			else
			{
				s.data[s.top]=m;
				s.top++;
			}
		}
		else if(n==0)
		{
			if(s.top<1)
			{
				printf("error ");
				flag=1;
			}
			else
			{
				s.top--;
			}
		}
		else if(n==-1)
		{
			break;
		}
		
		if(n!=1 && n!=-1 && flag==0)
		{
			printf("%d ",s.data[s.top]);
		}
		flag=0;
	}
	
	return 0;
}




