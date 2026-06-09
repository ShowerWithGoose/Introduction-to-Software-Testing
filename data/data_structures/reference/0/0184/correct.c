#include<stdio.h>
#include<string.h>
int main(){
	char a[1000];
	int b[100];
	scanf("%s",a);
	int i,j,k=0,m,n;
	b[0]=0;
	for(i=1;i<strlen(a);i++){
		m=i-1;n=i+1;
		if(a[i]=='-'&&a[m]<a[n]&&((a[m]>='a'&&a[n]<='z')||(a[m]>='A'&&a[n]<='Z')||(a[m]>='0'&&a[n]<='9'))){
			for(j=b[k];j<i;j++) printf("%c",a[j]);
			for(j=1;j<a[n]-a[m];j++) printf("%c",j+a[m]); 
			k++;
			b[k]=n;
		}
	}
	for(j=b[k];j<strlen(a);j++) printf("%c",a[j]);
} 



