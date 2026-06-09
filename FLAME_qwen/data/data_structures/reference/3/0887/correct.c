#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int main(){
	char a[100]={0};
	int i,j,x[100]={0},p=0,po=0,sw=0,m,len;
	for(i=0;i<99;i++){
		a[i]='a';
	}
	gets(a);
	for(i=0;a[i]!='a';i++){
		if(a[i]!='0'&&a[i]!='.'&&sw==0){
			p=i;
			sw++;
		}
		if(a[i]=='.'){
			po=i;
		}
		len=i;
	}if(po==0){
		po=i-1;
	}
	for(i=0,j=0,sw=0;i<len+1;i++){
		if(a[i]!='0'&&a[i]!='.'){
			sw++;
		}
		if(a[i]!='.'&&sw!=0){
			x[j]=a[i]-'0';
			j++;
		}
	}
	if(po>p){
		m=po-p-1;
	}
	else{
		m=po-p;
	}
	for(i=0;i<j;i++){
		if(i==0){
			printf("%d",x[i]);
		}
		else if(i==1&&x[i]>=0&&x[i]<=9){
			printf(".");
		}
		else if(i>=2){
			printf("%d",x[i-1]);
		}
	}
	printf("e");
	printf("%d",m);
	return 0;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
}

