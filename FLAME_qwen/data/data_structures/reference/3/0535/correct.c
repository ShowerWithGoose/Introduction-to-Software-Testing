#include<stdio.h>
#include<string.h>
char s[120];
int main() {
	int i,one=0,point,leng,all;
	scanf("%s",&s);
	leng=strlen(s);
	for(i=0; i<leng; i++) {
		if(s[i]=='.') {
			point=i;
			break;
		}
	}
	for(i=0; i<leng; i++) {
		if(s[i]<='9'&&s[i]>='1') {
			one=i;
			break;
		}
	}
	all=point-one;
	if(one==0)all--;
	if(leng==one+1)printf("%ce%d",s[one],all);
	else {
		for(i=one; i<leng; i++) {
			if(s[i]!='.')printf("%c",s[i]);
			if(i==one)printf(".");
		}
		printf("e%d",all);
	}
	return 0;
}





