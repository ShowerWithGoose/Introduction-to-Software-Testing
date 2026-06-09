#include<stdio.h>
#include<string.h>
char s[102]={'\0'};

int main()
{
	gets(s);
	if(s[0]=='0')
	{
		int i=2,time=1;
		while(s[i]=='0')
		{
			time++;
			i++;
		}      
		
		printf("%c",s[i]);
		if(s[i+1]!='\0')
		printf(".");
		for(i+=1;s[i];i++)
		    printf("%c",s[i]);
		printf("e-%d",time);
    }
    
	else
	{
		printf("%c.",s[0]);
		int j=1,time=0;
		while(s[j]!='.')
		{
			printf("%c",s[j]);
			time++;
			j++;
		}
		for(j+=1;s[j];j++)
		    printf("%c",s[j]);
		printf("e%d",time);
	}	
	
	
	
	return 0;
}


 



