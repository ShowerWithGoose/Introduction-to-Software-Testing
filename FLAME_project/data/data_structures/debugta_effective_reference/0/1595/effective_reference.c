#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main(){
	char str[100];
	char n;
	int i,len;
	scanf("%s",str);
	len=strlen(str);
	for(i=0;i<strlen(str);i++){
		if(i==len-1||str[i+1]!='-'){
			printf("%c",str[i]);
		}
		else{
			if(str[i]<str[i+2]&&((islower(str[i])&&islower(str[i+2]))||(isupper(str[i])&&isupper(str[i+2]))||(isdigit(str[i])&&isdigit(str[i+2])))){
			
	            for(n=str[i];n<str[i+2];n++){
	            	printf("%c",n);
				}
				i++;
			
		    }
			else{
				printf("%c",str[i]);
			
			}
		}
	}
}

