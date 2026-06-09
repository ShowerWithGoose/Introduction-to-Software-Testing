#include <stdio.h>
#include <string.h> 
int main()
{
	char s[10000];
	gets(s);
	int l=strlen(s),i=0,j;
	for(i=0;i<l;i++)
	{
		if((s[i]<='Z'&&s[i]>='A')&&(s[i+1]=='-')&&(s[i+2]<='Z'&&s[i+2]>='A')&&(s[i+2]>=s[i]))
		{	
			for(j=s[i]-'A';j<s[i+2]-'A';j++)
				printf("%c",j+'A');
			i+=1;continue;
		}
		if((s[i]<='z'&&s[i]>='a')&&(s[i+1]=='-')&&(s[i+2]<='z'&&s[i+2]>='a')&&(s[i+2]>=s[i]))
		{	
			for(j=s[i]-'a';j<s[i+2]-'a';j++)
				printf("%c",j+'a');		
			i+=1;continue;
		}
		if((s[i]<='9'&&s[i]>='0')&&(s[i+1]=='-')&&(s[i+2]>='0'&&s[i+2]<='9')&&(s[i+2]>=s[i]))
		{	
			for(j=s[i]-'0';j<s[i+2]-'0';j++)
				printf("%c",j+'0');	
			i+=1;continue;
		}
		printf("%c",s[i]);
	}
	return 0;
}



