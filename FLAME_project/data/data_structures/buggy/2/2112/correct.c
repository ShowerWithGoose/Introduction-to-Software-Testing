#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int main() 
{
	long long num,result=0,zhong=1;
	char c;
	
	while(1)
	{
		scanf("%lld %c",&num,&c);
		zhong=zhong*num;
		while(c=='*'||c=='/')
		{
			scanf("%lld",&num);
			if(c=='*')
			{
				zhong=zhong*num;
			}
			else 
			{
				zhong=zhong/num;
			}
			scanf(" %c",&c);
		}
		result=result+zhong;
		if(c=='+')
		{
			zhong=1;
		}
		else if(c=='-')
		{
			zhong=-1;
		}
		else 
		{
			printf("%lld",result);
			break;
		}
	}
	return 0;
}

