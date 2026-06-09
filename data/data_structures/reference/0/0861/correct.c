#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define ll long long
#define ull unsigned long long
#define db double
#define pr printf
#define sf scanf
#define rt return
#define gcr getchar
#define pcr putchar
#define pi 3.14159265
#define sw switch
#define brk break
#define ctn continue
#define sc(x) scanf("%d",&x)
#define ef else if
#define slf(x) scanf("%lf",&x)
#define pf(x) printf("%d\n",x)//\n
#define max(a,b) ((a)>=(b)?(a):(b))//¿ÉÐÞ¸Ä>=or>
#define min(a,b) ((a)<=(b)?(a):(b))
#define sl strlen
#define PR printf("\n");
#define For(n) for(int i=0;i<n;++i)
#define New(p) p=(node*)malloc(sizeof(node))
char s[1000];

int T(char *s, int i) {
	if (islower(s[i]) && s[i + 1] == '-' && islower(s[i + 2]))
		rt 1;
	else if (isupper(s[i]) && s[i + 1] == '-' && isupper(s[i + 2]))
		rt 2;
	else if (isdigit(s[i]) && s[i + 1] == '-' && isdigit(s[i + 2]))
		rt 3;
	rt 0;
}

void prt(char s, char aim) {
	for (char i = s; i < aim; ++i) {//×ó±ÕÓÒ¿ª
		pcr(i);
	}
}

int main() {
	gets(s);
	for (int i = 0; i < sl(s);) {
		if (T(s, i)) {
			prt(s[i], s[i + 2]);
			i += 2;
		} else {
			pcr(s[i]);
			i++;
		}
	}
	rt 0;
}


