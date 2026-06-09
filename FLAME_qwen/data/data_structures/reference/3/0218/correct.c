#include<stdio.h>
#include<string.h>
char a[105];int b[105];
int main()
{
	gets(a);
	int i=0,len,ex;
	len=strlen(a);
		if(a[0]=='0')
		{
			for(i=2;a[i]=='0';i++)
			{
				
			}
			ex=i-1;
			printf("%c",a[i]);
			if(i==len-1)
			printf("e-%d",ex);
			else
			{
				printf(".");i++;
				for(;i<len;i++)
				{
					printf("%c",a[i]);
				}
				printf("e-%d",ex);
			}
		}
		else
		{
			
			
				printf("%c.",a[0]);
				for(i=1;a[i]!='.';i++)
				{
					printf("%c",a[i]);
				}
				ex=i-1;i++;
				for(;i<len;i++)
				{
					printf("%c",a[i]);
				}
				printf("e%d",ex);
			
		}
	
	return 0;
}

