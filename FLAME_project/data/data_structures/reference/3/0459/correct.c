#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main() {
	char a[1000];
	int k1=0,k2=0;
	gets(a);
	for(int i=0;i<strlen(a);i++){
		if(a[i]!='.'){
			k1++;
		}else{
			break;
		}
	}
	if(a[0]!='0'&&k1==1){
		for(int i=0;i<strlen(a);i++){
			printf("%c",a[i]);
		}
		printf("e0");
		return 0;
	}
	if(a[0]=='0'){
		for(int i=2;a[i]=='0';i++){
			k1++;
		}
		printf("%c",a[k1+1]);
		for(int i=k1+2;i<strlen(a);i++){
			if(i==(k1+2)){
				printf(".");
			}
			printf("%c",a[i]);
		}
		printf("e-%d",k1);
		return 0;
	}
	printf("%c.",a[0]);
	for(int i=1;i<strlen(a);i++){
		if(a[i]!='.'){
			printf("%c",a[i]);
		}
	}
	printf("e%d",k1-1);
	return 0;
}
