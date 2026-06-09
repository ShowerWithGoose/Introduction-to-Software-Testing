#include<stdio.h>
int stk[105],p,d;
int main()
{
	while(scanf("%d",&d),d!=-1)
	{
		if(d)
		{
			scanf("%d",&d);
			if(p<100)	stk[p++]=d;
			else	printf("error ");
		}
		else
		{
			if(!p)	printf("error ");
			else	printf("%d ",stk[--p]);
		}
	}
	return 0;
}

