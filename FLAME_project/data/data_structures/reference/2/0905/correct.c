#include<stdio.h>
int ret,n1,n2;
int flag;
int sum(int,int);
int main()
{
	char s1='+';
	char s2,s3;
	while(1)
	{	flag=0;
		scanf("%d %c",&n1,&s2);
	while(s2=='*'||s2=='/')
		{
			scanf("%d %c",&n2,&s3);
			if(s2=='/')n1/=n2;
			else n1*=n2;
			s2=s3;
		}

		if(s1=='+')ret=sum(ret,n1);
		else if(s1=='-')ret-=n1;
		s1=s2;
		if(s1=='=')
		{
			printf("%d\n",ret);
			break;
		}
	}
	return 0;
}
int sum(int ret ,int n1)
{
	int sum=ret+n1;
	return sum;
}

