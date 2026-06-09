#include<stdio.h>
#include<string.h>
#include<ctype.h>//环境与系统一致 
#define MAXN 10005
char s[MAXN];

int main()
{
	int len, i, j, flag;
	gets(s);
	len = strlen(s);
	//puts(s);
	for(i=0; i<=len-1; i++)
	{
		flag = 1;
		if(s[i+1]=='-')
		{
			if(s[i]>='0'&&s[i]<='9'&&s[i+2]>='0'&&s[i+2]<='9'&&s[i]<s[i+2])
			{
				for(j=s[i]; j<=s[i+2]-1; j++)
					printf("%c", j);
				i+=1;
			}
			else if(s[i]>='a'&&s[i]<='z'&&s[i+2]>='a'&&s[i+2]<='z'&&s[i]<s[i+2])
			{
				for(j=s[i]; j<=s[i+2]-1; j++)
					printf("%c", j);
				i+=1;
			}
			else if(s[i]>='A'&&s[i]<='Z'&&s[i+2]>='A'&&s[i+2]<='Z'&&s[i]<s[i+2])
			{
				for(j=s[i]; j<=s[i+2]-1; j++)
					printf("%c", j);
				i+=1;
			}
			else
			 	printf("%c", s[i]);
		}
		else
			printf("%c", s[i]);
	}
}

