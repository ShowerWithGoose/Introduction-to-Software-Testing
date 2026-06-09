#include<stdio.h>
#include<string.h>
#include<math.h>
char s[100006],t[100006];
int len,ji=0;
int main()
{
	scanf("%s",s);
	len=strlen(s);
	int i;
	for(i=0;i<len;i++)
	{
		if(s[i]=='-')
		{
			if(i==0||i==len-1){t[ji++]=s[i];continue;}
			if(s[i-1]<s[i+1])
			{
				if(s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>='A'&&s[i+1]<='Z')
				{
					int j;
					for(j=s[i-1]+1;j<s[i+1];j++)t[ji++]=j;
				}
				else if(s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<='z')
				{
					int j;
					for(j=s[i-1]+1;j<s[i+1];j++)t[ji++]=j;
				}
				else if(s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>='0'&&s[i+1]<='9')
				{
					int j;
					for(j=s[i-1]+1;j<s[i+1];j++)t[ji++]=j;
				}
				else t[ji++]=s[i]; 
			}
			else t[ji++]=s[i]; 
		}
		else t[ji++]=s[i]; 
	}
	t[ji]='\0';
	printf("%s",t);
	return 0;
}

