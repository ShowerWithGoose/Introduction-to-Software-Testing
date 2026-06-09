#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int main()
{
	char zf[105],*p;
	p=zf;
	int num;
	scanf("%s",zf);
	while(*p!='.')
	{
		p++;
	}
	if(p-zf==1)
	{
		if(zf[0]!='0')
		printf("%se0",zf);
		else {
			char *m=p+1;
			while(*m=='0')
			{
				m++;
			}
			int num=m-p;
			putchar(*m);
			m++;
			if(*m!='\0')
			putchar('.');
			while(*m!='\0')
			putchar(*m++);
			printf("e-%d",num);
		}
	}
	else {
		num=p-zf-1;
		putchar(zf[0]);
		putchar('.');
		char *pp=zf+1;
		while(p-pp>0)
		{
			putchar(*pp);
			pp++;
		}
		p++;
		
		while(*p!='\0')
		{
			putchar(*p);
			p++;
		}
		printf("e%d",num);
	}
	
	
	return 0;
}

