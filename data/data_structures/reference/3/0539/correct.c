#include<stdio.h>
#include<string.h>
int main(){
	int i,j,k,m,n,l;
	char a[105]={};
	gets(a);
	n=strlen(a);
	for(i=0;a[i]!='.';i++){
	;}
	if(i==1){
		if(a[0]!='0'){
			for(l=0;l<n;l++){
				printf("%c",a[l]);
			}
			printf("e0");
		}
		else{
			for(j=2;a[j]=='0';j++){
			;}
			k=j;
			if(k==n-1){
				printf("%c",a[j]);
			}
			else printf("%c.",a[j]);
			for(j=j+1;j<n;j++){
				printf("%c",a[j]);
			}
			printf("e-%d",k-1);
		}
	}
	else{
		for(m=0;m<n;m++){
			if(m==i) continue;
			printf("%c",a[m]);
			if(m==0) printf(".");
		}
		printf("e%d",i-1);
	}
	return 0;
} 



