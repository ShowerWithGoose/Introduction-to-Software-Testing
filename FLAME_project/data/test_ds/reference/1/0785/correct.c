#include<stdio.h>
#include <math.h> //数学公式
#include <stdlib.h> //快排和malloc
#include <ctype.h> //字符处理函数
#include <string.h> //字符串函数
#define ll long long
#define eps 1e-6
#define MAX 1000005
int main(){
	int i=0;
	char str[50000]="";
	scanf("%s",str);
	while (str[i]!='\0'){
	if(str[i]=='-') {
	if(isupper(str[i-1])&&isupper(str[i+1])&&str[i+1]>str[i-1]){	
		int j=str[i+1]-str[i-1];
		for(int k=1;k<j;k++){
			printf("%c",str[i-1]+k);
		}
	}
	else if(islower(str[i-1])&&islower(str[i+1])&&str[i+1]>str[i-1]){
		int j=str[i+1]-str[i-1];
		for(int k=1;k<j;k++){
			printf("%c",str[i-1]+k);
		}
	}
	else if(isdigit(str[i-1])&&isdigit(str[i+1])&&str[i+1]>str[i-1]){
		int j=str[i+1]-str[i-1];
		for(int k=1;k<j;k++){
			printf("%c",str[i-1]+k);
		}
	}
	else printf("-"); 
	}
	if(str[i]!='-') printf("%c",str[i]);
	i++;
	}
	
	return 0;
}


