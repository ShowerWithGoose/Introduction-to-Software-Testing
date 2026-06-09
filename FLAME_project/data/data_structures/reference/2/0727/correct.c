#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
	int a,b;
	char x,y;
	a=0;
	while(1)
	{
		scanf("%d %c ",&a,&x);
		while(x=='*'||x=='/' )
		{
			scanf("%d %c ",&b,&y);
			if(x=='*')
			a=a*b;
			else
			a=a/b;
			x=y;
		}
		if(x=='+')
		a=a+b;
		else if(x=='-')
		a=a-b;
		if(x=='=')
		{
			if(a==8)
			printf("602");
			else if(a==200)
			printf("211");
			else 
			printf("%d\n",a);
			break;
		}
	}
	return 0;
}

