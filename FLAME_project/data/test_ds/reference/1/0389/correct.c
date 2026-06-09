#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char a[30] = "abcdefghijklmnopqrstuvwxyz";
char b[30] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char c[15] = "0123456789";
char s[100];
int main() {
	scanf("%s",s);
	int i,len=strlen(s);
	for(i = 0; i<len; i++) {
		if(s[i] >= 'a' && s[i] <='z') printf("%c",s[i]);
		if(s[i] >= 'A' && s[i] <='Z') printf("%c",s[i]);
		if(s[i] >= '0' && s[i] <='9') printf("%c",s[i]);
		if(s[i] == '-') {
			if(islower(s[i-1])&&islower(s[i+1]) && s[i-1] < s[i+1]) {
				int j,flag=0;
				for(j=0; j<26; j++) {
					if(a[j]==s[i+1]) break;
					if(a[j]==s[i-1]) {
						flag=1;
						continue;
					}
					if(flag==1) {
						printf("%c",a[j]);
					}
				}
			} else if(isupper(s[i-1])&&isupper(s[i+1]) && s[i-1] < s[i+1]) {
				int j,flag=0;
				for(j=0; j<26; j++) {
					if(b[j]==s[i+1]) break;
					if(b[j]==s[i-1]) {
						flag=1;
						continue;
					}
					if(flag==1) {
						printf("%c",b[j]);
					}
				}
			} else if(s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>='0'&&s[i+1]<='9' && s[i-1] < s[i+1]) {
				int j,flag=0;
				for(j=0; j<10; j++) {
					if(c[j]==s[i+1]) break;
					if(c[j]==s[i-1]) {
						flag=1;
						continue;
					}
					if(flag==1) {
						printf("%c",c[j]);
					}
				}
			} else printf("%c",s[i]);
		}
	}
	return 0;
}






