#include <stdio.h>
#include <string.h>
#include<ctype.h>
#include<stdlib.h>
#define ML 10086

char inp[ML];
int ansc[ML], sl = 0;
long long ans = 0;

int geti(char a[], int i) {
	int ret =0;
	for(;isdigit(a[i]);i++) {
		ret = ret*10 + a[i] -'0';
	}
	return ret;
}

int main()
{
	gets(inp);
	char las = '+';
	for(char *p = inp; *p != '='; p++) {
		if(isdigit(*p)) {
			int tmp = geti(p,0);
			switch(las) {
				case '+':
					ansc[++sl] = tmp;
					break;
				case '-':
					ansc[++sl] = tmp * -1;
					break;
				case '/':
					ansc[sl] /= tmp;
					break;
				case '*':
					ansc[sl] *= tmp;
					break;
			}
			while(isdigit(*p)) p++;
			p--;
		}else if(!isblank(*p)) las = *p;
	}
	for(int i=0;i<=sl;i++) ans += ansc[i];
	printf("%lld",ans);
	
	return 0;
}

