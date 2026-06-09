#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
	char s[1000];
	gets(s);
	int i,j,k;
	for(i=0;i<strlen(s);i++){
		if(s[i]=='-'){
			if((isupper(s[i-1])&&isupper(s[i+1])&&s[i-1]-s[i+1]<0)||(islower(s[i-1])&&islower(s[i+1])&&s[i-1]-s[i+1]<0)||(isdigit(s[i-1])&&isdigit(s[i+1])&&s[i-1]-s[i+1]<0)){
				j=s[i+1]-s[i-1];
				for(k=1;k<j;k++) printf("%c",s[i-1]+k);
			}
			else printf("%c",s[i]);
		}
		else printf("%c",s[i]);
	}
	return 0;		
} 

