#include <stdio.h>
#include <string.h>
int main(){
	char ch1,ch2;
	char s[100];
	gets(s);
	int k;
	int i;
	for(k=0;k<strlen(s)-1;k++){
		if(s[k]=='-'){
			ch1=s[k-1];
			ch2=s[k+1];
			if(ch1>='a'&&ch2<='z'&&ch1<ch2){
				for(i=1;i<ch2-ch1;i++){
					printf("%c",ch1+i);
				}
			}
			else if(ch1>='0'&&ch2<='9'&&ch1<ch2){
				for(i=1;i<ch2-ch1;i++){
					printf("%c",ch1+i);
				}
			}
			else if(ch1>='A'&&ch2<='Z'&&ch1<ch2){
				for(i=1;i<ch2-ch1;i++){
					printf("%c",ch1+i);
				}
			}
			else{
				printf("-");
			}
		}
		else{
			printf("%c",s[k]);
		}
	}
	printf("%c",s[k]);
} 



