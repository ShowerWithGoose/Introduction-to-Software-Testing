#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char s[105];
	int rem;
	gets(s);
	int cnt=0,flag=0;
	int len,i;
	len=strlen(s);
	
	if(s[1]=='.')//小数 或者个位 
	{
		if(s[0]=='0')
		{
			for(i=2;i<len;i++)
			{
				if(s[i]!='0')
				{
					break;
				}
				
			}
			if(i==len-1)
			printf("%c",s[i]);
			else
			{
				printf("%c.",s[i]);
				for(int j=i+1;j<len;j++)
			   {
				printf("%c",s[j]);
			   }
			}

			printf("e-%d",i-1);
		}
		else
		{
		  printf("%se0",s);
		}

	}
	else
	{
		for(int i=1;i<len;i++)
		{
			if(s[i]=='.')
			{
				rem=i-1;
				flag=1;
			}
		}
		if(flag==1)
		{
			printf("%c.",s[0]);
		    for(int i=1;i<len;i++)
		   {
			if(s[i]!='.')
			{
             printf("%c",s[i]);
			}
		   }
			printf("e%d",rem);
		}
		else
		{		   
		   if(s[len-1]!='0')
		   {
		   	printf("%c.",s[0]);
		   	for(i=1;i<len;i++)
		   	{
		   		printf("%c",s[i]);
			}
			printf("e%d",len-1);
		   }
			else
			{
				for(i=len-1;i>=0;i--)
				{
					if(s[i]!='0')
					{
						break;
					}
				}
				if(i==0)
				{
					printf("%ce%d",s[0],len-1);
					
				}
				else
				{
					printf("%c.",s[0]);
					for(int j=1;j<=i;j++)
					{
						printf("%c",s[j]);
					}
					printf("e%d",len-1);
				}
			}	
		}
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
 } 

