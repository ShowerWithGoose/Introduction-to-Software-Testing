#include <stdio.h>
#include <string.h>
int main() {
	char a,b,s[10000]={'\0'};
	int i=0;
	scanf("%s",s);
	int l=strlen(s);
	for(i=0;i<l;i++){
		if(s[i]=='-'){
			if(s[i-1]>='a' && s[i+1]<='z' && s[i+1]>s[i-1]){
				for(b=s[i-1]+1;b<s[i+1];b++){
					printf("%c",b);
				}
			}
			else if(s[i-1]>='A' && s[i+1]<='Z' && s[i+1]>s[i-1]){
				for(b=s[i-1]+1;b<s[i+1];b++){
					printf("%c",b);
				}
			}
			else if(s[i-1]>='0' && s[i+1]<='9' && s[i+1]>s[i-1]){
				for(b=s[i-1]+1;b<s[i+1];b++){
					printf("%c",b);
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
	printf("\n");
	return 0;
}


