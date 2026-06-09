#include <stdio.h>
int read();
char gt();
char s[1000006];

int main() {
    int ans = 0, nw = 0;
    nw = read();
    while (1) {
        char fh = gt();
        // printf("%c\n", fh);
        if (fh == '=') {
            ans += nw;
            break;
        }
        if (fh == '*')
            nw = nw * read();
        else if (fh == '/')
            nw = nw / read();
        else {
            ans = ans + nw;
            nw = (fh == '+') ? read() : -read();
        }
    }
    printf("%d\n", ans);
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
