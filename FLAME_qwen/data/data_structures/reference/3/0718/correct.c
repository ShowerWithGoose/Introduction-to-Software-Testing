#include<stdio.h>
#include<string.h>
char a[1000]={};
int main(){
	scanf("%s",a);
	int l=strlen(a);
	int i;
	int dot=-1,first=-1;
	for(i=0;i<l;i++){
		if(a[i]>'0'&&first==-1)first=i;
		if(a[i]=='.'&&dot==-1)dot=i;
	}
	if(first<dot){
		printf("%c.",a[first]);
		for(i=1;i<l;i++){
			if(a[i]!='.')printf("%c",a[i]);
		}
		printf("e%d",dot-1);
	}
	else if(first>dot){
		printf("%c",a[first]);
		if(first!=l-1)printf(".");
		for(i=first+1;i<l;i++){
			printf("%c",a[i]);
		}
		printf("e-%d",first-dot);
	}
	return 0;
} 

