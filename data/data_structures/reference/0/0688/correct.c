#include<stdio.h>
int main()
{
	char s[10000];
	gets(s);
	int n,p;
	for(n=0;s[n]!='\0';n++)
	{
		if(s[n]!='-')
		{
			printf("%c",s[n]);
		}
		else
		{
			if((isdigit(s[n-1])&&isdigit(s[n+1]))||(islower(s[n-1])&&islower(s[n+1]))||(isupper(s[n-1])&&isupper(s[n+1])))
			{
				for(p=1;s[n-1]+p<s[n+1];p++)
				{
					printf("%c",s[n-1]+p);
				}
			}
			else
			{
				printf("-");
			}
		}
	}
}



