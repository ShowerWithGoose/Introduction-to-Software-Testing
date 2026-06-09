#include<stdio.h>
const int maxn=1000000;
int main()
{
	char s[maxn];
	scanf("%s",s+1);
	s[0]=0;
	int i,j;
	for(i=1;s[i];i++)
	{
		if(s[i]!='-')
			printf("%c",s[i]);
		else
		{
			if((s[i-1]<s[i+1]&&s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>='0'&&s[i+1]<='9')||(s[i-1]<s[i+1]&&s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<='z')||(s[i-1]<s[i+1]&&s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>='A'&&s[i+1]<='Z'))
				for(j=s[i-1]+1;j<s[i+1];j++)	printf("%c",j);
			else	printf("%c",s[i]);
		}
	}
	return 0;
}



