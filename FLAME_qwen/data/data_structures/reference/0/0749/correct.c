#include<stdio.h>
#include<string.h>
char s[1005];
int judge(char a,char b)
{
	if(a>='a'&&a<='z'&&b>='a'&&b<='z'&&a<b)
	return 1;
	if(a>='A'&&a<='Z'&&b>='A'&&b<='Z'&&a<b)
	return 1;
	if(a>='0'&&a<='9'&&b>='0'&&b<='9'&&a<b)
	return 1;
	
	return 0;
}
int main()
{
	int i,j,k,n;
	char x;
	gets(s);
	n=strlen(s);

	for(i=0;i<n;i++)
	{
		if((i+2<n)&&(s[i+1]=='-'&&judge(s[i],s[i+2])))
		{
			for(j=0;j<s[i+2]-s[i];j++)
			printf("%c",s[i]+j);
			i+=1;
		}
		else printf("%c",s[i]);
	}
	return 0;
}



