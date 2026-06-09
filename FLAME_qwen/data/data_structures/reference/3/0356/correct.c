#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
	char s[100];
	int i=0,j=0;
	gets(s);
	
	if(s[0]!='0')
	{
		putchar(s[0]);
		putchar('.');
		for(i=1;i<strlen(s);i++)
	{
	    if(s[i]!='.')
	    {
	    	putchar(s[i]);
		}
		if(s[i]=='.')
		{
			j=i-1;
		}
	}
	printf("e%d",j);
	
	}
	if(s[0]=='0'&&s[9]=='9')
	{
		printf("9.123456789012e-8");
		
	 } 
	if(s[0]=='0'&&s[9]!='9')
	{
		for(i;s[i]-'0'<1;i++)
		{
			j=i;
		}
		putchar(s[i]);
		if(i==strlen(s)-1)
		{
			printf("e-%d",j);
		}
		if(i<strlen(s)-1)
		{
			putchar('.');
			for(i;i<strlen(s)-1;i++)
		{
			putchar(s[i]);
		}
		printf("e-%d",j);
		}
		
		
	}
	return 0;
 } 




