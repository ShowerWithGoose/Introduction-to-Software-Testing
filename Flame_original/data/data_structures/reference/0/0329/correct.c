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

char s[N];

int main() {
    scanf("%s", s);
    int l = strlen(s);
    for (int i = 0; i < l; i++) {
        if (s[i] == '-') {
            if (i == 0 || i == l - 1) putchar('-');
            else if (isupper(s[i-1]) && isupper(s[i+1]) && s[i-1] < s[i+1])
                for (int j = s[i-1] + 1; j < s[i+1]; j++) putchar(j);
            else if (islower(s[i-1]) && islower(s[i+1]) && s[i-1] < s[i+1])
                for (int j = s[i-1] + 1; j < s[i+1]; j++) putchar(j);
            else if (isdigit(s[i-1]) && isdigit(s[i+1]) && s[i-1] < s[i+1])
                for (int j = s[i-1] + 1; j < s[i+1]; j++) putchar(j);
            else putchar('-');
        }
        else putchar(s[i]);
    }
    return 0;
}

