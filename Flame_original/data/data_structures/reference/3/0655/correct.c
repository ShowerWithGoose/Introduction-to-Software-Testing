#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#define Arraynum(x) (sizeof(x)/sizeof(x[0]))
int main(){
	int i,j,k,flag=0,t=0;
	char a[1001],b[1001];
	gets(a);
	int len =strlen (a);
	for(i=0,j=0;i<len;i++){
		if(a[0]=='-') {
			printf("-");
			i++;
		}
		if(a[i]=='.') {
			flag=1;
			i++;
			if(t==1) k=i-2;
		}
		if(flag==0){
			b[j++]=a[i];
			if(a[i]>'0') t=1;
		}
		else if(flag==1){
			b[j++]=a[i];
		}
	}
	b[j]='\0';
	len=strlen (b);
	for(i=len-1;i>=0;i--){
		if(b[i]=='0') len--;
		else break;
	}
	if(t==1){
		for(i=0;i<len;i++){
			printf("%c",b[i]);
			if(i==0){
				if(len==1){
					printf("e0");
					return 0;
				}
				else{
					printf(".");
				}
			}
		}
		printf("e%d",k);
	}
	else {
		for(i=0,flag=0,j=0,t=0;i<len;i++){
			if(b[i]=='0'&&flag==0){
				j++;
			}
			else{
				t++;
				flag=1;
				printf("%c",b[i]);
				if(t==1&&i+1<len) printf(".");
			}
		}
		printf("e-%d",j);
	}
	getchar();getchar();
    return 0;
}


