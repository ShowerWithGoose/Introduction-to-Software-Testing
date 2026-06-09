#include <stdio.h>
int a[15];
int time[15]; 
void quanpailie(int n,int k)
{
	int j;
	if(k==n+1)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d ",a[j]);
		}
		printf("\n");
	}
	else{
		for(j=1;j<=n;j++)
		{
			if(time[j]==0)
			{
				a[k]=j;
				time[j]=1;
				quanpailie(n,k+1);
				time[j]=0;
			}
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	 quanpailie(n,1);
	 return 0; 
 } 



