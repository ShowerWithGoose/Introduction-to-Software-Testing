#include<stdio.h>
#include<string.h>
int main(){
	char A[200]={},B[200]={};
	int i,j,k;
	int t=0,s=0,n=0;
	gets(A);
	if(A[0]!='0'){
		B[0]=A[0];
		B[1]='.';
		n=2;
		for(i=1;i<strlen(A);i++){
			if(A[i]!='.'&&s==0)
				t++;
			if(A[i]=='.')
				s=1;
			if(A[i]!='.')
				B[n++]=A[i];	
		}
	}
	else{
		for(i=2;i<strlen(A);i++){
			if(A[i]=='0'&&s==0)
				t++;				
			if(A[i]!='0'&&s!=2)
				s=1;
			if(s==1)
				B[0]=A[i];
			if(i+1<strlen(A)&&s==1){
				B[1]='.';
				s=2;
				n=2;
				continue;
			}
			if(s==2){
				B[n++]=A[i];	
			}	
		}
		t++;
	}
	if(A[0]!='0')
		printf("%se%d",B,t);
	else
		printf("%se%d",B,-t);	
}


