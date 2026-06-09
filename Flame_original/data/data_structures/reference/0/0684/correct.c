#include<stdio.h>
#include<string.h>
int main()
{
	char s[1000],s2[1000];
	int a,b,i;
	gets(s);
	for(a=0,b=0;s[a]!='\0';a++)
	{
		if((s[a]=='-')&&(((s[a-1]>='A')&&(s[a+1]<='Z')&&(s[a-1]<s[a+1]))||((s[a-1]>='a')&&(s[a+1]<='z')&&(s[a-1]<s[a+1]))||((s[a-1]>='0')&&(s[a+1]<='9')&&(s[a-1]<s[a+1]))))
		{
			for(i=b;s2[i-1]<s[a+1]-1;i++,b++)
			{
				s2[b]=s2[i-1]+1;
			}
			continue;
		}
		s2[b]=s[a];b++;
				
	}
	printf("%s",s2);
	return 0;
}

