#include<stdio.h>
const int maxx=100;
int a[110],cnt,op,x;
int main()
{
	while(1)
	{
		scanf("%d",&op);
		if(op==-1)break;
		if(op==1)
		{
			scanf("%d",&x);
			if(cnt==100)
			{
				printf("error ");
				continue;
			}
			a[++cnt]=x;
		}
		if(op==0)
		{
			if(cnt==0)
			{
				printf("error ");
				continue;
			}
			printf("%d ",a[cnt]);
			cnt--;
		}
	}
}

