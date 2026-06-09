#include <stdio.h>
#include <string.h>
int main()
{
	char m,n,s[500];
	gets(s);
	int i;
	if(s[0]=='-')
	{
		printf("-");
	}
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]!='-')
		{
			printf("%c",s[i]);
		}
		if(s[i+1]=='-')
		{
			int j;
			if(((s[i]>='a'&&s[i+2]<='z'&&s[i]<s[i+2])||(s[i]>='A')&&(s[i+2]<='Z')&&(s[i]<s[i+2])||((s[i]>='0')&&s[i+2]<='9')&&(s[i]<s[i+2])))
		    {
				for(j=1;j<(s[i+2]-s[i]);j++)
			{
				printf("%c",s[i]+j);
			}
		    }
		    else printf("-");
		}
		
	}
	
} 


 

