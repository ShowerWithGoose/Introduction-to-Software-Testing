#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 100000

int main()
{
	char s[MAXN];
	gets(s);
	char *p=s;
	while((p=strstr(p,"-"))!=NULL)
	{
		char ch1,ch2;
		ch1=*(p-1);
		ch2=*(p+1);
		if(ch1<ch2 && ((ch1>='A' && ch1<='Z' && ch2>='A' && ch2<='Z') || (ch1>='a' && ch1<='z' && ch2>='a' && ch2<='z') || (ch1>='0' && ch1<='9' && ch2>='0' && ch2<='9')))
		{
			char s1[MAXN],s2[MAXN];
			memset(s2,0,MAXN*sizeof(char));
			strcpy(s1,p+2);
			int i=0;
			for(char q=ch1;q<=ch2;q++)
				s2[i++]=q;
			*(p-1)='\0';
			strcat(s,s2);
			strcat(s,s1);
		}
		else
			p++;
	}
	puts(s);
	return 0;
}



