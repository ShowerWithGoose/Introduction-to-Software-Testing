#include<stdio.h>

char s[1000000];
int main(){
	scanf("%s",s);
	for(int i=0; s[i]!='\0'; i++){
		if(s[i]=='-'&&i>0&&s[i+1]!='\0'){
			if(('0'<=s[i-1]&&s[i+1]<='9')||('a'<=s[i-1]&&s[i+1]<='z')||('A'<=s[i-1]&&s[i+1]<='Z')){
				for(char j=s[i-1]+1; j<s[i+1]; j++)
					printf("%c",j);				
			}
			else printf("%c",s[i]);
		}
		else printf("%c",s[i]);
	}
	return 0;
}



