#include<stdio.h>
int main()
{
	char s[100000],s1,s2,c;
	int i;
	gets(s);
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]=='-'&&(i!=0))
		{
			s1=s[i-1];
			s2=s[i+1];
			if(s1>='0'&&s1<='9'&&s2>='0'&&s2<='9'&&s2>s1||s1>='A'&&s1<='Z'&&s2>='A'&&s2<='Z'&&s2>s1||s1>='a'&&s1<='z'&&s2>='a'&&s2<='z'&&s2>s1)
			  for(c=s1+1;c<s2;c++) printf("%c",c);
			else printf("%c",s[i]);
		}
		else printf("%c",s[i]);
	 } 
	return 0;
}

