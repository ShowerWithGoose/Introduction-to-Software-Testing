#include<stdio.h>
#include<string.h>
int n;
int conse[12],flag[12];

void f(int t)
{
	int i;
	if(t == n + 1)
	{
		for(i=1;i<n;++i)
			printf("%d ",conse[i]);
		printf("%d\n",conse[n]);
		return ;
	}

	for(i=1;i<=n;++i)
	{
		if(flag[i]==0)
		{
			conse[t] = i; 
			flag[i] = 1;
			f(t + 1);
			conse[t] = 0;
			flag[i] = 0;
		}		 
	}
}

int main()
{
	memset(conse,0,sizeof(conse));
	memset(flag,0,sizeof(flag));
	scanf("%d",&n);
	f(1);
	return 0;
}


