#include <stdio.h>
int read();
char s[1000006], t[1000006];

int type(char j) {
    if (j >= '0' && j <= '9') return 1;
    if (j >= 'a' && j <= 'z') return 2;
    if (j >= 'A' && j <= 'Z') return 3;
    return 0;
}

int main() {
    scanf("%s", s + 1);
    int l = strlen(s + 1), m = 0, i;
    for (i = 1; i <= l; ++i) {
        if (s[i] != '-' || i == 1 || i == l ||
            type(s[i - 1]) != type(s[i + 1]) || s[i + 1] <= s[i - 1]) {
            putchar(s[i]);
            continue;
        }
        char j = s[i - 1] + 1;
        for (; j < s[i + 1]; ++j) putchar(j);
    }
    return 0;
}

int read() {
    int x = 0, f = 1, j = getchar();
    while (j < '0' || j > '9') (j == '-') ? (f = -1) : 0, j = getchar();
    while (j >= '0' && j <= '9') x = x * 10 + j - '0', j = getchar();
    return x * f;
}
