#include<stdio.h>
#include<stdlib.h>
#include<string.h>
	char A[100], B[100], c[100], D[100], E[100];
	int i=0, j=0, h=0, k=0, s[100], m[100];
int main(){
	
	gets(A);//读取算式
	for(i=0;i<strlen(A);i++){
		if(A[i]!=" "){
			B[j]=A[i];
			j++;
		}
	}//去除空格
	for(i=0;i<strlen(B);i++){
		if(B[i]=='+'||B[i]=='-'||B[i]=='*'||B[i]=='/'||B[i]=='='){
			D[h]=B[i];
			h++;
		if(B[i]=='+'||B[i]=='-'||B[i]=='='){
			E[k]=B[i];
			k++;
		}
		}
	}//记录所有运算符的次序
	j=0;
	h=0;
	k=0;
	for(i=0;i<strlen(B);i++){
		c[j]=B[i];
		j++;
		if(B[i+1]=='+'||B[i+1]=='-'||B[i+1]=='*'||B[i+1]=='/'||B[i+1]=='='){
			s[h]=atoi(c);
			memset(c,0,sizeof(c)/sizeof(char));
			j=0;
			h++;
		}
		if(B[i]=='+'||B[i]=='-'||B[i]=='*'||B[i]=='/'||B[i]=='='){
			c[0]='\0';
			j=0;
		}
	}//储存所有的数字
	for(i=0;i<strlen(D);i++){
		if(D[i]=='*') s[i+1]=s[i+1]*s[i];
		if(D[i]=='/') s[i+1]=s[i]/s[i+1];
		if(D[i]=='+'||D[i]=='-'||D[i]=='='){
			m[k]=s[i];
			k++;
		}
	}//将所有乘法除法运算过后的数字储存到一个数组里
	for(i=0;i<=k;i++){
		if(E[i]=='+') m[i+1]=m[i]+m[i+1];
		if(E[i]=='-') m[i+1]=m[i]-m[i+1];
		if(E[i]=='=') printf("%d",m[i]);
	}
	return 0;
}


