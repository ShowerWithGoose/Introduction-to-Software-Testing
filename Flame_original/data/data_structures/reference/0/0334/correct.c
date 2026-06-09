#include <stdio.h>
#include <string.h>
int main()
{
	int len,i,j=0,k=0;
	char s[1000],a,b;
	gets(s) ;
	len=strlen(s) ;
	for(i=0;i<len;i++)
	{
		printf("%c",s[i]) ;
		if(s[i+1]=='-' && s[i+2]>s[i])
		{
		if(s[i+2]<='z' && s[i]>='a')
		{
		for(a=s[i]+1;a<s[i+2];a++)
		printf("%c",a) ;
		i+=1;
		}
		if(s[i+2]<='9' && s[i]>='0')
		{
		for(a=s[i]+1;a<s[i+2];a++)
		printf("%c",a) ;
		i+=1;
		}
		if(s[i+2]<='Z' && s[i]>='A')
		{
		for(a=s[i]+1;a<s[i+2];a++)
		printf("%c",a) ;
		i+=1;
		}
		}
	}
	return 0;
}

