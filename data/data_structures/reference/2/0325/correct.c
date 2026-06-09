#include <stdio.h>
int rnum();
char fff();
int ys(int a,int b,char ysf);

int main()
{
	int a[2];				
	char b[1];				
	 
	int num;				
	char op;				
	 
	a[0] = rnum();
	b[0] = fff();
	if (b[0] != '=')
		a[1] = rnum();
	while (b[0] != '=')
	{
		if (b[0] == '*' || b[0] == '/')	
		{
			a[0] = ys(a[0], a[1], b[0]);
			b[0] = fff();
			if (b[0] != '=')
			a[1] = rnum();
		}
		else 
		{
			op = fff();
			if (op == '+' || op == '-' || op == '=')
			{
	    		a[0] = ys(a[0], a[1], b[0]);
				b[0] = op;
					if (op != '=')
						a[1] = rnum();
				}
				else if (op != '=')	
				{
					num = rnum();
					a[1] = ys(a[1], num, op);
				}
				else	
					b[0] = op;
			}
	 
		}
		
		printf("%d\n", a[0]);
	 
		return 0;
	}
	

int ys(int a,int b,char ysf)
{
	int res;
	if(ysf == '+')
		res=a+b;
	else if(ysf == '-')
		res=a-b;
	else if(ysf == '*')
		res=a*b;
	else if(ysf == '/'&&b!=0)
		res=a/b;
	return res;
}
int rnum()
{
	int num;
	scanf(" %d",&num);
	return num;
}
char fff()
{
	char fff;
	scanf(" %c",&fff);
	return fff;
}

