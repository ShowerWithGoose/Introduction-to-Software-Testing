#include<stdio.h>
#include<string.h>
int main()
{
	int i=0,j=0,k=0;
	char str[1000];
	scanf("%s",str);
	for(i=0;i<=strlen(str);i++)
	{
		if(str[i]=='-')
		{
			k=str[i-1],j=str[i+1];
			if(k>='0'&j<='9')
			{
				for(k=str[i-1]+1;k<=j-1;k++)
				printf("%c",k);
			}
			else if(k>='a'&j<='z')
			{
				for(k=str[i-1]+1;k<=j-1;k++)
				printf("%c",k);
			}
			else if(k>='A'&j<='Z')
			{
				for(k=str[i-1]+1;k<=j-1;k++)
				printf("%c",k);
			}
			else
			printf("%c",str[i]);
		}
		else
		printf("%c",str[i]);	
	}
	return 0;
 } 

