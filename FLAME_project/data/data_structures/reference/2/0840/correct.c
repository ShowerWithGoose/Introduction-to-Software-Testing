#include<stdio.h>

int main(void)
{
	int x1,x2,x3;
	char c1,c2,c3;
	x1 = 0;
	c1 = '+';
	while(1)
	{
		scanf("%d %c",&x2,&c2);
		while(c2 == '*' || c2 == '/')
		{
			scanf("%d %c",&x3,&c3);
			x2 = c2=='*'? x2*x3:x2/x3;
			c2 = c3; 
		}
		if(c1=='+')
			x1+=x2;
        else if(c1=='-')
			x1-=x2;
		c1 = c2;
		if(c1 == '=')
		{
			printf("%d\n",x1);
			break;
		}
	}
	return 0;
}

