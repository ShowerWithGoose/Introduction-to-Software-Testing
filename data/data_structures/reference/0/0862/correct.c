#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
	char s[10000];
	gets(s);
	int a=strlen(s);// 
	for(int i=0;i<a;i++)
	{
		if(s[i]=='-')
		{
		if(s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]<='z'&&s[i+1]>='a'&&s[i-1]<s[i+1])
		{
			while(s[i-1]!=s[i+1])
			{
				s[i-1]++;
				printf("%c",s[i-1]);
			}
		}
		else if(s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]<='Z'&&s[i+1]>='A'&&s[i-1]<s[i+1])
		{
			while(s[i-1]!=s[i+1])
			{
				s[i-1]++;
				printf("%c",s[i-1]);
			}
		}
		else if(s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]<='9'&&s[i+1]>='0'&&s[i-1]<s[i+1])
		{
			while(s[i-1]!=s[i+1])
			{
				s[i-1]++;
				printf("%c",s[i-1]);
			}
		}	
		else{
			printf("-");
			i--;
		}	
		i++;	 
		} 
		else
		printf("%c",s[i]);
	}
}

