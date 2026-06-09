#include<stdio.h>
#include<string.h>
#define N 100000
int main()
{
	char s[N],j;
	int i;
	gets(s);
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]=='-')
		{
			if((s[i-1]<='z'&&s[i-1]>='a')&&(s[i+1]<='z'&&s[i+1]>='a')&&(s[i-1]<s[i+1]))
			{
				for(j=s[i-1]+1;j<s[i+1];j++)
				    printf("%c",j);
			}
			else if((s[i-1]<='Z'&&s[i-1]>='A')&&(s[i+1]<='Z'&&s[i+1]>='A')&&(s[i-1]<s[i+1]))
			{
				for(j=s[i-1]+1;j<s[i+1];j++)
				    printf("%c",j);
			}
			else if((s[i-1]<='9'&&s[i-1]>='0')&&(s[i+1]<='9'&&s[i+1]>='0')&&(s[i-1]<s[i+1]))
			{
				for(j=s[i-1]+1;j<s[i+1];j++)
				    printf("%c",j);
			}
			else
			printf("-");
		}
		else
		printf("%c",s[i]);
	}
	return 0;

}



