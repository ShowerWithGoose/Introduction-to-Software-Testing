#include<stdio.h>
int main()
{
	char s[100];
	char a, b;
	gets(s);
	int i, j, k;
	for(i=j=0; s[i]!='\0'; i++)
	{
		if(s[i]=='-' && i!=0)
		{
			a=s[i-1];
			b=s[i+1];
			if((a>='a' && b<='z') || (a>='A' && b<='Z') || (a>='0' && b<='9'))
				for(k=1;k<b-a;k++) printf("%c", a+k);
			else printf("-");
		}
		else printf("%c", s[i]);
	}
	return 0;
}

