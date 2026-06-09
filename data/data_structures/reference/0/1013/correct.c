#include<stdio.h>
#include<string.h>
int main(){
	char s[1000];
	int i=0, h, j;
	gets(s);
	printf("%c",s[i]);
	for(i=1;s[i]!='\0';i++){
		if(s[i]=='-' && s[i-1]>='a' && s[i+1]<='z' && s[i-1]<s[i+1]){
			h=s[i+1]-s[i-1]-1;
			for(j=1;j<=h;j++){
				printf("%c",s[i-1]+j);
			}
		}
		else if(s[i]=='-' && s[i-1]>='A' && s[i+1]<='Z' && s[i-1]<s[i+1]){
			h=s[i+1]-s[i-1]-1;
			for(j=1;j<=h;j++){
				printf("%c",s[i-1]+j);
			}
		}
		else if(s[i]=='-' && s[i-1]>='0' && s[i+1]<='9' && s[i-1]<s[i+1]){
			h=s[i+1]-s[i-1]-1;
			for(j=1;j<=h;j++){
				printf("%c",s[i-1]+j);
			}}
		else printf("%c",s[i]);
	}
	return 0;
}



