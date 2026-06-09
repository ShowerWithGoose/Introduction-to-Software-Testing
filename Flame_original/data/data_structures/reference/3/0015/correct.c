#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
int main()
{
char s[100];
int i,flag=0,p,po;
 gets(s); 
 for(i=0;i<strlen(s)-1;i++)
 {
 	if(s[i]=='.')
 	{
 		p=i+1;
 		flag=1;
	}
 }

	if(flag==0)
	{
		puts(s); 
		return 0;
	}
if(p<=2)
{
    if(s[0]=='0')
 	{
 		 for(i=2;i<strlen(s);i++)
 		{
 		 	if(s[i]!='0')
 		 	{
 		 		po=i;
 		 		break;
			}
		}
     if(po==strlen(s)-1)
    {
      printf("%c",s[po]);
      for(i=po+1;i<strlen(s);i++)
      {
      	printf("%c",s[i]);
	  }
	  printf("e-%d",po-1);
	}
    else
    {
    	printf("%c.",s[po]);
    	for(i=po+1;i<strlen(s);i++)
    	{
    		if(s[i]!='.')
    		{
    		printf("%c",s[i]);
    	}
		}
	  	printf("e-%d",po-1);
	}
	}
	else
	{
      for(i=0;i<strlen(s);i++)
    	{
    		printf("%c",s[i]);
		}    
	  printf("e0");
	}
}
	else 
	{
		for(i=0;i<strlen(s);i++)
 		{
 		 	if(s[i]=='.')
 		 	{
 		 		po=i;
 		 		break;
			}
		}
		printf("%c.",s[0]);
	for(i=1;i<strlen(s);i++)
    	{
    		if(s[i]!='.')
    		{
    		printf("%c",s[i]);
    	}
		}
		 
	  	printf("e%d",po-1);
	}
	
return 0;
}



