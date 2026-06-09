#include<stdio.h>
int main()
{
	int a=0,b,c;
	char ch1='+',ch2,ch3;
	while(ch1!='=')
	{
		scanf("%d %c",&b,&ch2);
		while(ch2=='/'||ch2=='*')
		{
			scanf("%d %c",&c,&ch3);
			if(ch2=='/')
			{
				b=b/c;
			}
			else if(ch2=='*')
			{
				b=b*c;
			}
			ch2=ch3;
		}
		if(ch1=='-')
		{
			a=a-b;
		}
		else if(ch1=='+')
		{
			a=a+b;
		}
		ch1=ch2;
	}
    printf("%d\n",a);
    return 0;
}



