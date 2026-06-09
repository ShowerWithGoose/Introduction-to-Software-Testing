#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
void expand(char a,char b)
{
	int i;
	if((b-a)==1)
	return;
	for(i=a+1;i<=b-1;i++)
	printf("%c",i);
}
int main()
{
	char s[10000];
	int i,len;
	gets(s);
	len=strlen(s);
	printf("%c",s[0]);
	for(i=1;i<len-1;i++)
	{
		if(s[i]!='-') printf("%c",s[i]);
		else
		{
		if(s[i-1]<='z'&&s[i-1]>='a'&&s[i+1]<='z'&&s[i+1]>='a')	expand(s[i-1],s[i+1]);
		else if(s[i-1]<='Z'&&s[i-1]>='A'&&s[i+1]<='Z'&&s[i+1]>='A')	expand(s[i-1],s[i+1]);
		else if(s[i-1]<='9'&&s[i-1]>='0'&&s[i+1]<='9'&&s[i+1]>='0')	expand(s[i-1],s[i+1]);
		else printf("-");
		}
	}
	printf("%c",s[len-1]);
	return 0; 
} 



