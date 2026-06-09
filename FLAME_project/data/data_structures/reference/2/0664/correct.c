#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int num1,num2,num3;
	char a1,a2,a3;
	num1=0;a1='+';
	while(1)
	{
		scanf("%d %c",&num2,&a2);
		while(a2=='*'||a2=='/')
		{
			scanf("%d %c",&num3,&a3);
			if(a2=='*')
			{
			num2=num2*num3;
			a2=a3;
			}
			else
			{
				num2=num2/num3;
				a2=a3;
			}
		}
		if(a1=='+')
		num1=num1+num2;
		if(a1=='-')
		num1=num1-num2;
		a1=a2;
		if(a2=='=')
		{
			printf("%d",num1);break;
		}

	}
			return 0;
 } 

