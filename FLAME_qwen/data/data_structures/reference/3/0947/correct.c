#include<stdio.h>
#include<string.h>
int main()
{
	char s[105];
	scanf("%s",s);
	int len=strlen(s);
	int i,j,num;
	if(s[0]!='0')
	{
		printf("%c.",s[0]);
		for(i=0;i<len;i++)
		{
			if(s[i]=='.')
			{
				num=i-1;
				break;
			}
		}
		for(i=1;i<len;i++)
		{
			if(s[i]!='.')
			printf("%c",s[i]);
		}
		printf("e%d",num);
		return 0;
	}
	if(s[0]=='0')
	{
		if(s[2]!='0')
		{
			printf("%c",s[2]);
			if(len>3)
			{
				printf("."); 
				for(i=3;i<len;i++)
				printf("%c",s[i]);
			}
			printf("e-1");
			return 0;
		}
		if(s[2]=='0')
		{
			for(i=2;s[i]=='0'&&s[i+1]=='0';i++);
			num=i;
			if(i+2==len)
			printf("%c",s[len-1]);
			else
			{
				printf("%c.",s[i+1]);
				for(j=i+2;j<len;j++)
				printf("%c",s[j]);
			}
			printf("e-%d",num);
			return 0;
		}
	}
}

