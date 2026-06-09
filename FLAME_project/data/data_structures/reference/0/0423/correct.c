#include<stdio.h>
#include<ctype.h>
#include<string.h>
char read[100],write[125];
char *p=read,*q;

int main()
{
	gets(read);
	while((q=strchr(p,'-'))!=NULL)
	{
		if((isupper(*(q-1)))&&(isupper(*(q+1))))
		{
			*q=0;
			printf("%s",p);
			for(char i=*(q-1)+1;i<*(q+1);i++)
			{
				printf("%c",i);
			}
		}
		else if((islower(*(q-1)))&&(islower(*(q+1))))
		{
			*q=0;
			printf("%s",p);
			for(char i=*(q-1)+1;i<*(q+1);i++)
			{
				printf("%c",i);
			}
		}
		else if((isdigit(*(q-1)))&&(isdigit(*(q+1))))
		{
			*q=0;
			printf("%s",p);
			for(char i=*(q-1)+1;i<*(q+1);i++)
			{
				printf("%c",i);
			}
		}
		else
		{
			*q=0;
			printf("%s%c",p,'-');
		}
		p=q+1;
	}
	puts(p);
	
	return 0;
}
