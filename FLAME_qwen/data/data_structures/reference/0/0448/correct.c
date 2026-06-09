#include<stdio.h>
#include<string.h>
int main() {
	char c[50];
	int i,j,k,l;
	gets(c);
	for(i=0; i<=strlen(c)-1; i++) {
		if(c[i]=='-') {
			if(c[i-1]>='a'&&c[i+1]<='z') {
				k=c[i+1]-c[i-1]-1;
				j=strlen(c)-1;
				c[j+k]='\0';
				for(l=strlen(c)-1; l>i; j--,l--) {
					c[j+k-1]=c[l];
				}
				for(; i<l+k; i++) {
					c[i]=c[i-1]+1;
				}
			} else if(c[i-1]>='A'&&c[i+1]<='Z') {
				k=c[i+1]-c[i-1]-1;
				j=strlen(c)-1;
				c[j+k]='\0';
				for(l=strlen(c)-1; l>i; j--,l--) {
					c[j+k-1]=c[l];
				}
				for(; i<l+k; i++) {
					c[i]=c[i-1]+1;
				}
			} else if(c[i-1]>='0'&&c[i+1]<='9')
			{
				k=c[i+1]-c[i-1]-1;
				j=strlen(c)-1;
				c[j+k]='\0';
				for(l=strlen(c)-1; l>i; j--,l--) {
					c[j+k-1]=c[l];
				}
				for(; i<l+k; i++) {
					c[i]=c[i-1]+1;
				}
			}
		}
	}
	puts(c);
	return 0;
}



