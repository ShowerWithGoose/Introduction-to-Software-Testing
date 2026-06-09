#include <stdio.h>
#include <string.h>

#define MAXN 100000

char s[MAXN],a[MAXN];
int len1,len2;

int main()
{
	scanf("%s",s);
	char *p=strchr(s,'.');
	strcpy(a,p+1);
	*p='\0';
	len1=strlen(s),len2=strlen(a);
	if(len1==1&&s[0]=='0')
	{
		int num=0;
//		puts(a);
		while(a[num]=='0')
		{
			num++;
		}
//		printf("num=%d\n",num);
		printf("%c",a[num]);
		for(int i=num+1;i<len2;i++)
		{
			if(i==num+1) printf(".");
			printf("%c",a[i]);
		}
		printf("e-%d",num+1);
	}
	else
	{
		printf("%c.",s[0]);
		for(int i=1;i<len1;i++)
		{
			printf("%c",s[i]);
		}
		for(int i=0;i<len2;i++)
		{
			printf("%c",a[i]);
		}
		printf("e%d",len1-1);
	}
	return 0;
}

