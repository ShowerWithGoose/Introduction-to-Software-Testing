#include <stdio.h>
#include <string.h>
#define ll long long
int main ()
{
	char s[1001];
	scanf("%s",s);
	for(int i=0;i<strlen(s);i++)
	{
		if(s[i+1] != '-') printf("%c",s[i]);
		if(s[i+1] == '-')
		{
			if((s[i]<='z'&&s[i]>='a'&&s[i+2]<='z'&&s[i+2]>='a')||(s[i]<='Z'&&s[i]>='A'&&s[i+2]<='Z'&&s[i+2]>='A')||(s[i]<='9'&&s[i]>='0'&&s[i+2]<='9'&&s[i+2]>='0')&&(s[i]<s[i+2]))
				{
				for(char a = s[i] ;a < s[i+2] ;a++)
				printf("%c",a);
				i += 1;
				}
			else printf("%c",s[i]);
			}
	}
	return 0;
}



