#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
	char s[100];
	scanf("%s",s);
	int i;
	for(i=0;i<strlen(s);i++){
		if(s[i]=='-'){
			if(isdigit(s[i-1])&&isdigit(s[i+1])){
				int k=1;
				while(s[i-1]+k<s[i+1]){
				printf("%c",s[i-1]+k);
				k++;
				}
				continue;
			}
			if(islower(s[i-1])&&islower(s[i+1])){
				int k=1;
				while(s[i-1]+k<s[i+1]){
				printf("%c",s[i-1]+k);
				k++;
				}
				continue;
			}
			if(isupper(s[i-1])&&isupper(s[i+1])){
				int k=1;
				while(s[i-1]+k<s[i+1]){
				printf("%c",s[i-1]+k);
				k++;
				}
				continue;
			}
		}
		printf("%c",s[i]);
	}
	return 0;
}



