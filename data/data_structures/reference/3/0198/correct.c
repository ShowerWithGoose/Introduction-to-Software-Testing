#include<stdio.h>
int main()
{
	char s[105];
	gets(s);
	int sum1,sum2;int prime=0;int t=0;
	if(s[1]=='.'&&s[0]=='0')prime=1;
	if(prime==0)
	{
		for(;s[t]!='\0';t++)
	    {
		    if(s[t]!='.') printf("%c",s[t]);
		    else sum1=t;
		    if(t==0) printf(".");
	    }
		printf("e%d",sum1-1);
	}
	else
	{
		int sb=1;
		for(;s[t]!='\0';t++)
	    {
	    	if(sb==0)
	    	{
	    		printf("%c",s[t]);
	    	}
		    if(s[t]!='0'&&s[t]!='.')
		    {
		    	if(sb==1)
		    	{
		    		printf("%c",s[t]);
		    		if(s[t+1]!='\0') printf(".");
		    		sum2=t;
		    	    sb=0;
		    	}
		    }
	    }
	    printf("e-%d",sum2-1);
	}
	
	
	return 0;
} 

