#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
#define eps 1e-10

int main() {
	int i,j;
	char s[1000],p[100];
	char ch1,ch2;
	gets(s);
	for(i=0; s[i]!='\0'; i++) {
		if(s[i]>='a'&&s[i]<='z'||s[i]>='0'&&s[i]<='9'||s[i]>='A'&&s[i]<='Z')
			printf("%c",s[i]);
		else if(s[i]=='-') {
			ch1=s[i-1];
			ch2=s[i+1];
			if(s[i-1]>='a'&&s[i+1]<='z') {
				if(ch1>=ch2)
					printf("%c",s[i]);
				else {
					for(j=ch1+1; j<ch2; j++)
						printf("%c",j);
				}
			}
			else if(s[i-1]>='A'&&s[i+1]<='Z') {
				if(ch1>=ch2)
					printf("%c",s[i]);
				else {
					for(j=ch1+1; j<ch2; j++)
						printf("%c",j);
				}
			}
			else if(s[i-1]>='0'&&s[i+1]<='9') {
				if(ch1>=ch2)
					printf("%c",s[i]);
				else {
					for(j=ch1+1; j<ch2; j++)
						printf("%c",j);
				}
			}
			else printf("%c",s[i]);
		}

	}
	return 0;
}




