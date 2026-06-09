#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

int main()
{
	char s[100],*p=NULL;
	scanf("%s",s);
	int i=0,j=0,flag=0;
	int len=strlen(s);
	
	p=strchr(s,'.');
	
	if(p==NULL)  //为0或者一个大整数无小数点
	{
		if(s[0]=='0')
		{
			printf("%c",s[0]);
			return 0;
		}
		
		else
		{
			printf("%c",s[0]);
			printf(".");
			for(i=1;i<len;i++)
				printf("%c",s[i]);
			printf("e%d",len-1);
			return 0;
		}
	}
	
	
	 
	else if((p-s)==1) //整数部分小于10 
		{
			if(s[0]=='0') //如果整数部分是0 
			{
				for(i=2;i<len;i++)
				{
					if(s[i]!='0')
					{             //形如0.000000002xxxx 
						flag=i;
						break; 
					}
						
				}
				if(flag==(len-1))
				{						//形如0.000002 
					printf("%c",s[flag]);
					printf("e-%d",len-2);
					return 0;
				}
				
				else//形如0.0000002234
				{
					printf("%c",s[flag]);
					printf(".");
				 	for(j=(flag+1);j<len;j++)
				 	{
				 		printf("%c",s[j]);
					}
					printf("e-%d",flag-1);	
					return 0;			
				} 
			}
			
			else//整数部分不是0 
			{
				for(i=0;i<len;i++)
					printf("%c",s[i]);
				printf("e0");
				return 0;
			}
		}	
		
		
		
	else if((p-s)>=2) //整数部分大于等于10
	{
		printf("%c.",s[0]);
		for(i=1;i<(p-s);i++)
			printf("%c",s[i]);
		for(j=(p+1-s);j<len;j++)
			printf("%c",s[j]);
		printf("e%d",p-s-1);
		return 0;
	} 
	return 0;
} 

