#include<stdio.h>
int main()
{
	int a,b,c;
	char x,y,z;
	a=0;
	x='+';
	while(x!='=')
	{
		scanf("%d %c",&b,&y);
		while(y=='*'||y=='/')
		{
			scanf("%d %c",&c,&z);
			if(y=='*')
				b*=c;
			if(y=='/')
				b/=c;
			y=z;
		}
		if(x=='+')
			a+=b;
		if(x=='-')
			a-=b;
		x=y;
	}
	printf("%d",a);
	return 0;
}

