#include <stdio.h>
int main(){
	char ch[105];
	int i,j;
	gets(ch);
	if(ch[0]=='0'){
		i=2;
		while(ch[i]=='0'){
			i++;
		}
		for(j=i;ch[j]!='\0';j++){
			printf("%c",ch[j]);
			if(j==i&&ch[j+1]!='\0'){
				printf(".");
			}
		}
		printf("e-%d",i-1);
	}else{
		if(strlen(ch)==1){
			printf("%ce0",ch[0]);
			return 0;
		}
		i=1;
		while(ch[i]!='.'&&ch[i]!='\0'){
			i++;
		}
		for(j=0;ch[j]!='\0';j++){
			if(ch[j]!='.'){
				printf("%c",ch[j]);
			}
			if(j==0){
				printf(".");
			}
		}
		printf("e%d",i-1);
	}
	return 0;
}



