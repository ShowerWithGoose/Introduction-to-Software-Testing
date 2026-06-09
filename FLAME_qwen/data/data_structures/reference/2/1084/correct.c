#include <stdio.h>

int main()
{
	int a=0,b,c;
	char f1='+',f2,f3;
	while (f1!='=')
	{
		scanf("%d %c",&b,&f2);
		while (f2=='*'||f2=='/')
		{
			if (f2=='*')
			{
			    scanf("%d %c",&c,&f3);
		    	b*=c;f2=f3;
			}
		    else
		    {
		    	scanf("%d %c",&c,&f3);
		    	b/=c;f2=f3;
		    }
		}
		if (f1=='+')
		{
			a+=b;f1=f2;
		}
		else if (f1=='-')
		{
			a-=b;f1=f2;
		}
	}
	printf("%d",a);
	return 0;
}
