#include<stdio.h>
 
int ss(int a, int b, char op);
char Op();
int Num();
 
int main()
{
	int a1, a2, num;
	char b, op;

	a1 = Num();
	b = Op();
	
	if (b != '='){
		a2 = Num();
	}
	
	while (b != '='){
		if (b == '/' || b == '*')
		{
			a1 = ss(a1, a2, b);
			b = Op();
			
			if (b != '=')
				a2 = Num();
		}
		
		else
		{
			op = Op();
			if (op == '+' || op == '-')
			{
				a1 = ss(a1, a2, b);
				b = op;
				
				if (op != '=')
					a2 = Num();
			}
			
			else if(op == '=')
			{
				a1 = ss(a1, a2, b);
				b = op;
				
				if (op != '=')
					a2 = Num();
			}
			
			else if (op != '=')
			{
				num = Num();
				a2 = ss(a2, num, op);
			}
		}
 
	}

	printf("%d\n", a1);
 
	return 0;
}
 
int ss(int i, int j, char op)
{
	int result;
	if (op == '+')
		result = i + j;
	else if (op == '-')
		result = i - j;
	else if (op == '*')
		result = i * j;
	else
		result = i / j;
	return result;
}
 
int Num()
{
	int e;
	scanf(" %d", &e);
	return e;
}
char Op()
{
	char w;
	scanf(" %c", &w);
	return w;
}

