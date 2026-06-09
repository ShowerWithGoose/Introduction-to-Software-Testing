#include <stdio.h>
#include <string.h>
int main(){
	char s[10000],temp;
	int i; 
	gets(s);
	for(i=0;i<strlen(s);i++){
		if(s[i]!='-') 
			printf("%c",s[i]);
		else if(s[i]=='-'){
			if('a'<=s[i-1]&&s[i-1]<='z'&&'a'<=s[i+1]&&s[i+1]<='z'&&s[i-1]<s[i+1]){
				for(temp=s[i-1]+1;temp<s[i+1];temp++){
					printf("%c",temp);
				}
			}
			else if('A'<=s[i-1]&&s[i-1]<='Z'&&'A'<=s[i+1]&&s[i+1]<='Z'&&s[i-1]<s[i+1]){
				for(temp=s[i-1]+1;temp<s[i+1];temp++){
					printf("%c",temp);
				}
			}
			else if('0'<=s[i-1]&&s[i-1]<='9'&&'0'<=s[i+1]&&s[i+1]<='9'&&s[i-1]<s[i+1]){
				for(temp=s[i-1]+1;temp<s[i+1];temp++){
					printf("%c",temp);
				}
			}
			else printf("%c",'-');
	    }
	}
	return 0; 
}

