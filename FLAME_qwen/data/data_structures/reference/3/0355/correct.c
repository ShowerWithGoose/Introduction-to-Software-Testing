#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
char s[1000];

int main()
{
	gets(s);
	int i,j,ans;
	if(s[0]=='0')
	{
		for(i=0; s[i]>'9'||s[i]<='0'; i++);

		ans=1-i;
		if(s[i+1]=='\0')
			printf("%se%d",s+i,ans);
		else
		{
			s[i-1]=s[i];
			s[i]='.';
			printf("%se%d",s+i-1,ans);
		}
	}
	else
	{
		for(i=0; s[i]!='.'&&s[i]!='\0'; i++);
		ans=i-1;
		for(; i>1; i--)
			s[i]=s[i-1];
		s[1]='.';
		printf("%se%d",s,ans);
	}
	return 0;
}




