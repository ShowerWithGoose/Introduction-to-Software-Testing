#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

char s[100];
void p_ex(char a,char b){
	if(((a<='z'&&a>='a')&&(b<='z'&&b>='a'))
	||((a<='Z'&&a>='A')&&(b<='Z'&&b>='A'))
	||((a<='9'&&a>='0')&&(b<='9'&&b>='0'))){
		int cnt=b-a;
		for(int i=1;i<=cnt-1;i++)printf("%c",a+i);
	}
	else{
		printf("-");
	}
}
int main(){
	gets(s);
	int len=strlen(s);
	for(int i=0;i<len;i++){
		if(s[i]!='-')printf("%c",s[i]);
		else {
			if(i!=0&&i!=len-1)p_ex(s[i-1],s[i+1]);
			else printf("%c",s[i]);
		}
	}
	return 0;
}


