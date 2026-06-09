#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100007

typedef long long LL;

int input() {
    int x = 0; int sign = 1; char chr = getchar();
    for (;!isdigit(chr); chr = getchar()) if (chr == '-') sign = 0;
    for (; isdigit(chr); chr = getchar()) x = x * 10 + chr - '0';
    return sign? x: -x;
}

void print(int x) {
    if (x < 0) {putchar('-'); x = -x;}
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

char s[107];
int l, dot, x;

int main() {
    scanf("%s", s);
    l = strlen(s);
    for (int i = 0; i < l; i++) if (s[i] == '.') {dot = i; break;}
    for (int i = 0; i < l; i++) if (s[i] != '0' && s[i] != '.') {x = i; break;}
    putchar(s[x]);
    if (x != l - 1) putchar('.');
    for (int i = x + 1; i < l; i++)
        if (s[i] != '.') putchar(s[i]);
    putchar('e');
    if (dot >= x) print(dot - x - 1);
    else print(dot - x);
    return 0;
}

