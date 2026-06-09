#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int main(){
	char str[100];
	gets(str);
	
	char *pointLoc,*firstNumLoc=str;
//	printf("%c\n",*firstNumLoc);
	pointLoc=strchr(str,'.');
	if(pointLoc==NULL){
		pointLoc=str+strlen(str);
	}
	for(;*firstNumLoc!='\0';firstNumLoc++){
		if(isdigit(*firstNumLoc)&&*firstNumLoc!='0')
			break;
	}
	if(*firstNumLoc=='\0'){
		puts("0");
		return 0;
	}
	
	for(char *temp=firstNumLoc;*temp!='\0';temp++){
		if(isdigit(*temp))
			printf("%c",*temp);
		if(temp==firstNumLoc&&temp[1]!='\0')
			printf(".");
	}
	if(pointLoc-firstNumLoc-1>=0){
		printf("e%d",pointLoc-firstNumLoc-1);
	}else{
		printf("e%d",pointLoc-firstNumLoc);
	}
	return 0;
}

