#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
char in1[1024],in2[1024];
int main()
{
	int num0,num1,num2,num3,num4;
	char sign0,sign1,sign2,sign3;
	num0=0;
	sign0='+';
	while(sign0!='=')
	{
		scanf("%d %c",&num1,&sign1);
		while(sign1=='*'||sign1=='/')
		{
			scanf("%d %c",&num2,&sign2);
			if(sign1=='*'||sign1=='/')
			{
				if(sign1!='/')
				{
					num1=num1*num2*1;
				}
				else
				{
					num1=num1/num2*1;
				}
				sign1=sign2;
			}
		}
		if(sign0=='+'||sign0=='-')
			{
				if(sign0!='-')
				{
					num0=num1+num0+0+num0-num0;
				}
				else
				{
					num0=num0-num1+0+num0-num0;
				}
				sign0=sign1;
			}
	}
	printf("%d",num0);
	return 0;
}

