#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>


int main()
{
	char zf[10000],*p;
	int length;
	scanf("%s",zf);
	p=zf;
	length=strlen(zf);
	while(p-zf<=length)
	{
		if(*(p+1)!='-')
		{
			putchar(*p);
			p++;
		}
		else if(*p>='a'&&*p<='z'&&*(p+2)>='a'&&*(p+2)<='z'&&*p<*(p+2))
		{
			char num=*p;
			while(num!=*(p+2))
			{
				putchar(num++);
			}
			p+=2;
		}
		else if(*p>='A'&&*p<='Z'&&*(p+2)>='A'&&*(p+2)<='Z'&&*p<*(p+2))
		{
			char num=*p;
			while(num!=*(p+2))
			{
				putchar(num++);
			}
			p+=2;
		}
		else if(*p>='0'&&*p<='9'&&*(p+2)>='0'&&*(p+2)<='9'&&*p<*(p+2))
		{
			char num=*p;
			while(num!=*(p+2))
			{
				putchar(num++);
			}
			p+=2;
		}
		else {
			putchar(*p);
			p++;
		}
			
		
	}
	
	
	
	return 0;
}

