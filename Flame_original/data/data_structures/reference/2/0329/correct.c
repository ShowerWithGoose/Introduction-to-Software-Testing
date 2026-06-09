#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100007

typedef long long LL;

char s[N], ch[N];
LL num[N], x;
int num_t, ch_t;

int pri(char ch) {
    switch (ch) {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        case '(': return 3;
        case ')': return -1;
        default: return 0;
    }
}

int pop() {
    int a = num[--num_t], b = num[--num_t];
    switch (ch[--ch_t]) {
        case '+': num[num_t++] = b + a; return 1;
        case '-': num[num_t++] = b - a; return 1;
        case '*': num[num_t++] = b * a; return 1;
        case '/':
            if (!a) return 0;
            else {num[num_t++] = b / a; return 1;}
        default: return 0;
    }
}

void calculate(char *s) {
    int flag = 0;
    for (int i = 0; s[i] != '=' && s[i]; i++) {
        if (s[i] == ' ') continue;
        if (isdigit(s[i])) {
            x = x * 10 + s[i] - '0';
            flag = 1; continue;
        }
        int p = pri(s[i]);
        if (p) {
            if (flag) num[num_t++] = x, flag = x = 0;
            while (ch_t && ch[ch_t-1] != '(' && p <= pri(ch[ch_t-1]))
                if (!pop()) {puts("Invalid!"); return;}
            ~p? ch[ch_t++] = s[i]: ch_t--;
        }
        else {puts("Invalid!"); return;}
    }
    if (flag) num[num_t++] = x;
    while (ch_t) if (!pop()) {puts("Invalid!"); return;}
    printf("%I64d\n", *num);
}

int main() {
    gets(s);
    calculate(s);
    return 0;
}

