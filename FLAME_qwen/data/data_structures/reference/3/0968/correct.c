#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
int findpoint(char s[])
{
	int i;
	for(i=0;s[i]!='\0';i++)
	if(s[i]=='.') return i;
}
int findtail(char s[])
{
	return strlen(s)-1;
}
int main()
{
	char s[110];
	int poi,head,tail;
	gets(s);
	poi=findpoint(s);
	tail=findtail(s);
	if(poi==1&&s[0]!='0')
	printf("%se0",s);
	else if(poi==1&&s[0]=='0')
	{
		int i;for(i=2;i<=tail;i++) 
		if(s[i]!='0') {
			head=i;break;
		}
		printf("%c",s[head]);
		for(i=2;i<tail;i++)
		if(s[i]!='0') { printf("."); break;
		}
		char *p; p=s+head+1; 
		printf("%se-%d",p,head-1);
	}
	else
	{
		printf("%c.",s[0]);
		int i;
		for(i=1;i<=tail;i++)
		{
			if(s[i]=='.') continue;
			else printf("%c",s[i]);
		}
		printf("e%d",poi-1);
	}
	return 0; 
} 

