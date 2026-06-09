#include <stdio.h>

int detect(char a,char b){
	if((a>='a'&&a<='z')&&(b>='a'&&b<='z')&&a<b) return 1;
	else if((a>='A'&&a<='Z')&&(b>='A'&&b<='Z')&&a<b) return 1;
	else if((a>='0'&&a<='9')&&(b>='0'&&b<='9')&&a<b) return 1;
	else return 0;
}

int main(){
	char s[200];
	gets(s);
	int i;
	for(i=0;s[i]!='\0';i++){
		if(s[i]=='-'){
			if(detect(s[i-1],s[i+1])){
				int j;
				for(j=1;s[i-1]+j<s[i+1];j++)
				printf("%c",s[i-1]+j);
			}
			else printf("%c",s[i]);
		}
		else printf("%c",s[i]);
	}
	return 0;
}



