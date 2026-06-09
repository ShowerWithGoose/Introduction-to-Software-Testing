#include<stdio.h> 
#include<string.h> 
#include<math.h> 
#include<stdlib.h> 
#include<malloc.h>
#define N 100000+9
typedef long long ll;

char s[N];

int main()
{
	int i,j;
	int len;

	scanf("%s",s); 
	len=strlen(s);
	for(i=0;i<=len-1;i++)
	{
		if(s[i]=='-')continue;
		if(s[i+1]!='-'||i==len-1)
		{
			printf("%c",s[i]);
		}
		else if(s[i+1]=='-')
		{
			if(s[i+2]>='0'&&s[i+2]<='9')
			{
				if(s[i]>='0'&&s[i]<='9'&&s[i]<s[i+2])
				{
					for(j=s[i]-'0';j<s[i+2]-'0';j++)
					{
						printf("%d",j);
					}
				}
				else
				{
					printf("%c%c",s[i],s[i+1]);
				}
			}
			else if(s[i+2]>='a'&&s[i+2]<='z')
			{
				if(s[i]>='a'&&s[i]<='z'&&s[i]<s[i+2])
				{
					for(j=s[i];j<s[i+2];j++)
					{
						printf("%c",j);
					}
				}
				else
				{
					printf("%c%c",s[i],s[i+1]);
				}
			}
			else if(s[i+2]>='A'&&s[i+2]<='Z')
			{
				if(s[i]>='A'&&s[i]<='Z'&&s[i]<s[i+2])
				{
					for(j=s[i];j<s[i+2];j++)
					{
						printf("%c",j);
					}
				}
				else
				{
					printf("%c%c",s[i],s[i+1]);
				}
			}
			
		}
	}
}



