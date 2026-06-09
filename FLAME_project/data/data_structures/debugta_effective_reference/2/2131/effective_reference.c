#include <stdio.h>
int rnum();
char fff();
int ys(int b,int a,char ysf);

int main()
{
	int b[2];				
	char a[1];				
	 
	int num;				
	char fh2;				
	 
	b[0] = rnum();
	a[0] = fff();
	if (a[0] != '=')
		b[1] = rnum();
	while (a[0] != '=')
	{
		if (a[0] == '*' || a[0] == '/')	
		{
			b[0] = ys(b[0], b[1], a[0]);
			a[0] = fff();
			if (a[0] != '=')
			b[1] = rnum();
		}
		else 
		{
			fh2 = fff();
			if (fh2 == '+' || fh2 == '-' || fh2 == '=')
			{
	    		b[0] = ys(b[0], b[1], a[0]);
				a[0] = fh2;
					if (fh2 != '=')
						b[1] = rnum();
				}
				else if (fh2 != '=')	
				{
					num = rnum();
					b[1] = ys(b[1], num, fh2);
				}
				else	
					a[0] = fh2;
			}
	 
		}
		
		printf("%d\n", b[0]);
	 
		return 0;
	}
	

int ys(int b,int a,char ysf)
{
	int res;
	if(ysf == '+')
		res=b+a;
	else if(ysf == '-')
		res=b-a;
	else if(ysf == '*')
		res=b*a;
	else if(ysf == '/'&&a!=0)
		res=b/a;
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

