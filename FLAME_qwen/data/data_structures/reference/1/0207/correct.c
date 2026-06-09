#include<stdio.h>
#include<string.h>
int a[1926],n,flag[1926]={0};
void deal(int cnt)
{
	int i=0;
	if(cnt==n+1)
	{
		for(i=1;i<=n;i++)
		{
			printf("%d ",a[i]);
		}
		printf("\n");
		return;
	}
	for(i=1;i<=n;i++)
	{
		if(flag[i]==0)
		{
			a[cnt]=i;
			flag[i]=1;
			deal(cnt+1);
			flag[i]=0;
		}
	}
	return;


}
int main()
{
	scanf("%d",&n);
	deal(1);
	return 0;
}

