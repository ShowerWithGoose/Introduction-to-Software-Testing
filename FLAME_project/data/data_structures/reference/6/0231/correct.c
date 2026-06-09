
#include <stdio.h>
int data[105];
int main()
{
	int n,s,top;	
	while(scanf("%d",&n)!=EOF)
	{
		if(n==1)
		{
			scanf("%d",&s);
			if(top>=100)
				printf("error ");
			else
				data[top++]=s;
		}
		else if(n==0)
		{
			if(top<1)
				printf("error ");
			else
			{
				printf("%d ",data[top-1]);
				top--;
			}
		}
		else if(n==-1)
		{
			break;
		}
	}
	return 0;
}

