#include<stdio.h>
int s[105]; 
int main()
{
	int top=0;
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==1)
		{
			int m;
			scanf("%d",&m);
			s[top++]=m;
		}
		else if(n==0)
		{
			top--;
			if(top>=0)
				printf("%d ",s[top]);
			else
			{
				printf("error ");
				top=0;
			}
			
		}
		else if(n==-1)
			return 0;
	}
	return 0;
}

