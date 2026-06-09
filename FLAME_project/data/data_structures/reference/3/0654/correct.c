#include<stdio.h>
#include<string.h>
char str[105];
int k,r;
int main(){
	gets(str);
	int len=strlen(str);
	int i;
	for(i=0;i<len;i++){
		if(str[i]=='.') {
		k=i;//k为小数点所在位置
		break;} 
	}
	for(i=0;i<len;i++){
		if(str[i]!='0'&& str[i]!='.'){
		r=i;//r为首位非零位置 
		break; 	
		} 
	}
	printf("%c",str[r]);
	if(r<len-1) printf(".");
	for(i=r+1;i<=len-1;i++){
		if(str[i]!='.') printf("%c",str[i]);
	}
	printf("e");
	if(str[0]>='1')
	printf("%d",k-r-1);
	else printf("%d",k-r);
}



