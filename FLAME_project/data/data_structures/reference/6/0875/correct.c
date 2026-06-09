#include <stdio.h>
int a[105];
int main()
{
	int place=1,i,work;
	while(scanf("%d",&work)!=EOF)
	{
		if(work==-1)break;
		else if(work==1)
		{
			if(place==101)
			{
				printf("error ");
				continue;
			}
			scanf("%d",&a[place++]);
		}
		else if(work==0)
		{
			if((place-1)==0)
			{
				printf("error ");
				continue;
			}
			printf("%d ",a[place-1]);
			a[place-1]=0;
			place--;
		}
	}
	return 0;
} 

