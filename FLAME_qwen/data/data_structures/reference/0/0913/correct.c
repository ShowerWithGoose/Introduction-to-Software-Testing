#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int main(){
	char s[500];
	gets(s);
	int lenth=strlen(s);
	for(int i=0;i<=lenth-1;i++){
		if(s[i]=='-'){
			if(s[i-1]<s[i+1]){
				if(s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>='0'&&s[i+1]<='9'){
					for(int j=s[i-1]+1;j<s[i+1];j++){
						printf("%c",j);
					}
				}
				else if(s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>='A'&&s[i+1]<='Z'){
					for(int j=s[i-1]+1;j<s[i+1];j++){
						printf("%c",j);
					}
				}
				else if(s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<='z'){
					for(int j=s[i-1]+1;j<s[i+1];j++){
						printf("%c",j);
					}
				}
				else{
					printf("%c",s[i]);
				}
			}
			else{
				printf("%c",s[i]);
			}
		}
		else{
			printf("%c",s[i]);
		}
	}
	
	return 0;
}




