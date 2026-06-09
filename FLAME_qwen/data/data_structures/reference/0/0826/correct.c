#include<stdio.h>
#include<string.h>
int main()
{
	char s[100005];
	int i=0,j=0,l;
	gets(s);
	l=strlen(s);
	for(i=0;i<l;i++)
	{
		if(s[i]!='-')
		printf("%c",s[i]);
		if(s[i]=='-')
		{
			if((s[i-1]>='0'&&s[i+1]<='9')||(s[i-1]>='a'&&s[i+1]<='z')||(s[i-1]>='A'&&s[i+1]<='Z'))
			{
				for(j=i;j<i+(s[i+1]-s[i-1])-1;j++)
				printf("%c",s[i-1]+1+j-i);
			}
			else printf("%c",s[i]);
		}
	}
 } 

