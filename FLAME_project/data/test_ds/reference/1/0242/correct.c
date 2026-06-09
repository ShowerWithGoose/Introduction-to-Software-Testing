#include<stdio.h>
#include<string.h>
#include<ctype.h>
char s[9999],s1[999];
int k,i,j;
char temp;
int main()
{
	gets(s);
	for(i=0,j=0;i<strlen(s);i++,j++)
	{
		s1[j]=s[i];
		if(s[i]=='-')
		{
			if(s[i-1]>=97&&s[i+1]<=122&&s[i-1]<s[i+1])
			{
				k=s[i+1]-s[i-1]-1;
				for(int p=1;p<=k;p++)
				{
					s1[j++]=s[i-1]+p;
				}
				j--; 
			}
			if(s[i-1]>=65&&s[i+1]<=90&&s[i-1]<s[i+1])
			{
				k=s[i+1]-s[i-1]-1;
				for(int p=1;p<=k;p++)
				{
					s1[j++]=s[i-1]+p;
				}
				j--;
			}
			if(s[i-1]>=48&&s[i+1]<=57&&s[i-1]<s[i+1])
			{
				k=s[i+1]-s[i-1]-1;
				for(int p=1;p<=k;p++)
				{
					s1[j++]=s[i-1]+p;
				}
				j--;
			}
		}
	}
	s1[j]='\0';
	puts(s1);
} 



