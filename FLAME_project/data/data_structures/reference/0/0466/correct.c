#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main()
{
	int i,j,k;
	char s[1000000];
	gets(s);
	int l = strlen(s);
	for(i = 0; i < l; i++)
	{
		if(s[i] == '-' && i > 0 && i != l-1)
		{
			char a = s[i-1], b = s[i+1];
			if((islower(a)&&islower(b)||(isupper(a)&&isupper(b))||(isdigit(a)&&isdigit(b))))
			{
				for(char j = a+1; j < b; j++)
					printf("%c", j);
				continue;
			}
		} 
		printf("%c", s[i]);
	}
	
	

	return 0;
} 




