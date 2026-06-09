#include<stdio.h>
#include<string.h>
int putt(char a,char b){
	if(a>='a'&&a<='z'){
		if(b>=a&&b<='z'){
			while(a<b-1){
				a=a+1;
				printf("%c",a);
			}
		}else{
			printf("-");
		}
	}else
	if(a>='A'&&a<='Z'){
		if(b>=a&&b<='Z'){
			while(a<b-1){
				a=a+1;
				printf("%c",a);
			}
		}else{
			printf("-");
		}
	}else
	if(a>='0'&&a<='9'){
		if(b>=a&&b<='9'){
			while(a<b-1){
				a=a+1;
				printf("%c",a);
			}
		}else{
			printf("-");
		}
	}
	return 0;
} 
int main(){
	char str[1000];
	gets(str);
	int i=0;
	while(i<strlen(str)){
		if(str[i]!='-'){
			printf("%c",str[i]);
			i++;
		}else if(str[i]=='-'){
			putt(str[i-1],str[i+1]);
			i=i+1;
		}
	}
	
	return 0;
} 

