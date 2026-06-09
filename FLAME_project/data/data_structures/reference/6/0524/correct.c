#include<stdio.h>
int stack[105],a,b;
int main()
{
	while(scanf("%d",&b)!=-1)
	{
		if(b)
		{
			scanf("%d",&b);
			if(a<100)
			stack[a++]=b;
			else
			printf("error ");
		}
		else
		{
			if(!a)
			printf("error ");
			else
			printf("%d ",stack[--a]);
		}
	}
	return 0;
}


