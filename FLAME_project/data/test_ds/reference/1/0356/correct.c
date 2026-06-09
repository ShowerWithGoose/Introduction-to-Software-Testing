#include<stdio.h>
#include<string.h>
int main()
{
	char s[10000];
	gets(s);
	int i=0,j=0;
	
	for(i=0;i<=strlen(s);i++)
	{
		
	if((s[i]=='-'&&s[i-1]>=65&&s[i+1]<=90&&s[i+1]-s[i-1]<=25)||(s[i]=='-'&&s[i+1]<=57&&s[i-1]>=48&&s[i+1]-s[i-1]<=9)||(s[i]=='-'&&s[i+1]>=97&&s[i+1]<=122&&s[i+1]-s[i-1]<=25))	
	{
	       for(j=1;j<s[i+1]-s[i-1];j++)
	       {
	       	putchar(s[i-1]+j);
		   }
	}
	else
	{
		putchar(s[i]);
	 } 
	}
	
	return 0;
 } 



