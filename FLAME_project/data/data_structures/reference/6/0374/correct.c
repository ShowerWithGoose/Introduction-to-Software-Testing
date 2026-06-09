#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
 
struct stack
{
    int num;
    int list[100];
}a;
 
int main()
{
    int n,m;
    a.num=0;
    while(scanf("%d",&n))
    {
    	if(n==-1)
    		break;
    	else if(n==1)
    	{
    		scanf("%d",&m);
    		if(a.num>=100)
    		{
    			printf("error ");
    			continue;
			}
			else
			{
				a.list[a.num]=m;
				a.num++;
			}
		}
		else if(n==0)
		{
			if(a.num<=0)
			{
				printf("error ");
				continue;
			}
			else
			{
				printf("%d ",a.list[a.num-1]);
				a.num--;
			}
		}
	}
    return 0;
}



