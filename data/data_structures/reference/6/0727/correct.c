#include<stdio.h>
int main()
{
	int a[100];
	int i,flag,n;
	for(i=0;;)
	{
		scanf("%d",&flag);
		if(flag==1)
		{
			scanf("%d",&n);
			if(i==100)
			printf("error");
			else
			{
				a[i]=n;
				i++;
			}
		}
		else if(flag==-1)
		break;
		else if(flag==0)
		{
			if(i==0)
			printf("error ");
			else
			{
				i--;
				printf("%d ",a[i]);
			}
		}
	}
}

