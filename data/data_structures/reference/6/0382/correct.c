#include<stdio.h>
int main()
{
	int top=0,n,num;
	int s[105]={0};
	while(1)
	{
		scanf("%d",&n);
		if(n==1)
		{
			scanf("%d",&num);
			if(top<100)
			{
				s[top]=num;
				top++;
			}
			else
			printf("error ");
		}
		else if(n==0)
		{
			if(top==0)
			printf("error ");
			else
			{
				printf("%d ",s[top-1]);
				s[top-1]=0;
				top--;
			}
		}
		else if(n==-1)
		break;
		
	}
	return 0;
 } 

