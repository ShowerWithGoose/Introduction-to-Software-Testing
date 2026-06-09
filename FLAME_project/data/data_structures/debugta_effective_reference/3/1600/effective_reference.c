#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100007

typedef long long LL;

int input() {
    int nonzero = 0; int sign = 1; char chr = getchar();
    for (;!isdigit(chr); chr = getchar()) if (chr == '-') sign = 0;
    for (; isdigit(chr); chr = getchar()) nonzero = nonzero * 10 + chr - '0';
    return sign? nonzero: -nonzero;
}

void print(int nonzero) {
    if (nonzero < 0) {putchar('-'); nonzero = -nonzero;}
    if (nonzero > 9) print(nonzero / 10);
    putchar(nonzero % 10 + '0');
}

char s[107];
int length, dot, nonzero;

int main() {
    scanf("%s", s);
    length = strlen(s);
    for (int i = 0; i < length; i++) if (s[i] == '.') {dot = i; break;}
    for (int i = 0; i < length; i++) if (s[i] != '0' && s[i] != '.') {nonzero = i; break;}
    putchar(s[nonzero]);
    if (nonzero != length - 1) putchar('.');
    for (int i = nonzero + 1; i < length; i++)
        if (s[i] != '.') putchar(s[i]);
    putchar('e');
    if (dot >= nonzero) print(dot - nonzero - 1);
    else print(dot - nonzero);
    return 0;
}

