#include<stdio.h>
#include<string.h>
int main()
{
	char s[10000];
	int flag=0,k,i;
	gets(s);
	k=0;
	if(s[0]=='0')
	{
		i=1;
		while(!(s[i]>='1'&&s[i]<='9'))
		{
			i++;
			k--;
		}
		printf("%c",s[i]);
		if(s[i+1]=='\0') printf("e%d",k);
		else
		{
			printf(".");
			while(s[++i]!='\0') printf("%c",s[i]);
			printf("e%d",k);
		}
	}
	else
	{
		printf("%c.",s[0]);
		i=0;
		while(s[++i]!='\0')
		{
			if(s[i]=='.') flag=1;
			else printf("%c",s[i]);
			if(!flag) k++;
		}
		printf("e%d",k);
	}
	return 0;
}



