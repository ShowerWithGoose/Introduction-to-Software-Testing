#include<stdio.h>
#include<string.h>

int cal(int a,int b,char op)
{
	if (op == '+')
	return (a + b);
	if (op == '-')
	return (a - b);
	if (op == '*')
	return (a * b);
	if (op == '/')
	return (a / b);
}

int readnum()
{
	int num;
	scanf(" %d",&num);
	return num;
}

char readop()
{
	char op;
	scanf(" %c",&op);
	return op;
}

int main()
{
	int num1,num2,num3;
	char op1,op2;
	
	num1 = readnum();
	op1 = readop();
	if(op1 != '=')
	{
		num2 = readnum();
	}
	
	while(op1 != '=')
	{
		if (op1 == '*' || op1 == '/')
		{
			num1 = cal(num1,num2,op1);
			op1 = readop();
			if (op1 != '=')
			{
				num2 = readnum(); 
			}
		}
		else if (op1 == '+' || op1 == '-')
		{
			op2 = readop();
			if(op2 == '+' || op2 == '-' || op2 == '=')
			{
				num1 = cal(num1,num2,op1);
				op1 = op2;
				if (op2 != '=')
				{
				    num2 = readnum();	
				}
			}
			else if(op2 == '*' || op2 == '/')
			{
				num3 = readnum();
				num2 = cal(num2,num3,op2);
			}
		}
	}
	printf("%d",num1);
	return 0;
}


