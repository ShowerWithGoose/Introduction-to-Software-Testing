#include<stdio.h>
#include<string.h>
char ch[100000+7],s[100000+7];
int same(int i,int j)
{
	if((s[i]>='0'&&s[i]<='9')&&(s[j]>='0'&&s[j]<='9')&&s[j]>s[i]) return 1;
	if((s[i]>='a'&&s[i]<='z')&&(s[j]>='a'&&s[j]<='z')&&s[j]>s[i]) return 1;
	if((s[i]>='A'&&s[i]<='Z')&&(s[j]>='A'&&s[j]<='Z')&&s[j]>s[i]) return 1;
	return 0;
}
int main()
{
	int i=0,j=0,len;
	char k;
	gets(s);
	len=strlen(s);
	if(s[i]=='-')ch[j++]=s[i++];
	while(i<len)
	{
		while(s[i]!='-'&&i<len)
		{
			ch[j++]=s[i++];
		}
		if(i==len-1)ch[j++]=s[i];
		else if(i!=len-1&&same(i-1,i+1)==0)ch[j++]=s[i++];
		else if(i!=len-1&&same(i-1,i+1)==1)
		{
			for(k=s[i-1]+1;k<s[i+1];k++)
			{
				ch[j++]=k;
			}
			i++;
			ch[j++]=s[i++];
		}
	}
	ch[j]='\0';
	puts(ch);
	return 0;
}

