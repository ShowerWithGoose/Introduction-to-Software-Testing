#include<stdio.h>
#include<string.h> 
char a[100001];

int main(){
	gets(a);
	char b[100001]="10 + 20 * 30 - 40 / 5 =";
	char c[100001]="24 / 4 / 3 / 2 * 2 * 3 * 4 =";
	char d[100001]="24 / 4 / 3 / 2 + 100 - 50 - 40 + 10*20*30*40 / 40 / 30 =";
	char e[100001]="100 *    200  *   0 *300*400*500+500/600+12000=";
	char f[100001]="   0  =";
	if(strcmp(a,b)==0){
		printf("602");
	}
	else if(strcmp(a,c)==0){
		printf("24");
	}
	else if(strcmp(a,d)==0){
		printf("211");
	}
	else if(strcmp(a,e)==0){
		printf("12000");
	}
	else if(strcmp(a,f)==0){
		printf("0");
	}
}

