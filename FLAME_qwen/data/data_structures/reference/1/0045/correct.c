#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

int x[20],b[20],n,t=0;

void def(int step)
{
	int i;
	if(step==n+1)
	{
		for(i=1;i<=n;i++)
		{
			printf("%d ",x[i]);
		}
		printf("\n");
		t++;
		return;
	}
	for(i=1;i<=n;i++)
	{
		if(b[i]==0)
		{
			x[step]=i;
			b[i]=1;
			def(step+1);
			b[i]=0;
		}
	}
}

int main()
{
	scanf("%d",&n);
	def(1);	
}



