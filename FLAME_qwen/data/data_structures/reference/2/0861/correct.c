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
#define slf(x) scanf("%lf",&x)
#define pf(x) printf("%d\n",x)//\n
#define max(a,b) ((a)>=(b)?(a):(b))//可修改>=or>
#define min(a,b) ((a)<=(b)?(a):(b))
#define sl strlen
#define Arr(s) sizeof(s)/sizeof(s[0])
#define New(x) x=(node*)malloc(sizeof(node))
#define For(n) for(int i=0;i<n;++i)
#define PR pr("\n");
#define itn int
int num[300];
char ch[200];

int push(int *num, int top, int x) {
	top++;
	num[top] = x;
	rt top;
}

int Push(char *ch, int top, char x) {
	top++;
	ch[top] = x;
	rt top;
}

int main() {
	int top = -1;
	int Top = -1;
	int n1, n2;
	char c1, c2;
	int cnt = 0;
	while (1) {
		sf("%d %c", &n1, &c1);

		while (c1 == '*' || c1 == '/') {
			sf("%d %c", &n2, &c2);
			if (c1 == '*') {
				n1 = n1 * n2;
			}
			if (c1 == '/') {
				n1 = n1 / n2;
			}
			c1 = c2; //更新
		}
		{
			top = push(num, top, n1); //ruzhan
			Top = Push(ch, Top, c1);
			cnt++;
		}
		if (c1 == '=') {
			brk;
		}
	}
	int n = num[0];
	char c;
//	for (int i = 0; i < cnt; ++i) {
//		pr("%d%c", num[i], ch[i]);
//	}
//	PR
	for (int i = 1; i < cnt; ++i) {
		if (ch[i - 1] == '+') {
			n += num[i];
		} else if (ch[i - 1] == '-') {
			n -= num[i];
		}
	}
	pr("%d", n);
	rt 0;





}
