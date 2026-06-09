#include<stdio.h>
#include<string.h>
int main() {
	char s[1000];
	gets(s);
	int i,e=0,flag=1;
	if(s[0]=='0'&&strlen(s)==1) {
		printf("0");
	} else if(s[0]=='0') {
		for(i=0; i<strlen(s); i++) {
			if(s[i]!='.'&&s[i]!='0') {
				e=1-i;
				break;
			}
		}
		int sign=i;
		for(i=sign; i<strlen(s); i++) {
			printf("%c",s[i]);
			if(i==sign&&i!=strlen(s)-1) {
				printf(".");
			}
		}
	} else if(s[0]=='-'&&s[1]=='0') {
		for(i=1; i<strlen(s); i++) {
			if(s[i]!='.'&&s[i]!='0') {
				e=2-i;
				break;
			}
		}
		int sign=i;
		printf("-");
		for(i=sign; i<strlen(s); i++) {
			printf("%c",s[i]);
			if(i==sign&&i!=strlen(s)-1) {
				printf(".");
			}
		}
	}
	else if(s[0]!='-'){
		for(i=0; i<strlen(s); i++) {
			if(s[i]=='.') {
				flag=0;
				e=i-1;
				break;
			}
		}
		if(flag==1) {
			e=i-1;
			int flag2=1;
			for(i=1; i<strlen(s); i++) {
				if(s[i]!='0') {
					flag2=0;
					break;
				}
			}
			if(flag2==0) {
				for(i=strlen(s)-1; i>=0; i--) {
					if(s[i]!='0'&&s[i]!='.') {
						flag2=i;
						break;
					}
				}
				for(i=0; i<=flag2; i++) {
					if(s[i]!='.')
						printf("%c",s[i]);
					if(i==0) {
						printf(".");
					}
				}
			} else {
				printf("%c",s[0]);
			}
		}
		if(flag==0) {
			for(i=0; i<strlen(s); i++) {
				if(s[i]!='.')
					printf("%c",s[i]);
				if(i==0) {
					printf(".");
				}
			}
		}
	}else{
		for(i=0; i<strlen(s); i++) {
			if(s[i]=='.') {
				flag=0;
				e=i-2;
				break;
			}
		}
		if(flag==1) {
			e=i-2;
			int flag2=1;
			for(i=2; i<strlen(s); i++) {
				if(s[i]!='0') {
					flag2=0;
					break;
				}
			}
			if(flag2==0) {
				for(i=strlen(s)-1; i>=0; i--) {
					if(s[i]!='0'&&s[i]!='.') {
						flag2=i;
						break;
					}
				}
				printf("-");
				for(i=1; i<=flag2; i++) {
					if(s[i]!='.')
						printf("%c",s[i]);
					if(i==1) {
						printf(".");
					}
				}
			} else {
				printf("-%c",s[1]);
			}
		}
		if(flag==0) {
			printf("-");
			for(i=1; i<strlen(s); i++) {
				if(s[i]!='.')
					printf("%c",s[i]);
				if(i==1) {
					printf(".");
				}
			}
		}
	}
	
		printf("e%d",e);
	return 0;
}

