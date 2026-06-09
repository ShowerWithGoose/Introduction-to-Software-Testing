#include<stdio.h>
void quanpailie(int *a, int *b, int n , int m)   
{
	int i;
	if(m==n+1)  
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
		if(b[i]==0)  
		{
			b[i]=1;   
			a[m]=i; 
			quanpailie(a,b,n,m+1); 
			b[i]=0;
		}
	}
}
int main()
{	
	int n,i;
	int a[11]={0};
	int b[11]={0};
	scanf("%d",&n);
	quanpailie(a,b,n,1);
	return 0;
}


