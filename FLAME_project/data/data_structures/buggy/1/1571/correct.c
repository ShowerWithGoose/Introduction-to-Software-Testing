#include <stdio.h>
int a[110],b[110];
void all(int *a,int *b,int n,int d)
{
	int i;
	if(d==n+1)//深度匹配时 
	{
		for(i=1;i<=n;i++)
		{
			printf("%d ",a[i]);//输出数字 
			
		}
		
		printf("\n");
		return; 
	}
	for(i=1;i<=n;i++)
	{
		if(b[i]==0)//判断是否使用过 
		{
			b[i]=1;
			a[d]=i;
			all(a,b,n,d+1);
			b[i]=0;
		}
	}
}
int main()
{
	int n,i;
	scanf("%d",&n);
	all(a,b,n,1);
	return 0; 
}

