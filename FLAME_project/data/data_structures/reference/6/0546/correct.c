#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int a[105];
int main()
{
	int n,flag=0;
	while((scanf("%d",&n)&&(n!=-1)))
	{
		if(n==1)
		{
			int num;
			scanf("%d",&num);
			if(flag==100){
			printf("error ");
			continue;
		}
			else
			{
				flag++;
				a[flag]=num;
			}
		}
		else if(n==0)
		{
			if(flag==0)
			printf("error ");
			else
			{
				printf("%d ",a[flag]);
				flag--;
			}
		}
	}
	return 0;
} 

