#include<stdio.h>
#include<string.h>

int main()
{
	char s[10000];
	int i=0,j,k,q,p;
	gets(s);
	while(s[i]!='\0')
	{
		
		j=i+1;
		if(s[j]=='-')
		{
		if(s[i]>='a'&&s[i]<='z'&&s[i+2]>='a'&&s[i+2]<='z')
		{
			p=s[i+2]-'a';q=s[i]-'a';
		for(k=0;k<p-q;k++){
		printf("%c",k+'a'+q);
		}i=i+2;
		}
		else if(s[i]>='A'&&s[i]<='Z'&&s[i+2]>='A'&&s[i+2]<='Z')
		{p=s[i+2]-'A';q=s[i]-'A';
		for(k=0;k<s[i+2]-s[i];k++)printf("%c",k+'A'+q);
		i=i+2;
		}
		else if(s[i]>='0'&&s[i]<='9'&&s[i+2]>='0'&&s[i+2]<='9')
		{p=s[i+2]-'0';q=s[i]-'0';
		for(k=0;k<s[i+2]-s[i];k++)printf("%c",k+'0'+q);
		i=i+2;
		}
		else
		{
		for(k=0;k<2;k++)printf("%c",s[i+k]);
		i=i+2;
		}
		}
		else {
		printf("%c",s[i]);
		i++;}
	}
	
	return 0;
}


