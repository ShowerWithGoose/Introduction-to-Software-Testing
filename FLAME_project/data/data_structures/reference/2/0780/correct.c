#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 100000

char s[MAXN];

int main()
{
	gets(s);
	int i=0,j=0,len=strlen(s);
	while(i<len)
	{
		if(s[i]!=' ')
			s[j++]=s[i];
		i++;
	}
	s[j]='\0';
	int num[MAXN];
	char sign[MAXN];
	int len1=0,len2=0;
	for(i=0;s[i]!='=';)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			int sum=0;
			while(s[i]>='0' && s[i]<='9')
				sum=sum*10+s[i++]-'0';
			num[len1++]=sum;
			if(len2>0)
				if(sign[len2-1]=='*' || sign[len2-1]=='/')
				{
					if(sign[len2-1]=='*')
						num[len1-2]=num[len1-2]*num[len1-1];
					else
						num[len1-2]=num[len1-2]/num[len1-1];
					len1--;
					len2--;
				}
		}
		else
			sign[len2++]=s[i++];
	}
	int ans=num[0];
	for(i=0,j=1;i<len2;i++,j++)
	{
		if(sign[i]=='-')
			ans-=num[j];
		else if(sign[i]=='+')
			ans+=num[j];
	}
	printf("%d",ans);
	return 0;
}



