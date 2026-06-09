#include<stdio.h>
#include<string.h>
#include<math.h>
char s[210000],a[10000],b[200];
int main(){	
	gets(s);
	int i,j,k,l=1,f=0,m,n,nu,num=1,numb=0;
	for(i=0,j=0;i<strlen(s);i++){
		if(s[i]!=' ')
		s[j++]=s[i];	
	} 
	s[j]='\0';
	
	for(k=0;k<j;k++){
		
		if(k-1<0) f=1;
		else{
			if(s[k-1]=='+') f=1;
			if(s[k-1]=='-') f=2;
		}
		if(s[k]!='+'&&s[k]!='-'&&s[k]!='='){
			a[l++]=s[k];
		}
		else{
			m=1;
			B:
			n=0;    nu=0;
			for(;a[m]!='*'&&a[m]!='/'&&m<l;m++){
				b[n++]=a[m];
			
			}	
			
			for(i=0;i<n;i++){
				nu*=10;
				nu+=(b[i]-'0');
			}
		
			if(a[m-n-1]=='/')
			num/=nu;
			else
			num*=nu;
		
			if(m==l){
				l=1;
				goto A;
			}
			else{
				m++;
				goto B;
			}
			A:
			if(f==2){
			numb-=num; f=0;}
			if(f==1){
			numb+=num; f=0;}
			num=1;		
		}
	
	}
	printf("%d",numb);
	return 0;
} 

