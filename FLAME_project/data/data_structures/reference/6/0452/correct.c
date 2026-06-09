#include <stdio.h>
int main()
{
	int stack[105]={0};
	int i=0,n,j;
	int a[105]={0};
	while(scanf("%d",&a[i]),a[i]!=-1)
	{
		i++;
	}
	n=i;
	j=0;
	i=0;
	for(i=0;i<=n;i++)
	{
		if(a[i]==1&&j<=100)
		{
			stack[j]=a[i+1];
			j++;
			i++;
		}
		else if(a[i]==1&&j>100)
		{
			printf("error ");
			i++;
		}
		else if(a[i]==0&&j>0)
		{
			printf("%d ",stack[j-1]);
			j--;
		}
		else if(a[i]==0&&j<=0)
		{
			printf("error ");
		}
	}
	return 0;
}

