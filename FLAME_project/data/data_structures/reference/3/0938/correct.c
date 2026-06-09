#include <stdio.h>
#include <string.h>
int read();
char gt();
char s[1000006];
char t1[1000006], t2[1000006];
int n;
int main() {
    scanf("%s", s + 1), n = strlen(s + 1);
    int i = 1, a = 0, b = 0;
    while (s[i] >= '0' && s[i] <= '9') t1[++a] = s[i++];
    ++i;
    while (s[i] >= '0' && s[i] <= '9') t2[++b] = s[i++];
    if (t1[a] == '0') {
        i = 1;
        while (t2[i] == '0') ++i;
        if (i == b) return printf("%ce-%d", t2[b], b), 0;
        int x = i;
        putchar(t2[i]), putchar('.'), ++i;
        for (; i <= b; ++i) putchar(t2[i]);
        printf("e-%d", x);
    } else {
        putchar(t1[1]);
        putchar('.');
        for (i = 2; i <= a; ++i) putchar(t1[i]);
        for (i = 1; i <= b; ++i) putchar(t2[i]);
        printf("e%d\n", a - 1);
    }
    return 0;
}

char tk;
int read() {
    int x = 0, f = 1, c = getchar();
    while (c < '0' || c > '9') (c == '-') ? (f = -1) : 0, c = getchar();
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    tk = c;
    return x * f;
}

char gt() {
    char c = tk;
    while (c != '+' && c != '-' && c != '*' && c != '/' && c != '=')
        c = getchar();
    return c;
}
