#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
	char A[2000]={},C[1000]={},c;
	int B[1000]={},D[1000]={};
	int i,j,k,n=0,n1=0,n2=0,n3=0,n4=0;
	int t=0,t1=0,t2=0,b,p;
	for(;(c=getchar())!='=';){
		if(c==' ')
			continue;
		A[n1++]=c;
	}
	A[n1]='=';
	for(i=0;i<strlen(A);i++){
		if(isdigit(A[i])){
			t++;
		}
		else{
			for(j=0;j<t;j++){
				b=A[i-t+j]-'0';
				for(k=1;k<t-j;k++){
					b*=10;
				}
				B[n2]+=b;
				b=0;
			}
			n2++;
			C[n3++]=A[i];
			t=0;
		}
	}
	for(i=0;i<n3;i++){
		if(C[i]=='*'){
			t1++;
		}
		else if(C[i]=='/'){
			t2++;
		}
		else{
			if(t1!=0&&t2!=0){
				b=B[i-t1-t2];
				D[n4++]=i-t1-t2;
				for(j=0;j<t1+t2;j++){
					if(C[i-t1-t2+j]=='*')
						b*=B[i-t1-t2+j+1];
					else
						b/=B[i-t1-t2+j+1];
					B[i-t1-t2+j+1]=0;
				}
				B[i-t1-t2]=b;
				b=0;
				t1=t2=0;
				for(j=0;j<t1+t2;j++){
					C[i-t1-t2+j]='0';
				}
			}
			else if(t1!=0){
				b=B[i-t1];
				D[n4++]=i-t1;
				for(j=0;j<t1;j++){
					b*=B[i-t1+j+1];
					B[i-t1+j+1]=0;
				}
				B[i-t1]=b;
				b=0;
				t1=0;
				for(j=0;j<t1;j++){
					C[i-t1+j]='0';
				}
			}
			else if(t2!=0){
				b=B[i-t2];
				D[n4++]=i-t2;
				for(j=0;j<t2;j++){
					b/=B[i-t2+j+1];
					B[i-t2+j+1]=0;
				}
				B[i-t2]=b;
				b=0;
				t2=0;
				for(j=0;j<t2;j++){
					C[i-t2+j]='0';
				}
			}
			else 
				continue;		
		}
	}
	p=B[0];
	for(i=0;i<n3;i++){
		if(C[i]=='0')
			continue;
		if(C[i]=='-'){
			if(C[i+1]=='0')
				p-=B[D[n++]];
			else
				p-=B[i+1];
		}
		if(C[i]=='+'){
			if(C[i+1]=='0')
				p+=B[D[n++]];
			else
				p+=B[i+1];
		}
	}
	printf("%d",p);
	return 1;
}


