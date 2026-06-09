#include<stdio.h>
#include<string.h>
#include<math.h>
char ch[105];
int main() {
	gets(ch);
	int i=0,len,j,flag=0;
	len=strlen(ch);
	if(ch[0]=='-') {
		printf("-");
		if(ch[1]=='0') {
			for(i=1; i<len; i++) {
				if(ch[i]=='0'||ch[i]=='.') {
					flag++;
				}
				else{
					break;
				}
			}
			printf("%c",ch[flag+1]);
			if(flag+2==len) {
				printf("e%d",1-flag);
			} else {
				printf(".");
				for(i=flag+2; i<len; i++) {
					printf("%c",ch[i]);
				}
				printf("e%d",1-flag);
			}
		} else {
			for(i=1; i<len; i++) {
				if(ch[i]=='.') {
					break;
				}
			}
			j=i;
			printf("%c.",ch[1]);
			for(i=2; i<len; i++) {
				if(ch[i]=='.') {
					continue;
				} else printf("%c",ch[i]);
			}
			printf("e%d",j-2);
		}
	} else {
		if(ch[0]=='0') {
			for(i=0; i<len; i++) {
				if(ch[i]=='0'||ch[i]=='.') {
					flag++;
				}
				else{
					break;
				}
			}
			printf("%c",ch[flag]);
			if(flag+1==len) {
				printf("e%d",1-flag);
			} else {
				printf(".");
				for(i=flag+1; i<len; i++) {
					printf("%c",ch[i]);
				}
				printf("e%d",1-flag);
			}
		} else {
			for(i=0; i<len; i++) {
				if(ch[i]=='.') {
					break;
				}
			}
			j=i;
			printf("%c.",ch[0]);
			for(i=1; i<len; i++) {
				if(ch[i]=='.') {
					continue;
				} else printf("%c",ch[i]);
			}
			printf("e%d",j-1);
		}
	}
}



