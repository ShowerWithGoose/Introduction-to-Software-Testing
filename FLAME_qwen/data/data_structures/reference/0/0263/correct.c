#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int main(){
	char str[1000];//ÊäÈë×Ö·û´®
	int i=0,j;
	gets(str);
	for(i=0;i<strlen(str);i++){
		if(str[i]=='-'){
			if((str[i-1]<str[i+1])&&(((str[i-1]>='a')&&(str[i+1]<='z'))||((str[i-1]>='A')&&(str[i+1]<='Z'))||((str[i-1]>='0')&&(str[i+1]<='9')))){
				for(j=str[i-1];j<str[i+1]-1;j++){
				printf("%c",j+1);}}
			else
				printf("%c",str[i]);}
		else
			printf("%c",str[i]);
	}
	return 0; 
} 

