#include<stdio.h>
int main()
{
	int a,b,c;
	char m,n,t;
	a=0;
	m='+';
	while(m!='=')
	{
		scanf("%d %c",&b,&n);
		while(n=='*'||n=='/')
		{
			scanf("%d %c",&c,&t);
			if(n=='*')
			{
				b=b*c;
			}
			else
			{
				b=b/c;
			}
			n=t;
		}
		if(m=='+')
		{
			a=a+b;
		}
		else if(m=='-')
		{
			a=a-b;
		}
		m=n;
	}
	printf("%d",a);
	return 0;
}

