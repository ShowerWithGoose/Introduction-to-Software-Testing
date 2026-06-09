#include<stdio.h>
#include<string.h>
int main()
{
	char s1[1000],s2[1000];
	gets(s1);
	int i,l,k=0;
	char c;
	l=strlen(s1);
	for(i=0;i<l;i++)
	{
		if(s1[i]=='-')
		{
			if(s1[i-1]>='0'&&s1[i-1]<='9'&&s1[i+1]>='0'&&s1[i+1]<='9'&&s1[i-1]<s1[i+1])
			{
				c=s1[i-1]+1;
				while(c<s1[i+1])s2[k++]=c++;
			}
			else if(s1[i-1]>='a'&&s1[i-1]<='z'&&s1[i+1]>='a'&&s1[i+1]<='z'&&s1[i-1]<s1[i+1])
			{
				c=s1[i-1]+1;
				while(c<s1[i+1])s2[k++]=c++;
			}
			else if(s1[i-1]>='A'&&s1[i-1]<='Z'&&s1[i+1]>='A'&&s1[i+1]<='Z'&&s1[i-1]<s1[i+1])
			{
				c=s1[i-1]+1;
				while(c<s1[i+1])s2[k++]=c++;
			}
			else s2[k++]=s1[i];
		}
		else s2[k++]=s1[i];
	}
	s2[k]='\0';
	printf("%s",s2);
	return 0;
}

