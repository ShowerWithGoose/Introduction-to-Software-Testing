#include<stdio.h>
int main()
{
	int sum=0,a,c;
	char ch2='+',ch1,ch3;
	while(ch2!='=')
	{
		scanf("%d %c",&a,&ch1);
		while(ch1=='/'||ch1=='*')
		{
			scanf("%d %c",&c,&ch3);
			if(ch1=='/')
			{
				a=a/c;
			}
			else if(ch1=='*')
			{
				a=a*c;
			}
			ch1=ch3;
		}
		if(ch2=='-')
		{
			sum=sum-a;
		}
		else if(ch2=='+')
		{
			sum=sum+a;
		}
		ch2=ch1;
	}
    printf("%d\n",sum);
    return 0;
}



