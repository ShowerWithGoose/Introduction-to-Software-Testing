#include<stdio.h>
#include<string.h>
int main(){
	char A[105];
	int a[105], i, m;
	gets(A);
	a[0]=A[0]-'0';
	if(a[0]<10 && a[0]>0 && A[1]=='.'){
		for(i=0;i<strlen(A);i++){
			printf("%c",A[i]);
		}
		printf("e0");
	}
	else if(a[0]==0){
		i=2;
		while(A[i]=='0'){
			i++;
		}
		m=i;
		printf("%c",A[m]);
		if(A[m+1]!='0' && A[m+1]!='\0') printf(".");
		for(i=m+1;i<strlen(A);i++){
			printf("%c",A[i]);
		}
		printf("e-");
		printf("%d",m-1);
	}
	else if(A[1]!='.'){
		printf("%d",a[0]);
		
		i=0;
		while(A[i]!='.'){
			i++;
		}
		m=i;
		if(m<strlen(A)) {
		printf(".");
		for(i=1;i<m;i++){
			printf("%c",A[i]);
		}
		for(i=m+1;i<strlen(A);i++){
			printf("%c",A[i]);
		}} 
		if(m==strlen(A)){
		for(i=1;i<strlen(A);i++){
			printf("%c",A[i]);
		}}
		printf("e");
		printf("%d",m-1);
	}
	return 0;
}



