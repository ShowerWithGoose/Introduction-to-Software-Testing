#include<stdio.h>

int main()
{
	int x,i=-1,j;
	int a[105]={0}; 
	while(scanf("%d",&x)!=EOF)
	{
		switch(x)
		{
			case 1:
				if(i==99)
				{
					printf("error ");
				}
				else
				{
					scanf("%d",&a[++i]);
				}
				break;
			case 0:
				if(i==-1)
				{
					printf("error ");
				}
				else
				{
					printf("%d ",a[i--]);
				}
				break;
			case -1:
				break;
		}
	}
	return 0;
}

