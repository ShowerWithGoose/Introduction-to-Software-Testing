#include<stdio.h>
#include<string.h>
char s[105],a[105];	int b[105];
int main(){
	int i=0,k=0,j=0,l=0,n=0,sum=0,cnta=0;
	gets(s);
	l=strlen(s);
	char r=' ';
	for(i=0,j=0;i<l;i++){
		if(s[i]!=r) s[j++]=s[i];
	}//去空格 
	s[j]='\0';
	l=strlen(s);
	for(i=0;i<l;i++){
		if(s[i]<48||s[i]>57&&s[i]!='='){
		a[k++]=s[i];
		}
	}//存符号（按顺序） 
	for(i=0;i<l-1;i++){
		if(s[i]>=48&&s[i]<=57){
		    b[n]=b[n]*10+s[i]-'0';
		}
		else{
			n++;
		}
	}//存数（按十进制）
	for(i=0;i<k;i++){
		if(a[i]=='*'){
			b[i+1]=b[i]*b[i+1];
			b[i]=-1;
		}
		else if(a[i]=='/'){
			b[i+1]=b[i]/b[i+1];
		    b[i]=-1;
		}
	}
	for(i=0,j=0;i<k;i++){
		if(a[i]!='*'&&a[i]!='/') {
			a[j++]=a[i];
			cnta++;	
		}
	}
	for(i=0,j=0;i<=n;i++){
		if(b[i]!=-1) 
		b[j++]=b[i];
	}
	sum=b[0];
	for(i=0;i<cnta;i++){
		if(a[i]=='+'){
			sum+=b[i+1];
		}
		else if(a[i]=='-'){
			sum-=b[i+1];
		} 
	} 
	printf("%d",sum);
	return 0;
}


