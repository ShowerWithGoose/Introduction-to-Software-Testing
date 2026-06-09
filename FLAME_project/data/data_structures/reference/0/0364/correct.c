#include<stdio.h>
#include<string.h>

int main(){
	char s[1000],kuo[2000];
	gets(s);
	int len=strlen(s);
	int cnt=0;
	for(int i=0;i<len;i++){
		if(s[i-1]>='a'&&s[i-1]<='z'&&s[i]=='-'&&s[i+1]>='a'&&s[i+1]<='z'&&s[i+1]-s[i-1]>0){
			for(int j=1;j<s[i+1]-s[i-1];j++){
				printf("%c",s[i-1]+j);
			}
		}
		else if(s[i-1]>='A'&&s[i-1]<='Z'&&s[i]=='-'&&s[i+1]>='A'&&s[i+1]<='Z'&&s[i+1]-s[i-1]>0){
			for(int j=1;j<s[i+1]-s[i-1];j++){
				printf("%c",s[i-1]+j);
			}
		}
		else if(s[i-1]>='0'&&s[i-1]<='9'&&s[i]=='-'&&s[i+1]>='0'&&s[i+1]<='9'&&s[i+1]-s[i-1]>0){
			for(int j=1;j<s[i+1]-s[i-1];j++){
				printf("%c",s[i-1]+j);
			}
		}
		else
			printf("%c",s[i]);
	}
	
	return 0;
} 



