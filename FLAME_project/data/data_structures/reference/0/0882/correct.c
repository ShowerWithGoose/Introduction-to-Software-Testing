#include<stdio.h> 
int main()
{
	char s[105],es[105];
	int i,j,k;
	scanf("%s",s);
	for(i=0,j=0;s[i]!='\0';i++)
	{
		if(s[i]!='-')
		es[j++]=s[i];
		else if(s[i-1]<s[i+1])
		{
			if( ('a'<=s[i-1]&&s[i-1]<='z'&&'a'<=s[i+1]&&s[i+1]<='z') ||('A'<=s[i-1]&&s[i-1]<='Z'&&'A'<=s[i+1]&&s[i+1]<='Z') || ('0'<=s[i-1]&&s[i-1]<='9'&&'0'<=s[i+1]&&s[i+1]<='9'))
			for(k=1;k!=s[i+1]-s[i-1];k++)
			es[j++]=s[i-1]+k;
			else es[j++]='-';
		}
		else es[j++]='-';
	}
	es[j]='\0';
	printf("%s",es);
	return 0;
}

