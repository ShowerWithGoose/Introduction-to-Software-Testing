#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int a[100];
int m,n;
int main()
{
	scanf("%d",&n);
	f(a,1,n);

return 0;
}
int f(int a[],int m,int n)
{
	int i,j;
	if(m>n)
	{
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
		printf("\n");
		return 0;	
	}	
	for(i=1;i<=n;i++)
	{
		int h=0;
		for(j=0;j<m-1;j++)
		{
			if(a[j]==i)
			{
				h=1;
				break;
			}
		}
		if(h==0)
		{
			a[m-1]=i;
			f(a,m+1,n);
		}		
		
	}


}

