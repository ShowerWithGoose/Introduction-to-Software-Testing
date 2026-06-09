#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>	

int main()
{
	int a1,a2,a3;
	char s1,s2,s3;
	scanf("%d %c",&a1,&s1);
	while(s1!='=')
	{
		scanf("%d %c",&a2,&s2);
		if(s1=='*'||s1=='/')
		{
			if(s1=='*')
				a1*=a2;
			else
				a1/=a2;
			s1=s2;
			
		}
		else if((s1=='+'||s1=='-')&&(s2!='*'&&s2!='/'))
		{
			if(s1=='-')
				a2=-a2;
			a1+=a2;
			s1=s2;
		}
		else
		{
			do{
				scanf("%d %c",&a3,&s3);
				if(s2=='*')
					a2*=a3;
				else
					a2/=a3;
				s2=s3;
			}while(s2=='*'||s2=='/');
			if(s1=='-')
				a2=-a2;
			a1+=a2;
			s1=s2;			
		}
	}
	printf("%d",a1);
	return 0;
}

