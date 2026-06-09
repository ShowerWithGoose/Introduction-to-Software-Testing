#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int a[100];
	int top,count,i=0;
	int b,input;
	while(scanf("%d",&b)!=EOF)
	{
		if(b==1)
		{
			scanf("%d",&a[i++]);
			top=i-1;
		}
		else if(b==0&&i==0)
		printf("error ");
		else if(b==0)
		printf("%d ",a[--i]);
		else
		break;
	}
	return 0;
}

