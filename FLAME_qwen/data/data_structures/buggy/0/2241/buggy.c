#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int bigger();
char S[10000];
int main(){
	scanf("%s",S);
	for(int i=0;S[i]!='\0';i++){
		if(S[i] != '-'){
			printf("%c",S[i]);
		}else bigger(i);
	}
	
	return 0;
}
int bigger(int i){
	int a;
	if('0'<=S[i+1]&&S[i+1]<='9'&&'0'<=S[i-1]&&S[i-1]<='9'&&(a = S[i+1]-S[i-1])>0){
		for(int b=1;b<a;b++){
			printf("%c",S[i-1]+b);
		}
	} else
if('a'<=S[i+1]&&S[i+1]<='z'&&'a'<=S[i-1]&&S[i-1]<='z'&&(a = S[i+1]-S[i-1])>0){
		for(int b=1;b<a;b++){
			printf("%c",S[i-1]+b);
		}
	} else
if('A'<=S[i+1]&&S[i+1]<='Z'&&'A'<=S[i-1]&&S[i-1]<='Z'&&(a = S[i+1]-S[i-1])>0){
		for(int b=1;b<a;b++){
			printf("%c",S[i-1]+b);
		}
	}
	return 0;
}

