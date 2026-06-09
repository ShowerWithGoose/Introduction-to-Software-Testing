#include <stdio.h>
#include <string.h>
char s[1000];
void f(char s[], int i)
{
	for(int m=s[i-1];m<s[i+1];m++)
		if(m!=s[i-1]&&m!=s[i+1])
			printf("%c", m);
	return;
} 
int main()
{
	gets(s);
	char* a=s;
	int i=0,j=0,k=0;
	int len = strlen(s);
	for(i=0;i<len;i++)
	{
		if(s[i]!='-')
			printf("%c", s[i]);
		else if(s[i-1]<='9'&&s[i-1]>='0')
			{
				if(s[i+1]>s[i-1]&&s[i+1]<='9')
				{
					f(s, i);
				}
				else printf("-");
			}
		else if(s[i-1]<='Z'&&s[i-1]>='A')
			{
				if(s[i+1]>s[i-1]&&s[i+1]<='Z')
				{
					f(s, i);
				}
				else printf("-");
			}
		else if(s[i-1]<='z'&&s[i-1]>='a')
			{
				if(s[i+1]>s[i-1]&&s[i+1]<='z')
				{
					f(s, i);
				}
				else printf("-");
			}

	}
	return 0;
}

