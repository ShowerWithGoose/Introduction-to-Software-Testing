#include<stdio.h>
#include<string.h>
int main()
{
	int n,top=-1;
	int list[101];
	while(~scanf("%d",&n))
	{
		if(n==-1)
		return 0;
		else if(n==1)
		{
			if(top>=99)
			printf("error ");
		}
		else if(n==0)
		{
			if(top<=-1)
			printf("error ");
			else
			{
				printf("%d ",list[top]);
				top--;
			}
		}
		else
		{
			top++;
			list[top]=n;
		}
	}
	return 0;	
}

