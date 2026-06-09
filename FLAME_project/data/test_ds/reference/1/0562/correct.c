#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main() {
	char s[10000];
	int flag[10000]={0};
	gets(s);
	int l=strlen(s);
	for(int i=0; i<l; i++) {
		if(s[i]!='-'&&s[i+1]!='-')
			printf("%c",s[i]);
		else if(s[i]=='-') {
			if((isupper(s[i-1])&&isupper(s[i+1]))||(islower(s[i-1])&&islower(s[i+1]))||(isdigit(s[i-1])&&isdigit(s[i+1]))) {
				if(s[i+1]>s[i-1]) {
					if (flag[i-1]==0)
						printf("%c",s[i-1]);
					for(int k=s[i-1]+1; k<=s[i+1]; k++)
						printf("%c",k);
					flag[i+1]=1;
					i=i+1;
				} else printf("%c%c",s[i-1],s[i]);
			} else printf("%c%c",s[i-1],s[i]);
		}

	}
	return 0;
}

