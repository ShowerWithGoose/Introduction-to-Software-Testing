#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<memory.h>
int main()
{
	char s[1000],*p,*q,c;
	int i;
	gets(s);
	p=s;
	for(i=0;i<strlen(s)&&*p!='\0';i++)
	{
		q=p+1;
		if(*q=='-')
		{
			if((isupper(*(q+1))&&isupper(*p))||(islower(*(q+1))&&islower(*p))||(isdigit(*(q+1))&&isdigit(*p)))
			{
				printf("%c",*p);
				for(c=*p+1;c<*(q+1);c++)
				{
					printf("%c",c);
				}
				p+=2;
			}
			else
			{
				printf("%c-",*p);
				p+=2;
			}
		}
		else
		{
			printf("%c",*p);
			p++;
		}
	}
	return 0;
}


