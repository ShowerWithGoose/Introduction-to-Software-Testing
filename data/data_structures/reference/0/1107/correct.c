#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	char s[1000];
	int i,j;
	gets(s);
	for(i=0;i<=strlen(s)-1;i++){
		if(s[i]=='-'){
			if(i==0||i==strlen(s)) printf("%c",s[i]);
			else if(('0'<=s[i-1]&&s[i-1]<='9'&&'0'<=s[i+1]&&s[i+1]<='9')||('a'<=s[i-1]&&s[i-1]<='z'&&'a'<=s[i+1]&&s[i+1]<='z')||('A'<=s[i-1]&&s[i-1]<='Z'&&'A'<=s[i+1]&&s[i+1]<='Z'))
			for(j=1;j<s[i+1]-s[i-1];j++){
				printf("%c",s[i-1]+j);
			}
			else printf("%c",s[i]);
		}
		else printf("%c",s[i]);
	}
	return 0;
}



