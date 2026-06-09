#include<stdio.h>
int a[10000],stack[100];
int main()
{
	int i=0;
	for(;;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==-1)
		break;
	}
	int top=0,j=0;
	for(j=0;j<=i;j++)
	{
		if(a[j]==-1)
		break;
		else if(a[j]==1)
		{
			j++;
			if(top==100)
			{
				printf("error ");
				continue;
			}
			stack[top]=a[j];
			top++;
		}
		else if(a[j]==0)
		{
			if(top==0)
			{
				printf("error ");
				continue;
			}
			printf("%d ",stack[top-1]);
			top--;
		}
	}
	return 0;
}

