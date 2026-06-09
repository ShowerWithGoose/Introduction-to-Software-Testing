#include<stdio.h>
#include<string.h>
int main(){
	char a[101]={'0'},b[101]={'0'};
	int i=0,j=0,l=0,n=0,m=0,k,p;
	scanf("%s",a);
	n=strlen(a);
	for(i=0;a[i]=='0'||a[i]=='.';i++){
		n-=1;
		if(a[i]=='.'){
			j=i;
		}
	}
	m=j-i;
	k=n-i;
	if(k==n){
		for(j=0;j<n;j++){
			if(a[j]=='.') p=j;
		}
	}
	if(n==1){
		printf("%ce%d",a[i],m);
	}
	else if(n>1&&m!=0&&k!=n){
		printf("%c.",a[i]);
		for(l=i+1;l<i+n;l++){
			printf("%c",a[l]);
		}
		printf("e%d",m);
	}
	else if(n>1&&m==0&&k!=n){
		printf("%c",a[i]);
		for(l=i+1;l<i+n;l++){
			printf("%c",a[l]);
		}
		printf("e%d",m);
	}
	else if(k==n){
		printf("%c.",a[0]);
		for(l=1;l<p;l++){
			printf("%c",a[l]);
			}
		for(l=p+1;l<k;l++){
			printf("%c",a[l]);
		}
		printf("e%d",p-1);	
	}
	return 0;
	
	
}

