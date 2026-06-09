#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
#define eps 1e-10
char a[10000],b[10000];
int c[10000],i,h1,h2,result,flag1,flag2;

int main() {
	gets(a);
	int l=strlen(a);
	for(i=0; i<l; i++) {
		int number=0;
		if(isdigit(a[i])) {
			while(isdigit(a[i]))
				number=number*10+a[i++]-'0';
			c[++h1]=number;
			i--;
		} else {
			if(a[i]==' ')
				continue;
			if(b[h2]=='*'&&h1>=2&&h2>=1) {
				c[h1-1]=c[h1-1]*c[h1];
				h1--;
				h2--;
			} else if(b[h2]=='/'&&h1>=2&&h2>=1) {
				c[h1-1]=c[h1-1]/c[h1];
				h1--;
				h2--;
			}
			b[++h2]=a[i];
		}
	}
	int result=c[1];
	for(i=1; i<h1; i++) {
		if(b[i]=='+') {
			result+=c[i+1];
		} else {
			result-=c[i+1];
		}
	}
	printf("%d",result);
	return 0;
}



