#include<stdio.h>
int a,b,c;
char s1,s2,s3;

int main()
	{a=0;
	s1='+';
	while(s1!='=')
	{	scanf("%d %c",&b,&s2);
		
		while(s2=='*'||s2=='/')
		{ scanf("%d %c",&c,&s3);
			if(s2=='*')
			{b=b*c;s2=s3;
			}
			else if(s2=='/')
			{b=b/c;s2=s3;
			}
			
		}
		if(s1=='+')
		{a=a+b;s1=s2;
		}
		else if(s1=='-')
		{a=a-b;s1=s2;
		}
		
	}
	printf("%d",a);
	
	
	}



