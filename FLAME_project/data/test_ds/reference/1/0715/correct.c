#include<stdio.h>
#include<string.h>

int main()
{
	char ch[100005];gets(ch);
	int len=strlen(ch);
	int i,j;
	for(i=0;i<len;i++)
	{
		if(ch[i]!='-'||i==0||i==len-1)printf("%c",ch[i]);
		else
		{
			if('0'<=ch[i-1]&&ch[i-1]<ch[i+1]&&ch[i+1]<='9')
			{
				int left=(int)ch[i-1];
				int right=(int)ch[i+1];
				for(j=left+1;j<=right-1;j++)
				{
					char ch0=(char)j;
					printf("%c",ch0);
				}
			}
			else if('a'<=ch[i-1]&&ch[i-1]<ch[i+1]&&ch[i+1]<='z')
			{
				int left=(int)ch[i-1];
				int right=(int)ch[i+1];
				for(j=left+1;j<=right-1;j++)
				{
					char ch0=(char)j;
					printf("%c",ch0);
				}
			}
			else if('A'<=ch[i-1]&&ch[i-1]<ch[i+1]&&ch[i+1]<='Z')
			{
				int left=(int)ch[i-1];
				int right=(int)ch[i+1];
				for(j=left+1;j<=right-1;j++)
				{
					char ch0=(char)j;
					printf("%c",ch0);
				}
			}
			else printf("-");
		}
	}
	printf("\n");
	return 0;
}



