#include <stdio.h>
#include <string.h>
int main()
{
	char s[105];
	int i,flag=0,k,l;
	scanf("%s",&s);
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]=='.') flag=1,k=i;
	}
	if(flag==0) 
	{
		if(strlen(s)==1) printf("%ce0",s[0]);
		else
		{
			printf("%c.",s[0]);
			for(i=1;i<strlen(s);i++) printf("%c",s[i]);
			printf("e%d",strlen(s)-1);
		}
	}
	if(flag==1)
	{
		if(s[0]=='0') 
		{
			for(i=k+1;i<strlen(s);i++)
			{
				if(s[i]!='0')
				{
					l=i;
					break;
				}
			}
			printf("%c",s[l]);
			if(l!=strlen(s)-1) printf(".");
			for(i=l+1;i<strlen(s);i++) printf("%c",s[i]); 
			printf("e-%d",l-k);
		}
		else
		{
			printf("%c.",s[0]);
			for(i=1;i<strlen(s);i++)
			{
				if(s[i]!='.') printf("%c",s[i]);
			}
			printf("e%d",k-1);
		}
	}
	return 0;
} 

