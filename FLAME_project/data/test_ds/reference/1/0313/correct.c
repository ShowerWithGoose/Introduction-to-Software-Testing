#include<stdio.h>
#include<string.h>
int main() {
	char a[10000]="\0",b[10000]="\0";
	gets(a);
	int x=0,y=0,k=0;
	for(x=0,y=0; a[x]!='\0'; x++,y++) {
		if(a[x]=='-'&&'0'<=a[x-1]&&a[x-1]<='9'&&'0'<=a[x+1]&&a[x+1]<='9'&&a[x-1]<a[x+1]) {

			for(k=1; k<=(a[x+1]-a[x-1]-1); k++,y++) {
				int c=k+a[x-1]-'0';
				b[y]=(char)(c+48);
			}
			y--;
		} else if(a[x]=='-'&&'a'<=a[x-1]&&a[x-1]<='z'&&'a'<=a[x+1]&&a[x+1]<='z'&&a[x-1]<a[x+1]) {

			for(k=1; k<=(a[x+1]-a[x-1]-1); k++,y++) {
				int c=k+a[x-1]-'a';
				b[y]=(char)(c+97);
			}
		y--;
		} else if(a[x]=='-'&&'A'<=a[x-1]&&a[x-1]<='Z'&&'A'<=a[x+1]&&a[x+1]<='Z'&&a[x-1]<a[x+1]) {

			for(k=1; k<=(a[x+1]-a[x-1]-1); k++,y++) {
				int c=k+a[x-1]-'A';
				b[y]=(char)(c+65);
			}
		y--;
		} else
			b[y]=a[x];
	}
	puts(b);
	return 0;
}


