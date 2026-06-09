#include<stdio.h>
#include<string.h>
int main()
{
	char s[100000];
	scanf("%s",s);
	char c[100000];
	int len = strlen(s);
	int i,j;
	for(i = 0, j = 0; i < len; i++)
	{
		if(s[i]=='-')
		{
			if(i == 0)
			{
				c[j++] = s[i];
				continue;
			}
			if(s[i-1] >='a'&&s[i-1]<='z' &&s[i+1] >='a'&&s[i+1]<='z' &&s[i+1]>s[i-1])
			{
			for(int k = s[i-1]+1; k < s[i+1]; k++)
			c[j++] = k;
			continue;
			}
			if(s[i-1] >='A'&&s[i-1]<='Z' &&s[i+1] >='A'&&s[i+1]<='Z' &&s[i+1]>s[i-1])
			{
			for(int k = s[i-1]+1; k < s[i+1]; k++)
			c[j++] = k;	
			continue;
			}
			if(s[i-1] >='0'&&s[i-1]<='9' &&s[i+1] >='0'&&s[i+1]<='9' &&s[i+1]>s[i-1])
			{
			for(int k = s[i-1]+1; k < s[i+1]; k++)
			c[j++] = k;
			continue;
			}
			c[j++] = s[i];
		}
		else c[j++] = s[i];
	}
	printf("%s",c);
}
