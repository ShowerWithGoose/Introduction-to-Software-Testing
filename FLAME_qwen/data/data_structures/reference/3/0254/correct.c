#include<stdio.h>  
#include<math.h>
#include<string.h>
#include<stdlib.h>


int main()
{  char s[1000];
   int i=0,tmp=1,j;
   gets(s);
   if(s[0]=='0')
   {  i=i+2;
   while(s[i]=='0')
   	{tmp++;
   	i++;
	}
    printf("%c",s[i]);
	if(i<strlen(s)-1)
	{printf(".");
	}
	for(j=i+1;j<strlen(s);j++)
    {printf("%c",s[j]);
	}
	printf("e-%d",tmp);
	}
	else 
{int flag=0;
	for(j=0;j<strlen(s);j++)
	{if(s[j]=='.')
	flag=1;
	}
	if(flag==1)
{
	for(j=1;j<strlen(s);j++)
	{if(s[j]!='.')
	continue;
	else
	tmp=j-1;	
	}
	printf("%c.",s[0]);
	for(j=1;j<strlen(s);j++)
	{if(s[j]!='.')
	printf("%c",s[j]);
	}	
	printf("e%d",tmp);			
}
	else if(flag==0)
	{puts(s);
	 printf("e%d",strlen(s));
	}	
}  
    return 0;  
}

