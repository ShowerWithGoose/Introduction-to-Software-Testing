# include <stdio.h>
# include <math.h>
# include <string.h>
# include<stdlib.h>
# include <ctype.h>
char expand(char s[])
{
	if(strlen(s)<=2)
	puts(s);
	int i,k;
	for(i=0;i<strlen(s);i++)
	{	
		printf("%c",s[i]);
		if((s[i+1]=='-')&&(s[i]<s[i+2]))
		{
			if('0'<=s[i]&&s[i]<='9'&&'0'<=s[i+2]&&s[i+2]<='9')
			{	for(k=1;k<s[i+2]-s[i];k++)
					printf("%c",s[i]+k);
				i=i+1;
			}	
		
			else if('a'<=s[i]&&s[i]<='z'&&'a'<=s[i+2]&&s[i+2]<='z')
			{	for(k=1;k<s[i+2]-s[i];k++)
					printf("%c",s[i]+k);
				i=i+1;
			}	
			else if('A'<=s[i]&&s[i]<='Z'&&'A'<=s[i+2]&&s[i+2]<='Z')
			{	for(k=1;k<s[i+2]-s[i];k++)
					printf("%c",s[i]+k);
				i=i+1;
			}	
		}
		
	
	}
}
int main()
{
	char s[10000];
	gets(s);
	expand(s);
	return 0;
} 

