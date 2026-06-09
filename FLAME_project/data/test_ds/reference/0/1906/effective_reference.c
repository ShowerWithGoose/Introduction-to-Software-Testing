#include<stdio.h>
#include<string.h>
int main() {
	char a[1000],b[1000];
	int i=0,j=0,p=0,q=0;
	gets(a);
	while(a[i+1]!='\0') {
		if(a[i+1]=='-') {q=0;
			if(a[i]<='Z'&&a[i]>='A'&&a[i+2]<='Z'&&a[i+2]>='A') {
				while(a[i]+j<a[i+2]) {
					b[p++]=a[i]+j;
					j++;
				}
				i++;
				q=1;
			} else if(a[i]<='z'&&a[i]>='a'&&a[i+2]<='z'&&a[i+2]>='a') {
				while(a[i]+j<a[i+2]) {
					b[p++]=a[i]+j;
					j++;
				}
				i++;
				q=1;
			} else if(a[i]<='9'&&a[i]>='0'&&a[i+2]<='9'&&a[i+2]>='0') {
				while(a[i]+j<a[i+2]) {
					b[p++]=a[i]+j;
					j++;
				}
				i++;
				q=1;
			} else
				b[p++]=a[i++];

			j=0;
		} else {
			if(q==0)
				b[p++]=a[i++];
			else
				i++;
			q=0;
		}
	}
	b[p]=a[i];
	puts(b);

	return 0;
}



