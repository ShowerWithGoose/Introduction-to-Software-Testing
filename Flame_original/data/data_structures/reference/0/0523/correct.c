#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>


char s[10000];
int main()
{
	int i,len,j,t;
	
	gets(s);
	len = strlen(s);
	for(i=0;i<len;i++)
	{
		if(s[i+1]!='-')
		{
			printf("%c",s[i]);
		}
		else if(isupper(s[i])&&isupper(s[i+2])&&(t=s[i+2]-s[i])>0)
		{
			for(j=0;j<=(t-1);j++)
			{
				printf("%c",s[i]+j);
			}
			i+=1;
		}
		else if(islower(s[i])&&islower(s[i+2])&&(t=s[i+2]-s[i])>0)
		{
			for(j=0;j<=(t-1);j++)
			{
				printf("%c",s[i]+j);
			}
			i+=1;
		}
		else if(isdigit(s[i])&&isdigit(s[i+2])&&(t=s[i+2]-s[i])>0)
		{
			for(j=0;j<=(t-1);j++)
			{
				printf("%c",s[i]+j);
				
			}
			i+=1;
		}
		else
		{
			printf("%c",s[i]);
		}
	}
	return 0;
	
}

