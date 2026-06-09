#include<stdio.h>
#include<string.h>
#define M 10000
int is(char c){
	if(c>='a'&&c<='z') return 1;
	else if(c>='A'&&c<='Z') return 2;
	else if(c>='0'&&c<='9') return 3;
	else return 0;
}
int main(){
	char s[M];
	gets(s);
	for(int i=0;i<strlen(s);i++){
		if(s[i]=='-'){
			if(is(s[i-1])==is(s[i+1])){
				for(int j=1;j<s[i+1]-s[i-1];j++){
					printf("%c",s[i-1]+j);
				}
			}
			else printf("%c",s[i]);
		}
		else printf("%c",s[i]);
	}
	return 0;
}



