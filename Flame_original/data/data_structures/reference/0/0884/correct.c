#include<stdio.h> 
#include<string.h>
int main()
{
	char s[1000],b;
	int i,k;
	scanf("%s",s);
	printf("%c",s[0]);
	for(i=1;i<=(strlen(s)-2);i++)
	{
		if(s[i]!='-')
		{
			printf("%c",s[i]);
		}
		else
		{
			if(s[i-1]>='a'&&s[i-1]<'z'&&s[i+1]>s[i-1]&&s[i+1]<='z')
			{
				for(k=1;k<(s[i+1]-s[i-1]);k++)
				{
					b=s[i-1]+k;
					printf("%c",b);
				}
			}
			else if(s[i-1]>='A'&&s[i-1]<'Z'&&s[i+1]>s[i-1]&&s[i+1]<='Z')
			{
				for(k=1;k<(s[i+1]-s[i-1]);k++)
				{
					b=s[i-1]+k;
					printf("%c",b);
				}
			}
			else if(s[i-1]>='0'&&s[i-1]<'9'&&s[i+1]>s[i-1]&&s[i+1]<='9')
			{
				for(k=1;k<(s[i+1]-s[i-1]);k++)
				{
					b=s[i-1]+k;
					printf("%c",b);
				}
			}
			else
			printf("-");
		}
	}
	printf("%c",s[(strlen(s)-1)]);
	return 0;
}

