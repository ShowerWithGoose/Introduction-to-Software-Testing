#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
#define REP(i,a,b) for(register int i=a;i<=b;i++)
#define PER(i,a,b) for(register int i=a;i>=b;i--)
int num[110];
int main()
{
	int order;
	int number=0;
	while(scanf("%d",&order)&&order!=-1)
	{
		if(order==1)
		{
			number++;//´æ´¢Î»ÖÃ1-100
			if(number>100)
			printf("error ");
			else
			scanf("%d ",&num[number]);	
		}
		else if(order==0)
		{
		    if(number<1)
			printf("error ");
			else
			{
				printf("%d ",num[number]);
				num[number]=0;
				number--;
			}	
		}
	}
    return 0;
}


