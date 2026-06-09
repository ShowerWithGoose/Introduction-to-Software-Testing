#include <stdio.h>
#include <string.h>
int Check(char *p){
	int i=0;
	for(i=0;p[i]!='\0';i++){
		if(p[i]=='.'){
			return i;
		}
	}
	return 0;
}
int main(){
	char ch[1000]={0};
	gets(ch);
	int x=strlen(ch);
	int C=Check(ch);
	int i=0,j=0,k=0;
	int number=0;
	if(!C){
		if(x==1){
			printf("%ce0",ch[0]);
		}else{
			printf("%c.",ch[0]);
			for(i=1;ch[i]!='\0';i++){
				printf("%c",ch[i]);
			}
			printf("e%d",x-1);
		}
	}else{
		if(ch[0]=='0'){
			for(j=2;ch[j]=='0';j++);
			printf("%c",ch[j]);
			number=j;
			j++;
			if(ch[j]!='\0')printf(".");
			while(ch[j]!='\0'){
				printf("%c",ch[j]);
				j++;
			}
			printf("e-%d",number-1);
		}else{
			printf("%c.",ch[k]);
			k++;
			while(ch[k]!='\0'){
				if(ch[k]!='.'){
					printf("%c",ch[k]);
				}
				k++;
			}
			printf("e%d",C-1);
		}
	}
}

