#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
char s[10086];
int i=0;
int main(){
	scanf("%s",s);
	printf("%c",s[0]);
	for(i=1;i<strlen(s)-1;i++){
		if(s[i]=='-'){
			if(s[i-1]<s[i+1]&&'a'<=s[i-1]&&s[i+1]<='z'){
				int p=s[i-1];
				while(++p<s[i+1]){
					printf("%c",p);
				}
			}else if(s[i-1]<s[i+1]&&'A'<=s[i-1]&&s[i+1]<='Z'){
				int p=s[i-1];
				while(++p<s[i+1]){
					printf("%c",p);
				}
			}else if(s[i-1]<s[i+1]&&'0'<=s[i-1]&&s[i+1]<='9'){
				int p=s[i-1];
				while(++p<s[i+1]){
					printf("%c",p);
				}
			}else{
				printf("-");
			}
		}else{
			printf("%c",s[i]);
		}
	}
	return 0;
}

