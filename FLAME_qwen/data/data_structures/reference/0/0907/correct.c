#include <stdio.h>
#include<string.h>
char s[5000];
void fun(int x){
	if(x<1||x>=strlen(s)-1){
		printf("%c",'-');
	}
	char a=s[x-1],b=s[x+1];
	if(a<b&&(('a'<=a&&b<='z')||('A'<=a&&b<'Z')||('0'<=a&&b<='9')))
	for(char i=a+1;i<b;i++)
	printf("%c",i);
	else{
		printf("%c",'-');
	}
}
int main(){
	gets(s);
	for(int i=0;i<strlen(s);i++){
		if(s[i]=='-'){
			fun(i);
		}
		else printf("%c",s[i]);
	}
	return 0;
}
