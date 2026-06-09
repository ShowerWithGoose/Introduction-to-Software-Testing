#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main() {
	char ch[200];
	int j=0;
	int flag=0;
	gets(ch);
	if(ch[0]=='0') {
		for(int i=2;i<strlen(ch);i++) {
			if(ch[i]=='0') {
				j++;
			}
			else break; 
		}
		printf("%c",ch[j+2]);
		if(ch[j+3]!='\0') printf(".");
		for(int k=j+1;k+2<strlen(ch);k++){
			printf("%c",ch[k+2]);	
		}
		printf("e-%d",j+1);
	}
	else {
		for(int i=0;i<strlen(ch);i++) {
			if(ch[i]!='.') {
				j++;
			}
			else break;
		}
		printf("%c",ch[0]);
		for(int k=1;k<strlen(ch)-1;k++) {
			if(ch[k]=='0') {
				flag++;
			}
		}
		if(flag!=strlen(ch)-1) {
			printf(".");
			for(int m=1;m<strlen(ch);m++) {
				if(ch[m]!='.') printf("%c",ch[m]);
			}
			printf("e%d",j-1);
		}
		else {
			printf("e%d",j-2);
			
		}
	}
	return 0;
	
}



