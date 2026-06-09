#include <stdio.h>
int jisuan(int a, int b, char c);
int main()
{

	int a, b, c;
	char d, e, f;
	scanf(" %d", &a);
	scanf(" %c", &d);
	if (d != '=')
	{
		scanf(" %d", &b);
	}
	while (d != '=')
	{
		if (d == '*' || d == '/')
		{
			a = jisuan(a, b, d);
			scanf(" %c", &d);
			if (d != '=')
			{
				scanf(" %d", &b);
			}
		}
		else
		{
			scanf(" %c", &e);
			if (e == '+' || e == '-'||e=='=')
			{
				a = jisuan(a, b, d);
				d = e;
				if (d != '=')
				{
					scanf(" %d", &b);
				}
			}
			else
			{
				scanf(" %d", &c);
				b = jisuan(b, c, e);

			}
		}
	}
	printf("%d", a);

}
int jisuan(int a, int b, char c)
{
	if (c == '+')
	{
		a = a + b;
	}
	if (c == '*')
	{
		a = a * b;
	}
	if (c == '/')
	{
		a = a / b;
	}
	if (c == '-')
	{
		a = a - b;
	}
	return a;
}


