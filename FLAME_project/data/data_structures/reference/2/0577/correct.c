#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int f(int a, int b, char c)
{
	int result;
	if (c == '+')
		result = a + b;
	else if (c == '-')
		result = a - b;
	else if (c == '*')
		result = a * b;
	else
		result = a / b;
	return result;
}
int main()
{
	int a,b,e;
	char c,d;
	scanf("%d",&a);
	scanf(" %c",&c);
	if(c!='='){
		scanf(" %d",&b);
	}
	while(c!='='){
		if(c=='*'||c=='/'){
		a=f(a,b,c);
		scanf(" %c",&c);
		if(c!='='){
			scanf(" %d",&b);
		}
	}
	else{
		scanf(" %c",&d);
		if(d!='/'&&d!='*'){
			a=f(a,b,c);
			c=d;
			if(c!='='){
				scanf(" %d",&b);
			}
		}
		else if(d!='='){
			scanf(" %d",&e);
			b=f(b,e,d);
		}
		else{
			c=d;
		}
	}
	}
	printf("%d",a);
 	return 0;
}


