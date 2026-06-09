#include<stdio.h>
int main(){
	char s[101];
	char a;
	gets(s);
	int i,j;
	for(i=0;s[i]!='\0';i++){
		if((s[i]=='-'&&s[i-1]>='a'&&s[i+1]<='z')||(s[i]=='-'&&s[i-1]>='A'&&s[i+1]<='Z')||(s[i]=='-'&&s[i-1]>='0'&&s[i+1]<='9')){
			for(j=1;j<s[i+1]-s[i-1];j++){
				printf("%c",s[i-1]+j);
			}
		}else{
			printf("%c",s[i]);
		}
	}
	return 0;
}

