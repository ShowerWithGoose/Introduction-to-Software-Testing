#include <stdio.h>
#include <string.h>

int js(int a, int b, char x)
{
	int n;
	if(x=='+')
	n = a + b;
	else if(x=='-')
	n = a - b;
	else if(x=='*')
	n = a * b;
	else
	n = a / b;
	return n;
}

int numread()
{
	int m;
	scanf(" %d",&m);
	return m;
}

char xx()
{
	char xxx;
	scanf(" %c",&xxx);
	return xxx;
} 

int main()
{
	int a[5];
	char b[5];
	int num;
	char op;
	a[0]=numread();
	b[0]=xx();
	if (b[0] != '=')
		a[1] = numread();
	while (b[0] != '=')
	{
		if (b[0] == '*' || b[0] == '/')	
		{	
			a[0] = js(a[0], a[1], b[0]);
			b[0]=xx();
			if (b[0] != '=')
			a[1] =numread();
		} 
		else
		{
			op = xx();
			if (op == '+' || op == '-' || op == '=')
			{
				a[0] = js(a[0], a[1], b[0]);
				b[0] = op;
				if (op != '=')
				a[1] = numread();
			}
		else if (op != '=')	
			{
				num = numread();
				a[1] = js(a[1], num, op);
			}
		else
			{
				b[0] = op;
			}
		}
	}
	printf("%d\n", a[0]);
	return 0;
}
 





 

