#include<string.h>
#include<stdio.h>
int main()
{
	char s[1000];
	int i=0,j;
	gets(s);
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]!='-') printf("%c",s[i]);
		else if(s[i-1]<'z'+1&&s[i-1]>'a'-1&&s[i+1]<'z'+1&&s[i+1]>'a'-1)
		{
			for(j=s[i-1]+1;j<s[i+1];j++)
			printf("%c",j);
		}
		else if(s[i-1]<'Z'+1&&s[i-1]>'A'-1&&s[i+1]<'Z'+1&&s[i+1]>'A'-1)
		{
			for(j=s[i-1]+1;j<s[i+1];j++)
			printf("%c",j);
		}
		else if(s[i-1]<'9'+1&&s[i-1]>'0'-1&&s[i+1]<'9'+1&&s[i+1]>'0'-1)
		{
			for(j=s[i-1]+1;j<s[i+1];j++)
			printf("%c",j);
		}
		else printf("%c",s[i]);
	}
	return 0;
}

