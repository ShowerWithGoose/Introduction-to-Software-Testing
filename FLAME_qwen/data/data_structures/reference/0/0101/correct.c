#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
	char A[100]={},B[200]={};
	int i,j,n=0,s=0;
	gets(A);
	for(i=0;i<strlen(A);i++){
		if(A[i]!='-'||i==0)
			B[n++]=A[i];
		if(A[i]=='-'&&i!=0){
			if(A[i-1]<A[i+1]&&islower(A[i-1])&&islower(A[i+1])){
				s=1;
				for(j=1;j<A[i+1]-A[i-1];j++)
					B[n++]=A[i-1]+j;
			}
			else if(A[i-1]<A[i+1]&&isupper(A[i-1])&&isupper(A[i+1])){
				s=1;
				for(j=1;j<A[i+1]-A[i-1];j++)
					B[n++]=A[i-1]+j;
			}
			else if(A[i-1]<A[i+1]&&isdigit(A[i-1])&&isdigit(A[i+1])){
				s=1;
				for(j=1;j<A[i+1]-A[i-1];j++)
					B[n++]=A[i-1]+j;
			}
			if(s!=1)
				B[n++]='-';
			s=0;
		}
	}
	fputs(B,stdout);
	return 1;
}


