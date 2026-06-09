#include<stdio.h>
#include<string.h>
char s[1000];
int a=0;
int j=0;
char y;
int k=0;
int flag=0;
int main()
{
	gets(s);
	a=strlen(s);
	for(int i=0;i<a;i++)
	{   
		if(s[i]=='.') 
		j=i;
	}
	for(int i=0;i<j;i++)
	{
		if(s[i]!='0') 
		{
		flag=1;
		
		break;
	    }	
	}
	if(flag==1) 
	{
		printf("%c",s[0]);
		printf(".");
	    for(int i=1;i<j;i++)
	    printf("%c",s[i] );
	    for(int i=j+1;i<a;i++)
	    printf("%c",s[i]);
	    printf("e"); 
	    printf("%d",j-1);
			}
	else
	{
	    for(int i=j+1;i<a;i++)
		{
			
			if(s[i]!='0')
			{
		    	y=s[i];
		    	k=i;
		     	break;
					}
			
			}	
	printf("%c",y);
	if((a-k)!=1)
	printf(".");
	for(int i=k+1;i<a;i++)
	{
		printf("%c",s[i]);
		
		}	
		printf("e-");
		printf("%d",k-j);
		
			}	
		return 0;	
	
}

