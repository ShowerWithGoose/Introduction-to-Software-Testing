#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
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
#define itn int
#define fsf fscanf
#define fpr fprintf
int st[100];
int top = -1;

void push(int x) {
	st[++top] = x;
}

void pop() {
	top--;
}

int main() {
	int op;
	int x;
	while (1) {
		sc(op);
		if (op == 1) {
			if (top == 100) {
				pr("error ");
			} else {
				sc(x);
				push(x);
			}
		}
		ef(op == 0) {
			if (top == -1) {
				pr("error ");
			} else {
				pr("%d ", st[top]);
				pop();
			}
		} else if (op == -1)
			brk;
	}















}
