#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#define lli long long int

char a[201],t1,t2;
int i,j;
int main() {
	gets(a);
	for(i=0; i<strlen(a); i++) {
		if(a[i]!='-') {
			printf("%c",a[i]);
		}
		if(a[i]=='-') {
			t1=a[i-1];
			if(i+1<strlen(a))
				t2=a[i+1];
			else t2=0;
			if(t1>='a'&&t1<='z'&&t2>='a'&&t2<='z'&&t1<t2) {
				for(j=1; j<=t2-t1-1; j++)
					printf("%c",t1+j);
				continue;
			}
			if(t1>='A'&&t1<='Z'&&t2>='A'&&t2<='Z'&&t1<t2) {
				for(j=1; j<=t2-t1-1; j++)
					printf("%c",t1+j);
				continue;
			}
			if(t1>='0'&&t1<='9'&&t2>='0'&&t2<='9'&&t1<t2) {
				for(j=1; j<=t2-t1-1; j++)
					printf("%c",t1+j);
				continue;
			}
			printf("-");
		}
	}
	return 0;
}



