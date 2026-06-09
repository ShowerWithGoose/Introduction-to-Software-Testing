#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main()
{
	int s1=0,s2,s3;
	char z1,z2,z3;
	z1='+';
	while(z1!='=')
	{
		scanf("%d%c",&s2,&z2);
		while(z2==' ')
		{
			scanf("%c",&z2);
		}
		for(;z2=='*'||z2=='/';z2=z3)
		{
			scanf("%d%c",&s3,&z3);
			while(z3==' ')
		{
			scanf("%c",&z3);
		}
			if(z2=='*')
			s2=s2*s3;
			else if(z2=='/')
			s2=s2/s3;
		}
		if(z1=='+')
		s1=s1+s2;
		else if(z1=='-')
		s1=s1-s2;
		z1=z2;
	}
	printf("%d\n",s1);
	return 0;
}

