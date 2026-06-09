#include<stdio.h>
int a[10],out[10],s[10];
void fun(int k,int n)
{
	int j;
	if(k!=0)
	{
		for(j=0;j<n;j++)
		{
			if(s[j]==0)
			{
				out[n-k]=a[j];
				s[j]=1;
				fun(k-1,n);
				s[j]=0;
				
			}
		}
	}
	else
	{
		int m;
		for(m=0;m<n;m++)
		printf("%d ",out[m]);
		printf("\n");
	}
}
int main()
{
	int n,k,i;
	
	scanf("%d",&n);
	k=n;
	for(i=0;i<n;i++)
	{
		a[i]=i+1;
	}
	fun(k,n);
	return 0;
} 

