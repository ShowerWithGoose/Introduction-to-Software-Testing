#include<stdio.h>
#include<string.h>

int main()
{
	char s[105]={};
	int i,j,k=0;
	gets(s);
	if(s[0]=='0')
	{
		for(i=2;i<strlen(s);i++)
		{
			if(s[i]=='0') k++;
			else
			{
				for(j=i;j<strlen(s);j++)
				{
					if(i==strlen(s)-1)
					{
						printf("%ce-%d",s[j],k+1);
						return 0;
					}
					else if(i==j) printf("%c.",s[j++]);
					printf("%c",s[j]);
				}
				printf("e-%d",k+1);
				return 0;
			}
		}
	}
//	if(s[1]=='.') printf("%se0",s);
	for(i=1;i<strlen(s);i++)
	{
		
		if(s[i]=='.')
		{
			printf("%c.",s[0]);
			for(j=1;j<strlen(s);j++)
			{
				if(j==i) j++;
				printf("%c",s[j]);
			}
			printf("e%d",i-1);
		}
	}
	
	
	
	
	
	
	
	
	
}

