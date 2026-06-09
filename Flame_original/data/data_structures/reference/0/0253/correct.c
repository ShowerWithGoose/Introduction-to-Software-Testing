#include<stdio.h>
#include<string.h>
int main()
{
	char s[100000];
	int n;
	scanf("%s",s);
	n=strlen(s)-1;
	for(int i=0;i<=n;i++)
	{
		if(s[i]=='-')
		{
			if(s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>='0'&&s[i+1]<='9'&&s[i-1]<s[i+1])
			for(int j=s[i-1]+1;j<s[i+1];j++)
			printf("%c",j);
			
			else if(s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<='z'&&s[i-1]<s[i+1])
			for(int j=s[i-1]+1;j<s[i+1];j++)
			printf("%c",j);
			
			else if(s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>='A'&&s[i+1]<='Z'&&s[i-1]<s[i+1])
			for(int j=s[i-1]+1;j<s[i+1];j++)
			printf("%c",j);
			
			else
			printf("%c",s[i]); 
		}
		else printf("%c",s[i]);
	}
	
}



