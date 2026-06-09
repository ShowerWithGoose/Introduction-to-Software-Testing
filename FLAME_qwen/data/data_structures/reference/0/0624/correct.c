#include<stdio.h>
#include<math.h>
#include<string.h>

char s[1000];

void expand(int i){
	int x=0;
	if('0'<=s[i-1]&&s[i-1]<s[i+1]&&s[i+1]<='9')x=1;
	if('a'<=s[i-1]&&s[i-1]<s[i+1]&&s[i+1]<='z')x=1;
	if('A'<=s[i-1]&&s[i-1]<s[i+1]&&s[i+1]<='Z')x=1;
	if(x){
		for(int j=s[i-1]+1;j<s[i+1];j++)
			printf("%c",j);
			return;
	}
	else printf("-");
	return;
}

int main(){
	scanf("%s",s);
	for(int i=0;i<strlen(s);i++){
		if(s[i]=='-')expand(i);
		else printf("%c",s[i]);
	}
	return 0;
} 

