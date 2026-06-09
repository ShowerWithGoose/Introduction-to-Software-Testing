#include<stdio.h>
#include<string.h>
int main(){
	char s[110];
	scanf("%s",s);
	if(s[0]!='0'&&s[1]=='.'){
		printf("%se0",s);
		return 0;
	}
	if(s[0]=='0'){
		int i=2;
		while(s[i]=='0')i++;
		int pow=i-1;
		printf("%c",s[i]);
		i++;
		if(s[i]!='\0')printf(".");
		while(s[i]!='\0'){
			printf("%c",s[i]);
			i++;
		}
		printf("e%d",-pow);
		return 0;
	}
	int j=0;
	while(s[j]!='.'&&s[j]!='\0')j++;
	int pow=j-1;
	if(s[j]=='\0'){
		printf("%c.",s[0]);
		for(j=1;s[j]!='\0';j++){
			printf("%c",s[j]);
        }			
		printf("e%d",pow);
		return 0;
	}
	printf("%c.",s[0]);
	for(j=1;s[j]!='\0';j++){
		if(s[j]!='.')printf("%c",s[j]);
	}
	printf("e%d",pow);
	return 0;
}



