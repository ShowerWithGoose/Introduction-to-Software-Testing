#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main() {
	char a[10000];
	gets(a);
	for(int i=0;a[i]!='\0' ; i++) {
		if(a[i]=='-'&&i>0) {
			if('a'<=a[i-1]&&a[i-1]<a[i+1]&&a[i+1]<='z')for(int j=a[i-1]+1; j<a[i+1]; j++) {
					printf("%c",j);
				}
			else if('A'<=a[i-1]&&a[i-1]<a[i+1]&&a[i+1]<='Z')for(int k=a[i-1]+1; k<a[i+1]; k++) {
					printf("%c",k);
				}
			else if('0'<=a[i-1]&&a[i-1]<a[i+1]&&a[i+1]<='9')for(int l=a[i-1]+1; l<a[i+1]; l++) {
					printf("%c",l);
				}
			else printf("-");
		} else printf("%c",a[i]);
	}
	return 0;
}

