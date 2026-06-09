#include<stdio.h>
int n,a[50],b[50];
void work(int p)
{
	int c,i;
	if(p==n+1)
	{
		for(c=1;c<=n;c++)
		printf("%d ",a[c]);
		printf("\n");
		return;
	}
	for(i=1;i<=n;i++)
	{
		if(!b[i])
		{
			a[p]=i;
			b[i]=1;
			work(p+1);
			b[i]=0;
		}
	}
}
int main(){
	scanf("%d",&n);
	work(1);
} 

