#include <stdio.h>
#include <string.h>
char s[105];
int i,j,len,k;

int main()
{
	gets(s);
	len = strlen(s);
	for(i=0;i<len;i++)
	{
		if(s[i]=='.')
		{
		k=i;
		break;
		}
	}
	
	if(s[0]=='0')
		{
			for(i=k+1;i<len;i++)
			{
				if(s[i]!='0')
				break;
			}
			if(i==len-1)
			{
			for(j=i;j<len;j++)
				printf("%c", s[j]);
			printf("e-%d", i-k);
			}
			else
			{
				printf("%c.", s[i]);
				for(j=i+1;j<len;j++)
					printf("%c", s[j]);
				printf("e-%d", i-k);
			}
		}
	
	else
		{
			printf("%c.", s[0]);
			for(i=1;i<len;i++)
			{
				if(i!=k)
					printf("%c", s[i]);
			}
			printf("e%d", k-1);
		} 
	
	return 0;
	
} 

