#include<stdio.h>
#include<string.h>
char str[103];
int main()
{
	int i;
	char *p,*q;
	gets(str);
	p=strchr(str,'.');
	if(str[0]!='0')
	{   
		printf("%c.",str[0]);
		q=str+1;
		while(*q!='\0')
		{
		  if(*q!='.')	printf("%c",*q);
		  q++;
		}
		
		printf("e%d",p-str-1);
	}

	else
    {   p++;
    	while(*p=='0')
    	p++;
    	if(*(p+1)=='\0')
    		printf("%ce-%d",*p,p-str-1);
    	else printf("%c.%se-%d",*p,p+1,p-str-1);
	}
}

