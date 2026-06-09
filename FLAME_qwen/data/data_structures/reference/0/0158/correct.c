#include<stdio.h>
#include<string.h>
int main()
{int i,j;
	char s[1000];
	gets(s);
	int n=strlen(s); 
	for(i=0;i<n;i++)
	{if(s[i]=='-'&&((s[i-1]>='0'&&s[i+1]<='9'&&s[i+1]>='0'&&s[i-1]<='9'&&s[i+1]>s[i-1]+1)||(s[i-1]>='a'&&s[i+1]<='z'&&s[i+1]>='a'&&s[i-1]<='z'&&s[i+1]>s[i-1]+1)||(s[i-1]>='A'&&s[i+1]<='Z'&&s[i-1]<='Z'&&s[i+1]>='A'&&s[i+1]>s[i-1]+1)))
	for(j=1;j<s[i+1]-s[i-1];j++)
	printf("%c",s[i-1]+j);
	else 
	printf("%c",s[i]);
	}
	return 0;
}

