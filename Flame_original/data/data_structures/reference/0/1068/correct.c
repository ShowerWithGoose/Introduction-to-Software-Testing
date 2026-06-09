#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define LL long long
#define D double
#define f(i,s,n) for(i=s;i<n;i++)
int main()
{
	char s[10000];
	char c[10000];
	gets(s);
	int i,j=0,k;
	for(i=0;s[i]!='\0';i++)
	{
		c[j++]=s[i];
		if(s[i]=='-')
		{
			if(s[i-1]>='A'&&s[i-1]<'Z'&&s[i+1]>s[i-1]&&s[i+1]<='Z')
			{
				j=j-1;
				for(k=j;j<(s[i+1]-s[i-1]+k);j++)
				{
					c[j]=c[j-1]+1;
				}
				i=i+1;
			}
				else if(s[i-1]>='a'&&s[i-1]<'z'&&s[i+1]>s[i-1]&&s[i+1]<='z')
				{
					j=j-1;
					for(k=j;j<(s[i+1]-s[i-1]+k);j++)
								{
									c[j]=c[j-1]+1;
								}
								i=i+1;	
				}
				else if(s[i-1]>='0'&&s[i-1]<'9'&&s[i+1]>s[i-1]&&s[i+1]<='9')
				{
					j=j-1;
					for(k=j;j<(s[i+1]-s[i-1]+k);j++)
													{
														c[j]=c[j-1]+1;
													}
													i=i+1;	
				}
		}
	}
	puts(c);
	return 0;
} 



