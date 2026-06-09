#include<stdio.h>
#include<string.h>
#include<ctype.h>

char a[1000];
int m,n,len,temp;

int dian(){
	int i;
	for(i=0;a[i]!='.'&&a[i]!='\0';i++);
	return i;
}

int feiling(){
	int i;
	for(i=0;a[i]!='\0';i++){
		if(a[i]>'0'&&a[i]<='9') return i;
	}
	return i;
}

int main(){
	int j=0;
	scanf("%s",a);
	m = dian();
	n = feiling();
	if(m>n) temp = m - n - 1;
	else temp = m - n; 
	len = strlen(a);
	if(a[0]=='-') printf("-");
	for(j=n;j<len;j++){
		if(a[j]!='.') printf("%c",a[j]);
		if(j==n&&n!=len-1) printf(".");
	}
	printf("e%d",temp);
	return 0;
} 

