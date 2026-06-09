#include <stdio.h>
int read();
char s[1000006], t[1000006];

int type(char c) {
    if (c >= '0' && c <= '9') return 1;
    if (c >= 'a' && c <= 'z') return 2;
    if (c >= 'A' && c <= 'Z') return 3;
    return 0;
}

int main() {
    scanf("%s", s + 1);
    int n = strlen(s + 1), m = 0, i;
    for (i = 1; i <= n; ++i) {
        if (s[i] != '-' || i == 1 || i == n ||
            type(s[i - 1]) != type(s[i + 1]) || s[i + 1] <= s[i - 1]) {
            putchar(s[i]);
            continue;
        }
        char c = s[i - 1] + 1;
        for (; c < s[i + 1]; ++c) putchar(c);
    }
    return 0;
}

int read() {
    int x = 0, f = 1, c = getchar();
    while (c < '0' || c > '9') (c == '-') ? (f = -1) : 0, c = getchar();
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
