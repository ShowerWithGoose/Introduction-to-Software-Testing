#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char a[1100];
	gets(a);
	int dot;
	int length=strlen(a);
	char *behind;
	int e;
	int i,j;

	for(dot=0;a[dot]!='.';dot++)
		;
	behind=a+dot+1;
	
	if(dot==1)
	{
		if(a[0]=='0')
		{
			for(j=0,e=1;*(behind+j)=='0';j++,e++)
				;
			if(*(behind+j+1)!='\0')	
				printf("%c.%se-%d",*(behind+j),behind+j+1,e);
			else
				printf("%ce-%d",*(behind+j),e);
		}
		else
		{
			printf("%se0",a);
		}
	}
	else
	{
		printf("%c.",a[0]);
		e=0;
		for(i=1;a[i]!='.';i++,e++)
			printf("%c",a[i]);
		
		printf("%se%d",behind,e);

	}


	
	return 0;
}


