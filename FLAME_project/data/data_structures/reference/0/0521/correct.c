#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int jud(char a,char b)
{
	if(a<b&&a<='z'&&a>='a'&&b<='z'&&b>='a')
	return 1;
	else if(a<b&&a<='Z'&&a>='A'&&b<='Z'&&b>='A')
	return 1;	
	else if(a<b&&a<='9'&&a>='0'&&b<='9'&&b>='0')
	return 1;
	else 
	return 0;
}
void link(char a,char b)
{
	while(a<b-1)
	printf("%c",++a);
}

int main(int argc, char *argv[]) {
	char sen[200],a,b;
	gets(sen);
	int i=0,len=strlen(sen),ju;
	while(i<len)
	{
		if(sen[i]!='-')
		printf("%c",sen[i]);
		else 
		{
			a=sen[i-1];
			b=sen[i+1];
			ju=jud(a,b);
			if(ju==1)
			link(a,b);
			else
			{
				printf("-");
			}
		}
		
		i++;
	}
	
	return 0;
}

