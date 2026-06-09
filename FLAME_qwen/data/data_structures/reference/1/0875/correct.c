#include <stdio.h>
#include <string.h>
int a[20],b[20];
int main()
{
	int n;
	scanf("%d",&n);
	f(1,n);
	return 0;
	
} 

void f(int m,int n)
{
		for(int i=1;i<=n;i++)
		{
			
				if(b[i]==0)
				{
					a[m]=i;
					b[i]=1;
					f(m+1,n);
					b[i]=0;
				}
			
		}
			if(m>n)
			{
				for(int j=1;j<=n;j++)printf("%d ",a[j]);
				printf("\n");
			}	
		
}
 


