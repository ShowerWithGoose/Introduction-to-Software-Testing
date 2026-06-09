#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
int main()
{
	char s[200];
	scanf("%s",s);
	int i=0,l=0;
	l=strlen(s);
	while(i<=l)
	{
		if(s[i]!='-')
		printf("%c",s[i]);
		else{
			if(islower(s[i-1])&&islower(s[i+1])&&s[i-1]<s[i+1])
				{
				for(int k=1;k<s[i+1]-s[i-1];k++)
				printf("%c",s[i-1]+k);
				}
				else if(isupper(s[i-1])&&isupper(s[i+1])&&s[i-1]<s[i+1])
				{
				for(int k=1;k<s[i+1]-s[i-1];k++)
				printf("%c",s[i-1]+k);
				}
				else if(isdigit(s[i-1])&&isdigit(s[i+1])&&s[i-1]<s[i+1])
				{
				for(int k=1;k<s[i+1]-s[i-1];k++)
				printf("%c",s[i-1]+k);
				}
				else printf("%c",s[i]);
		}
		i++;
	}
}




