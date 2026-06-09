#include<stdio.h>
#include<string.h>
int main()
{
	int i=0;
	int n=0;
	int l=0;
	char s[100]={0};
	scanf("%s",s);
	for(i=1;i<=strlen(s);i++)
	{
		printf("%c",s[i-1]);
		if(s[i]=='-')
		{   
		     if('a'<=s[i-1]&&s[i-1]<s[i+1]&&s[i+1]<='z')
			{
				l=s[i+1]-s[i-1];
				for(n=0;n<l-1;n++)
				{
					printf("%c",s[i-1]+n+1);
				}
				i=i+1;
				
			}
			if('A'<=s[i-1]&&s[i-1]<s[i+1]&&s[i+1]<='Z')
			{
				l=s[i+1]-s[i-1];
				for(n=0;n<l-1;n++)
				{
					printf("%c",s[i-1]+n+1);
				}
				i=i+1;
				
			}
			if('0'<=s[i-1]&&s[i-1]<s[i+1]&&s[i+1]<='9')
			{
				l=s[i+1]-s[i-1];
				for(n=0;n<l-1;n++)
				{
					printf("%c",s[i-1]+n+1);
				}
				i=i+1;
				
			}
		}
	 }
	 return 0; 
}



