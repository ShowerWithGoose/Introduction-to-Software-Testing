#include <stdio.h>
#include <string.h>
int main()
{
	char s[105];
	gets(s);
	int flag=-1,before=-1,after=-1,end=-1,i;
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]!='0'&&before==-1)
			before=i;
		if(s[i]=='.')
		{
			flag=i;
			continue;
		}
		if(flag!=-1&&s[i]!='0')	
		{
			if(after==-1)
			after=i;
			end=i;
		}
	}
	if(before==-1&&end==-1)
	printf("0e0");
	else if(before<flag)
	{
		printf("%c",s[before]);
		if(end==-1)
		{
			if(before-flag>1)
			{
				printf(".");
				for(i=1;i<flag-before;i++)
				printf("%c",s[before+i]);
			}
		}
		else{
			printf(".");
			for(i=1;i<=end-before;i++)
			if(s[before+i]!='.')printf("%c",s[before+i]);
		}
		printf("e%d",flag-before-1);
	}
	else
	{
		printf("%c",s[after]);
		if(end>after)
		{
			printf(".");
			for(i=1;i<=end-after;i++)
			printf("%c",s[after+i]);
		}
		printf("e-%d",after-flag);
	}
	return 0;
}

