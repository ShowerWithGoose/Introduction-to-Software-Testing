#include<stdio.h>
int main()
{
	int a[105],MAX=100,p,top=0;
	while(1)
	{
		scanf("%d",&p);
		if(p==-1)
		{
			break;
		}
		else if(p==1)
		{
			if(top==MAX)
			{
				printf("error ");
			}
			else
			{
				scanf("%d ",&a[top++]);
			}
		}
		else
		{
			if(top==0)
			{
				printf("error ");
			}
			else
			{
				printf("%d ",a[--top]);
			}
		}
	}
	return 0;
}

