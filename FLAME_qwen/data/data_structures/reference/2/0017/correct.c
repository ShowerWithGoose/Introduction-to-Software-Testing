#include <stdio.h>
#include <string.h>
#include <math.h>
int judge(char);
int main()
{
	int num1,num2,num;
	char fu1,fu2,fu;
	num1 = 0;
	fu1 = '+';
	while (fu1 != '=')
	{	
		scanf("%d %c",&num2,&fu2);
		int num3;
		char fu3;	
		while(judge(fu2) == 1)//后为乘除法时 
			{
				scanf("%d %c",&num3,&fu3);
				if(fu2 == '*')
				{
					num2 = num2*num3;
					fu2 = fu3;
				}
				else if(fu2 == '/')
				{
					num2 = num2/num3;
					fu2 = fu3;
				}
			}
	
		if (judge(fu2) == 0)//后为加减法时 
		{
			if(fu1 == '+')
			{
				num1 = num1 + num2;
				fu1 = fu2; 
			}
			else if(fu1 == '-')
			{
				num1 = num1 - num2;
				fu1 = fu2; 
			}
		}
	} 
	printf("%d",num1);
	return 0; 
	
}
int judge(char a)
{
	if (a == '+' || a == '-' || a == '=')
		return 0;
	else if (a == '*' || a == '/')
		return 1;
}


