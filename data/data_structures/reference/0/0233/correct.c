#include<stdio.h>
int main() {
	char s[200];
    gets(s);

	int i=0,j;
	for(i=0; s[i]!='\0'; i++) {

		if(s[i]=='-') {

			if(('0'<=s[i-1]&&s[i-1]<'9'&&s[i+1]>s[i-1]&&s[i+1]<='9')||('a'<=s[i-1]&&s[i-1]<'z'&&s[i+1]>s[i-1]&&s[i+1]<='z')||('A'<=s[i-1]&&s[i-1]<'Z'&&s[i+1]>s[i-1]&&s[i+1]<='Z'))	{
			if('0'<=s[i-1]&&s[i-1]<'9'&&s[i+1]>s[i-1]&&s[i+1]<='9')	{
				for(j=1;(s[i-1]+j)<s[i+1];j++)
					printf("%c", s[i-1]+j);}

			if('a'<=s[i-1]&&s[i-1]<'z'&&s[i+1]>s[i-1]&&s[i+1]<='z')	{
				for(j=1;(s[i-1]+j)<s[i+1];j++)
					printf("%c", s[i-1]+j);}

			if('A'<=s[i-1]&&s[i-1]<'Z'&&s[i+1]>s[i-1]&&s[i+1]<='Z')	{
				for(j=1;(s[i-1]+j)<s[i+1];j++)
					printf("%c", s[i-1]+j);}}
					
			else printf("-");		
		}

		else printf("%c", s[i]);
	}
	if(s[i]=='\0')
	return 0;
}


