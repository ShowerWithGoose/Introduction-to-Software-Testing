#include<stdio.h>
int a[1005];
int main()
{
	int s,n=0,q;
	while(scanf("%d",&s)!=EOF)
	{
		if(s==1)
		{
			if(n>=99)
			{
				printf("error ");
			}
			else
			{
				scanf("%d",&q);
				a[n]=q;
				n++;
			}
		}
		if(s==0)
		{
			if(n<=0)
			{
				printf("error ");
			}
			else
			{
				printf("%d ",a[n-1]);
				n--;
			}
		}
		if(s==-1)
		break;

	}
}

