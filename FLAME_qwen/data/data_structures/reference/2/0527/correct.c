#include<stdio.h>
#include<string.h>
int main()
{
	char c;
	int sum=0,a,b;
	scanf("%d",&a);
	while((c=getchar())!='=')
	{
		if(c==' ') continue;
		if(c=='+'||c=='-')
		{
			sum+=a;
			scanf("%d",&a);
			if(c=='-')
			a=-a;//这里不要用sum-=a,因为吧a换了符号之后在乘除法能用的到，，，， 
		}
		if(c=='*'||c=='/')
		{
			scanf("%d",&b);
			if(c=='*')
			{
				a=b*a;
			}
			if(c=='/')
			{
				a=a/b;
			}
		}
	}
	sum+=a;
	printf("%d",sum);
	return 0;
}



