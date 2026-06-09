#include<stdio.h>
#include<string.h>
int func(int a, int b, char ch);	
int ReadNum();					
char ReadChar();					
int main()
{
	int a[2];				
	char b[1];				
	int num;				
	char ch;				
	a[0] = ReadNum();
	b[0] = ReadChar();
	if (b[0] != '=')
		a[1] = ReadNum();
	while (b[0] != '=')
	{
		if ( b[0] == '/'||b[0] == '*' )
		{
			a[0] = func(a[0], a[1], b[0]);
			b[0] = ReadChar();
			if (b[0] != '=')
				a[1] = ReadNum();
		}
		else 
		{
			ch = ReadChar();
			if (ch == '+' || ch == '-' || ch == '=')
			{
				a[0] = func(a[0], a[1], b[0]);
				b[0] = ch;
				if (ch != '=')
					a[1] = ReadNum();
			}
			else if (ch != '=')	
			{
				num = ReadNum();
				a[1] = func(a[1], num, ch);
			}
			else  b[0] = ch;
		}
	}
	printf("%d\n", a[0]);
	return 0;
}
 
int func(int a, int b, char ch)
{
	int r;
	if (ch == '+')  r = a + b;
	else if (ch == '-')	r= a - b;
	else if (ch == '*')  r = a * b;
	else  r = a / b;
	return r;
}
 
int ReadNum()
{
	int number;
	scanf(" %d", &number);
	return number;
}
char ReadChar()
{
	char ch;
	scanf(" %c", &ch);
	return ch;
}

