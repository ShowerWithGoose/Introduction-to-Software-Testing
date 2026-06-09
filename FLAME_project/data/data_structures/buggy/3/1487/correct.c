#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>


int main()
{
	char a[500];
	int i=0, j=0, len;
	
	gets(a);
	len = strlen(a);
	
	if(a[i] == '0')//零点几 
	{
		i=2;
		
		while(a[i] == '0')
		{
			i++;
		}
		j=i-2;
		
		printf("%c", a[i]);
		
		i++;
		
		if(i!=len)
		{
			printf(".");
		}
		
		while(i<len)
		{
			printf("%c", a[i]);	
			i++;
		}
		
		printf("e-%d", j+1);
	}
	else if(a[i] != '0')//几点几 
	{
		printf("%c.", a[i]);
		i=1;
		 
		while(a[i] != '.')
		{
			printf("%c", a[i]);
			i++;
		}
		j=i-1;
		
		i++;
		
		while(i<len)
		{
			printf("%c", a[i]);	
			i++;
		}
		printf("e%d", j);
	}
	return 0;
}


