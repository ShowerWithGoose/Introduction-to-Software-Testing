#include <stdio.h>
#include <math.h>
#include <string.h> 

int main()
{
	int a,sum=0,b=0;
	char fh1='+',fh2,fh3;
	while(fh1!='=')
	{
		scanf("%d%c",&a,&fh2);
		while(fh2==' ')
		{
			scanf("%c",&fh2);
		}
		while(fh2=='*' || fh2=='/')
		{
			scanf("%d %c",&b,&fh3);
			if(fh2=='*') a*=b;
			else a/=b;
			fh2=fh3;
		}
		if(fh1=='+') sum+=a;
		else if(fh1=='-') sum-=a;
		fh1=fh2;
	}
	printf("%d",sum);
	return 0;
} 



