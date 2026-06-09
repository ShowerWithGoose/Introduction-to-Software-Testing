#include <stdio.h>
#include <ctype.h>
#include <string.h>
void  expanding(char a,char b){
	int i;
	if((!(isupper(a)==0||isupper(b)==0)||!(islower(a)==0||islower(b)==0)||(a>='0'&&a<='9'&&b>='0'&&b<='9'))&&ispunct(a)==0&&ispunct(b)==0&&a<b)
	for(i=1;i<b-a;i++)
	printf("%c",a+i);
	else
	printf("-");
}
int main(){
	char s[1000];
	gets(s);
	int i;
	for(i=0;i<strlen(s);i++)
	if(s[i]=='-'&&s[i+1]!='\0')
	expanding(s[i-1],s[i+1]);
	else
	printf("%c",s[i]);
	return 0;
}

