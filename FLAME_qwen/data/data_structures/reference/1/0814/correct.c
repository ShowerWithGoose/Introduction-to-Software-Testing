#include <stdio.h>
int main()
{
	int i,k,j,n,a[10]={1,2,3,4,5,6,7,8,9,10};
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	for(k=n-1;k>=0;k--)
	{
		int count[11]={0};
		if(a[k]<n)
		{
			for(i=0;i<k;i++) count[a[i]]++;
			for(a[k]++;count[a[k]]!=0;a[k]++);
			if(a[k]>n) continue;
			count[a[k]]++;
			for(j=1;j<=n;j++)
			{
				if(count[j]==0)
				{
					a[++k]=j;
				}
			}
			for(i=0;i<n;i++) printf("%d ",a[i]);
			printf("\n");
		}
	}
	return 0;
}

