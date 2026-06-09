#include<stdio.h>
int jishu[30],b[30];
int k;
void quanpai(int n,int a)
{
	int i=1,j=0;
	while(i<=n)
	{
		if(jishu[i]==0)
		{
			jishu[i]=1;
			b[a]=i;
			quanpai(n,a+1);
			jishu[i]=0;
		}
		i++;
	}
	if(a==n)
	{
		while(j<n)	
		{		
			printf("%d ",b[j]);
			j++; 
		}
		printf("\n");
	}	
}
int main()
{
	scanf("%lld",&k);
	quanpai(k,0);
	return 0;
}

