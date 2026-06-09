#include <stdio.h>
#include <string.h>
int main()
{
	char s[2000];
	gets(s);
	for(int i=0;i<strlen(s);i++)
	{
		if(s[i]!='-') printf("%c",s[i]);
		else 
		{
			if(s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>='0'&&s[i+1]<='9')
			{
				for(int j=s[i-1]-'0'+1;j<s[i+1]-'0';j++) printf("%c",j+'0');
			}
		   else	if(s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<='z')
			{
				for(int j=s[i-1]-'a'+1;j<s[i+1]-'a';j++) printf("%c",j+'a');
			}
			else if(s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>='A'&&s[i+1]<='Z')
			{
				for(int j=s[i-1]-'A'+1;j<s[i+1]-'A';j++) printf("%c",j+'A');
			}
			else printf("-");
		}
	}
	return 0;
}



