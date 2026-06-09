#include<stdio.h>
#include<string.h>
int main()
{
	char s[100];
	gets(s);
	int i=0,ch=0,cn=0;
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]=='.')
		ch=i;
	}
	i=0;
	while(s[i]=='0'||s[i]=='.')
	{
		i++;
	}
	cn=i;
	if(cn>ch)
	{
		printf("%c",s[cn]);
		if(cn-ch!=1) 
		printf(".");
		printf("%s",s+cn+1);
		printf("e-");
		printf("%d",cn-ch);
	}
	if(ch>cn)
	{
		printf("%d.",s[0]-'0');
		s[ch]=0;
		printf("%s",s+1);
		s[ch]='.';
		printf("%s",s+ch+1);
		printf("e%d",ch-cn-1);
	}
	return 0;
}

