#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
char s[20000]; 
int o=0;
int main()
{
	gets(s);
	int i,l;
	l=strlen(s);
	for(i=0;i<=l;i++)
	{
		o=0;
		if(s[i]=='-')
		{
			if((s[i-1]>='a')&&(s[i-1]<='z')&&s[i+1]<='z')
			{
				int m=s[i+1]-s[i-1];
				if(m>0)
				{
					int k=1;
					for(;k<=m-1;k++)
					printf("%c",s[i-1]+k);
					o++; 
				}
			}
			if((s[i-1]>='A')&&(s[i-1]<='Z')&&s[i+1]<='Z')
			{
				int m=s[i+1]-s[i-1];
				if(m>0)
				{
					int k=1;
					for(;k<=m-1;k++)
					printf("%c",s[i-1]+k);
					o++;
				}
			}
			if((s[i-1]>='0')&&(s[i-1]<='9')&&s[i+1]<='9')
			{
				int m=s[i+1]-s[i-1];
				if(m>0)
				{
					int k=1;
					for(;k<=m-1;k++)
					printf("%c",s[i-1]+k);
					o++;
				}
			}
		}
		if(o==0)
		printf("%c",s[i]);
	}
	return 0;
}

