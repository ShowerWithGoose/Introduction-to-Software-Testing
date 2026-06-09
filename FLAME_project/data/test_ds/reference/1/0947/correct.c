#include<stdio.h>
#include<string.h>
int main()
{
	char s[10005],j;
	int i;
	scanf("%s",s);
	int len=strlen(s);
	printf("%c",s[0]);
	for(i=1;i<len;i++)
	{
		if(s[i]=='-')
		{
			if((s[i-1]<='9'&&s[i-1]>='0')&&(s[i+1]<='9'&&s[i+1]>='0')&&(s[i-1]<s[i+1]))
			{
				for(j=s[i-1]+1;j<=s[i+1];j++)
				{printf("%c",j);}
				i++;
			}
			else if((s[i-1]<='z'&&s[i-1]>='a')&&(s[i+1]<='z'&&s[i+1]>='a')&&(s[i-1]<s[i+1]))
			{
				for(j=s[i-1]+1;j<=s[i+1];j++)
				{printf("%c",j);}
				i++;
			}
			else if((s[i-1]<='Z'&&s[i-1]>='A')&&(s[i+1]<='Z'&&s[i+1]>='A')&&(s[i-1]<s[i+1]))
			{
				for(j=s[i-1]+1;j<=s[i+1];j++)
				{printf("%c",j);}
				i++;
			}
			else printf("%c",s[i]);
		} 
	    else printf("%c",s[i]);
	}
	return 0;
}



