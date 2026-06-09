#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h> 
char j=0,putout[100];
void add(char a, char b)
{
	int i;
	for(i=1;i<b-a;i++)
	{		
		putout[j]=a+i;
		j++;		
	}
}
int main ()
{
	char s[100],i=0;
	scanf("%s",s);
	while(s[i]!='\0')
	{
		if(s[i]!='-')
		{
			putout[j]=s[i];
			j++;
			i++;
			continue;
		}
		if(s[i-1]>='0'&&s[i-1]<='9')
		{
			if(s[i+1]>='0'&&s[i+1]<='9'&&s[i+1]>s[i-1])
			{
				add(s[i-1],s[i+1]);
				i++;
				continue;
			}
						putout[j]=s[i];
			i++;
			j++;
			continue;
		}
		if(s[i-1]>='a'&&s[i-1]<='z')
		{
			if(s[i+1]>='a'&&s[i+1]<='z'&&s[i+1]>s[i-1])
			{
				add(s[i-1],s[i+1]);
				i++;
				continue;
			}
						putout[j]=s[i];
			i++;
			j++;
			continue;
		}
		if(s[i-1]>='A'&&s[i-1]<='Z')
		{
			if(s[i+1]>='A'&&s[i+1]<='Z'&&s[i+1]>s[i-1])
			{
				add(s[i-1],s[i+1]);
				i++;
				continue;
			}
						putout[j]=s[i];
			i++;
			j++;
			continue;
		}		
	}
	printf("%s",putout);
}

