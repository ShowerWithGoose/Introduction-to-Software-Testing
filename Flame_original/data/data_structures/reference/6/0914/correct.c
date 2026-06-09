#include <stdio.h>
int main()
{
	int stack[101],now=0,op=0;
	while(scanf("%d",&op)!=-1)
	{
		if(op==0)
		{
			if(now==0)
			{
				printf("error ");
			}
			else
			{
				now--;
				printf("%d ",stack[now]);
	    	}
		}
		else
		{
			if(now==100)
			{
				printf("error ");
				scanf("%d",&op);
			}
			else
			{
			    scanf("%d",&stack[now]);
				now++;	
    		}
		}
	}
	return 0;
}

