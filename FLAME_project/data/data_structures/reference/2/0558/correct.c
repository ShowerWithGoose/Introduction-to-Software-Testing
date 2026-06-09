#include<stdio.h>
 
int cal(int a, int b, char op);	
int getnum();						
char getop();					
 
int main()
{
	int number[5];				
	char OP[1];			
 
	int num,result;			
	char op;			
 
	number[0] = getnum();
	OP[0] = getop();
	if (OP[0] != '=')
		number[1] = getnum();
	while (OP[0] != '=')
	{
		if (OP[0]=='*'||OP[0]=='/')	
		{
			number[0]=cal(number[0], number[1],OP[0]);
			OP[0]=getop();
			if (OP[0]!='=')
				number[1]=getnum();
		}
		else 
		{
			op = getop();
			if (op == '+' || op == '-' || op == '=')
			{
				number[0] = cal(number[0], number[1], OP[0]);
				OP[0] = op;
				if (op != '=')
					number[1] = getnum();
			}
			else if (op != '=')	
			{
				num = getnum();
				number[1] = cal(number[1], num, op);
			}
			else	
				OP[0] = op;
		}
 
	}
    result=number[0];
	printf("%d\n",result);
 
	return 0;
}
 
int cal(int a, int b, char op)
{
	int result;
	if (op == '+')
		result = a + b;
	else if (op == '-')
		result = a - b;
	else if (op == '*')
		result = a * b;
	else
		result = a / b;
	return result;
}
 
int getnum()
{
	int num;
	scanf(" %d", &num);
	return num;
}
char getop()
{
	char op;
	scanf(" %c", &op);
	return op;
}

