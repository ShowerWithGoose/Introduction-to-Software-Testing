#include<stdio.h>
int a[11],b[11],n;
void quanpaile(int k)
{
	int i;
	if(k>n)
	{
		for(i=1;i<n;i++)
		{
			printf("%d ",a[i]);
		}
		printf("%d\n",a[n]);
		return;
	}
	else
	{
		for(i=1;i<=n;i++)
		{
			if(b[i]==0)
			{
				a[k]=i;b[i]=1;
				quanpaile(k+1);
				a[k]=0;b[i]=0;
			}
		}
	} 
}
int main()
{
	scanf("%d",&n);
	quanpaile(1);
	return 0;
}

