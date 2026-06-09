/* 本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果 */
#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
	char s[105],ans=0;
	gets(s);
	int i;
	if(strchr(s,'.')==NULL)
	{
		ans=strlen(s);
		for(i=0;i<strlen(s);i++)
		{
			if(i==1)
			{
				printf("%c",'.');
			}
			printf("%c",s[i]);
		}
		printf("e-%d",ans);
	}
	
	else if(s[0]=='0')
	{
		int i=0;
		for(i=1;;i++)
		{
			if(s[i]!='0'&&s[i]!='.')
			{
				ans=i;
				break;
			}
		}
		ans--;
		for(i=ans+1;s[i]!='\0';i++)
		{
			if(i==ans+2&&strlen(s)-1>ans+1)
			{
				printf("%c",'.');
			}
			printf("%c",s[i]);
		}
		printf("e-%d\n",ans);
	}
	else
	{
		int i;
		ans=strchr(s,'.')-s-1;
		for(i=0;i<strlen(s);i++)
		{
			if(i==1)
			{
				printf("%c",'.');
			}
			if(isdigit(s[i]))
				printf("%c",s[i]);
		}
		printf("e%d\n",ans);
	}
	return 0;
} 

