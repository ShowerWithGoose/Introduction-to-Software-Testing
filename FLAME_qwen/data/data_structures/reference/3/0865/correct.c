#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
int main(){
	char a[1005];
	gets(a);
	int i,len,dotp,num,nop,f=0;
	len=strlen(a);
	for(i=0;i<len;i++){
		if(a[i]=='.'){
			dotp=i;
		}
		if(a[i]!='0'&&a[i]!='.'&&f==0){
			nop=i;f=1;
		}
	}
	if(nop>dotp){
		printf("%c",a[nop]);
		if(len!=nop+1){
			printf(".");
			for(i=nop+1;i<len;i++){
				printf("%c",a[i]);
			}
		}
		printf("e%d",-(nop-dotp));
	}
	else{
		printf("%c.",a[0]);
		for(i=1;i<len;i++){
			if(a[i]!='.')
			printf("%c",a[i]);
		}
		printf("e%d",dotp-1);
	}
	return 0;
}


