#include<stdio.h>
int main()
{
	char s[105];
	gets(s);
	int sum1,sum2;int x=0;int j=0;
	if(s[1]=='.'&&s[0]=='0')x=1;
	if(x==0)
	{
		for(;s[j]!='\0';j++)
	    {
		    if(s[j]!='.') printf("%c",s[j]);
		    else sum1=j;
		    if(j==0) printf(".");
	    }
		printf("e%d",sum1-1);
	}
	else
	{
		int sb=1;
		for(;s[j]!='\0';j++)
	    {
	    	if(sb==0)
	    	{
	    		printf("%c",s[j]);
	    	}
		    if(s[j]!='0'&&s[j]!='.')
		    {
		    	if(sb==1)
		    	{
		    		printf("%c",s[j]);
		    		if(s[j+1]!='\0') printf(".");
		    		sum2=j;
		    	    sb=0;
		    	}
		    }
	    }
	    printf("e-%d",sum2-1);
	}
	
	
	return 0;
} 

