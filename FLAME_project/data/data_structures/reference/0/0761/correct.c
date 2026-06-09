#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
	int l,i,k,j,p;
	char s[1024];
	scanf("%s",s);
	l=strlen(s);
	for(i=0;i<l;i++)
	{
		if(s[i]=='-')
		{
			if(s[i-1]>='A'&&s[i-1]<='Z'&&s[i-1]>='A'&&s[i+1]<='Z'&&s[i-1]<s[i+1])
			{
				k=s[i+1]-s[i-1];
				for(j=1;j<k;j++)
				printf("%c",s[i-1]+j);p++;
			}
			if(s[i-1]>='a'&&s[i-1]<='z'&&s[i-1]>='a'&&s[i+1]<='z'&&s[i-1]<s[i+1])
			{
				k=s[i+1]-s[i-1];
				for(j=1;j<k;j++)
				printf("%c",s[i-1]+j);p++;
			}
			if(s[i-1]>='0'&&s[i-1]<='9'&&s[i-1]>='0'&&s[i+1]<='9'&&s[i-1]<s[i+1])
			{
				k=s[i+1]-s[i-1];
				for(j=1;j<k;j++)
				printf("%c",s[i-1]+j);p++;
			}
			if(p==0)
			printf("%c",s[i]);
			p=0;
		}
		else
		printf("%c",s[i]);
	}
	return 0;
}

