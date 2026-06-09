#include<stdio.h>
#include<string.h>
char s[10000],t[10000];
int i,j,num,flag=0;
int main() {
	scanf("%s",s);
	for(i=0; s[i]!='\0'; i++) {
		if(s[i]=='.') num=strlen(s)-1-i;
		if(s[i]!='-'&&s[i]!='0'&&s[i]!='.') flag=1;
		if(flag==1&&s[i]!='.') {
			t[j]=s[i];
			j++;
		}
	}
	if(s[0]=='-') printf("-");
	for(i=0; t[i]!='\0'; i++) {
		if(i==1) printf(".%c",t[i]);
		else printf("%c",t[i]);
	}
	printf("e%d",j-1-num);
	return 0;
}



