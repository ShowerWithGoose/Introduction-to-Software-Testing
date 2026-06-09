#include<stdio.h>

int main(){
	char a[101],b[101];
	int i,j,k,n,m,l,p,e;
	gets(a);
	for(n=0;a[n]=='0'||a[n]=='.';n++);
	for(m=0;a[m]!='.';m++);
	e=m>n?m-n-1:m-n;
	for(l=0;a[l]!='\0';l++);
	for(p=l-1;a[p]=='0'||a[p]=='.';p--);
	b[0]=a[n];
	if(n!=p){
		b[1]='.';	
		for(i=2,j=n+1;j<=p;){
		if(a[j]=='.'){
			j++;
			continue;
		}
		b[i++]=a[j++];
		}
	}
	else b[1]='\0';
	printf("%se%d",b,e);
	return 0;
} 

