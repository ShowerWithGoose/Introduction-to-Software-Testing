#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
void expand(char a,char b){
	char x;
	if(islower(a)&&islower(b)){
		for(x=a+1;x<b;x++){
			printf("%c",x);
		}
	}else if(isupper(a)&&isupper(b)){
		for(x=a+1;x<b;x++){
			printf("%c",x);
		}
	}else if(isdigit(a)&&isdigit(b)){
		for(x=a+1;x<b;x++){
			printf("%c",x);
		}
	}else{
		printf("-");
	}
}
int main(){
	char s[1000];
	scanf("%s",s);
	int len=strlen(s);
	int i;
	for(i=0;i<len;i++){
		if(s[i]=='-'){
			expand(s[i-1],s[i+1]);
		}else{
			printf("%c",s[i]);
		}
	}
	return 0;
}




