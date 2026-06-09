#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define ll long long
#define ull unsigned long long

int main()
{
	char s[105];
	int i,j;
	scanf("%s",s);
	int k=strlen(s);
	for(i=0;i<k;i++)
	{
		//printf("%c",s[i]);
		if(s[i]=='-')
		{
			if(s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<='z'&&s[i-1]<s[i+1])
			{
				for(j=1;s[i-1]+j-s[i+1]<0;j++)
				{
					printf("%c",s[i-1]+j);
				}i+=1;
			}
			else if(s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>='A'&&s[i+1]<='Z'&&s[i-1]<s[i+1])
			{
				for(j=1;s[i-1]+j-s[i+1]<0;j++)
				{
					printf("%c",s[i-1]+j);
				}i+=1;
			}	
			else if(s[i-1]>='0'&&s[i+1]<='9'&&s[i+1]>='0'&&s[i+1]<='9'&&s[i-1]<s[i+1])
			{
				for(j=1;s[i-1]+j-s[i+1]<0;j++)
				{
					printf("%c",s[i-1]+j);
				}	i+=1;		
			}
		}
		printf("%c",s[i]);
	}
    return 0;
}

