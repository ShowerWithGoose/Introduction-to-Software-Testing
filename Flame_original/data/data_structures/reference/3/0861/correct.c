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

int Output(char *s) {
	if (s[0] == '0') {
		int cnt = 0;
		for (int i = 2; i < sl(s) && s[i] == '0'; ++i) {
			cnt++;
		}
		pcr(s[cnt + 2]);
		if (sl(s) != cnt + 3)
			pr(".");
		for (int i = cnt + 3; i < sl(s); ++i) {
			pcr(s[i]);
		}
		pr("e-%d", cnt + 1);

	} else {
		int point = 0;
		for (int i = 0; s[i]; ++i) {
			point++;
			if (s[i] == '.')
				brk;//Î»ÖÃ
		}
		point -= 2;
		pcr(s[0]);
		pr(".");
		for (int i = 1; i < sl(s); ++i) {
			if (s[i] ==  '.')
				ctn;
			else
				pcr(s[i]);
		}
		pr("e%d", point);
	}


}
char s[105];

int main() {
	gets(s);
	Output(s);
	rt 0;
}
