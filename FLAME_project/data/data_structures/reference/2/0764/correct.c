#include<stdio.h>
#include<string.h>
int main(){
	char s[100]={"0"},a[100]={"0"},b[100]={"0"},m[100]={"0"};
	int j=0,k=0,d=0,l=0,e[100]={0},n[100]={0},p=0,q=0;
	gets(s);
	for(int i=0;i<strlen(s);i++){
		if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
		a[j++]=s[i];
		b[k++]='c';
		}
		else if(s[i]>='0'&&s[i]<='9')
		b[k++]=s[i];
		else if(s[i]=='='){
			j++;
			b[k++]='c';
		break;
	}
	}
	for(int i=0;i<k;i++){
		if(b[i]>='0'&&b[i]<='9')
			d=d*10+b[i]-'0';
		else if(b[i]=='c'){
			e[l++]=d;
			d=0;
		}
	}
	for(int i=0;i<j-1;i++){
		if(a[i]=='*'){
			e[i+1]=e[i]*e[i+1];
			a[i]=' ';
			e[i]=0;
		}
		else if(a[i]=='/'){
			e[i+1]=e[i]/e[i+1];
			a[i]=' ';
			e[i]=0;
		}
	}
	for(int i=0;i<j-1;i++){
		if(a[i]!=' ')
		m[p++]=a[i];
	}
		for(int i=0;i<l;i++){
		if(e[i]!=0)
		n[q++]=e[i];
	}
	d=n[0];
	for(int i=0;i<p;i++){
		if(m[i]=='+')
		d=d+n[i+1];
		else if(m[i]=='-')
		d=d-n[i+1];
	}
	printf("%d",d);
	return 0;
} 



