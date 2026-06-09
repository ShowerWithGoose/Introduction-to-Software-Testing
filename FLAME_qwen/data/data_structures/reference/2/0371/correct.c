#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int Calculate(int a, int b, char c)
{
	int re;
	if(c == '+')
		re = a + b;
	if(c == '-')
		re = a - b;
	if(c == '/')
		re = a / b;
	if(c == '*')
		re = a * b;
	return re;
}

int Read_number()
{
	int a;
	scanf(" %d", &a);
	return a;
}

char Read_fu()
{
	int c;
	scanf(" %c", &c);
	return c;
}

int main()
{
	int a1=0, a2=0, a3=0;
	char c1, c2;
	//begin_reading
	a1 = Read_number();
	c1 = Read_fu();
	
	if(c1 != '=')
		a2 = Read_number();
	else
	{
		printf("%d", a1);
		return 0;
	}
	
	while(c1 != '=')
	{
		// '*'and '/' can calculate firstly
		if(c1 == '*' || c1 == '/')
		{
			a1 = Calculate(a1, a2, c1);
			c1 = Read_fu();
			if(c1 != '=')
				a2 = Read_number();
		}
		else
		{
			//read next fu_hao
			c2 = Read_fu();
			if(c2 == '+' || c2 == '-' || c2 == '=')
			{
				a1 = Calculate(a1, a2, c1);
				c1 = c2;
				if(c2 != '=')
					a2 = Read_number();
			}
			//calculate next first
			else if(c2 != '=')
			{
				a3 = Read_number();
				a2 = Calculate(a2, a3, c2);
			}
			else
				c1 = c2;
		}
	}
	printf("%d", a1);
	
	return 0;
}


