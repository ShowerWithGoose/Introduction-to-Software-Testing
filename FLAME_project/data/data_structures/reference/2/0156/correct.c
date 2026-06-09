#include<stdio.h>
 
int cal(int a, int b, char op);
int readNum();
char readOp();
 
int main()
{
	int a[2];
	char b[1];
 
	int num;
	char op;
 
	a[0] = readNum();
	b[0] = readOp();
	if (b[0] != '=')
		a[1] = readNum();
	while (b[0] != '=')
	{
		if (b[0] == '*' || b[0] == '/')	
		{
			a[0] = cal(a[0], a[1], b[0]);
			b[0] = readOp();
			if (b[0] != '=')
				a[1] = readNum();
		}
		else
		{
			op = readOp();
			if (op == '+' || op == '-' || op == '=')
			{
				a[0] = cal(a[0], a[1], b[0]);
				b[0] = op;
				if (op != '=')
					a[1] = readNum();
			}
			else if (op != '=')	
			{
				num = readNum();
				a[1] = cal(a[1], num, op);
			}
			else
				b[0] = op;
		}
 
	}
	
	printf("%d\n", a[0]);
 
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
 
int readNum()
{
	int num;
	scanf(" %d", &num);
	return num;
}
char readOp()
{
	char op;
	scanf(" %c", &op);
	return op;
}

