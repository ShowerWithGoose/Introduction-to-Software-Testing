#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char s[100],t[100];
	int i,j=0,k;
	gets(s);
	for(i=0;i<=strlen(s);i++)
	{
		if(s[i]!=45)
		{
			t[j]=s[i];
			j++;
		}
		else
		{
			if(((s[i-1]>=48&&s[i-1]<=57&&s[i+1]>=48&&s[i+1]<=57)||(s[i-1]>=65&&s[i-1]<=90&&s[i+1]>=65&&s[i+1]<=90)||(s[i-1]>=97&&s[i-1]<=122&&s[i+1]>=97&&s[i+1]<=122))&&s[i-1]<s[i+1]-1)
			for(k=s[i-1]+1;k<s[i+1];k++,j++)
			t[j]=k;
			else
			{
				t[j]='-';
				j++;
			}
		}
	}
	printf("%s",t);
	return 0;
}

