#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(){
	char s[150];
	gets(s);
	int f;
	for(int i=0;i<strlen(s);i++){if(s[i]=='.') f=i;}
	if(f==1){
		if(s[0]=='0'){
		int fei;
		for(int i=0;i<strlen(s);i++){if(s[i]>'0'&&s[i]<='9') {fei=i;break;}}	
		if(fei==strlen(s)-1){
			printf("%ce%d",s[fei],f-fei);
		}	
		else {
			printf("%c.",s[fei]);
			for(int i=fei+1;i<strlen(s);i++){printf("%c",s[i]);}
			printf("e%d",f-fei);
		}	
		}
		else {
        for(int i=0;i<strlen(s);i++){printf("%c",s[i]);}
		printf("e0"); 	
		}	
	}
	else{
		printf("%c.",s[0]);
		for(int i=1;i<strlen(s);i++){
			if(s[i]!='.') printf("%c",s[i]);
		}
		printf("e%d",f-1);
	}
	return 0;
}

