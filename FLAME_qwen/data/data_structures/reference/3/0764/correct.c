#include<stdio.h>
#include<string.h> 
int main(){
	char s[101]={"0"};
	int d,c;
	gets(s);
	for(int i=0;i<strlen(s);i++){
		if(s[i]=='.'){
		d=i;
		break;
	}
	}
	if(s[0]-'0'>0){
		
		printf("%c.",s[0]);
		for(int i=1;i<d;i++){
			printf("%c",s[i]);
		}
		for(int i=d+1;i<strlen(s);i++){
			printf("%c",s[i]);
		}
		printf("e%d",d-1);
	}
	else{
		for(int i=d+1;i<strlen(s);i++){
			if(s[i]!='0'){
				c=i;
				printf("%c",s[i]);
				break;
			}
		}
		if(strlen(s)-c!=1){
			printf(".");
		}
	for(int i=c+1;i<strlen(s);i++){
		printf("%c",s[i]);
	}
		printf("e-%d",c-d);
	}
	return 0;
}

