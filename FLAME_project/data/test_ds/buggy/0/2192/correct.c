#include <stdio.h>
#include <string.h>

int main()  {           
	char s[100000]={"0"};
	gets(s);
	
	for(int i=0; i<strlen(s); i++){
		if(s[i+1]=='-'&& s[i]<s[i+2]){
			
			if(s[i]>='A' && s[i+2]<='Z'){
				for(i;s[i]<s[i+2];s[i]=s[i]+1){
					printf("%c",s[i]);}i=i+1;
			}
			else if(s[i]>='0' && s[i+2]<='9'){
				for(i;s[i]<s[i+2];s[i]=s[i]+1){
					printf("%c",s[i]);}i=i+1;
			}
			else if(s[i]>='a' && s[i+2]<='z'){
				for(i;s[i]<s[i+2];s[i]=s[i]+1){
					printf("%c",s[i]);}i=i+1;
			}
			else{
			printf("%c", s[i]);	}
		}
		else{
			printf("%c", s[i]);
		}
	}
	return 0;}

