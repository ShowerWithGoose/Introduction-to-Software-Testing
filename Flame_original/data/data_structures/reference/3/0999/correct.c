#include<stdio.h>
#include<string.h>
int main() {
	char s[103];
	gets(s);
	int i,j,x1,sign=0;
	if(s[0]=='-') {
		for(i=j=0; s[i]!='\0'; i++) {
			if(s[i]!='-')s[j++]=s[i];
		}
		s[j]='\0';
		printf("-");
	}
	if((int)(s[0]-'0')>0) {
		for(i=0; s[i]!='.'&&s[i]!='\0'; i++) {

		}
		x1=i;
		for(i=1;s[i]!='\0';i++) {if(s[i]!='0')sign=1;
}

		for(j=0; s[j]!='\0'; j++) {
			if(s[j]=='.')continue;
			printf("%c",s[j]);
			if(sign==1&&j==0)printf(".");
		}
		printf("e%d",x1-1);
	} else {
		for(i=j=0; s[i]!='\0'; i++) {
			if(s[i]!='.')s[j++]=s[i];
		}//去".";
		s[j]='\0';
		for(i=0; s[i]=='0'; i++) {
		}//记录有几个零
		x1=i;
		for(i; s[i]!='\0'; i++) {
			printf("%c",s[i]);
			if(i==x1&&s[i+1]!='\0')printf(".");
		}

		printf("e-%d",x1);
	}
	return 0;
}

