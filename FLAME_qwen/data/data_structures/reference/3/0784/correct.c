#include<stdio.h>
#include<string.h>
char ch[101];
int main(){
	gets(ch);
	int len=strlen(ch),n,num1,num2;
	for(int i=0;i<len;i++){
		if(ch[i]=='.')
			n=i;//
		if(ch[i]!='.'&&ch[i]!='0')
			num2=i; 
	}
	for(int i=0;i<len;i++){
		if(ch[i]!='.'&&ch[i]!='0'){
			num1=i;
			break;
		}
	}
	if(num1==num2){
		printf("%ce%d",ch[num1],num1>n?n-num1:n-num1-1);
	}
	else{
		for(int i=num1;i<=num2;i++){
			if(ch[i]!='.')
				printf("%c",ch[i]);
			if(i==num1)
				printf(".");
		}
		printf("e%d",num1>n?n-num1:n-num1-1);
	}
	return 0;
}

