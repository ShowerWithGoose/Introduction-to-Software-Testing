#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int main(){
	char Cen[100];
	gets(Cen);
	
	char *dot1,*dot2=Cen;
//	printf("%c\n",*firstNumLoc);
	dot1=strchr(Cen,'.');
	if(dot1==NULL){
		dot1=Cen+strlen(Cen);
	}
	for(;*dot2!='\0';dot2++){
		if(isdigit(*dot2)&&*dot2!='0')
			break;
	}
	if(*dot2=='\0'){
		puts("0");
		return 0;
	}
	
	for(char *temp=dot2;*temp!='\0';temp++){
		if(isdigit(*temp))
			printf("%c",*temp);
		if(temp==dot2&&temp[1]!='\0')
			printf(".");
	}
	if(dot1-dot2-1>=0){
		printf("e%d",dot1-dot2-1);
	}else{
		printf("e%d",dot1-dot2);
	}
	return 0;
}

