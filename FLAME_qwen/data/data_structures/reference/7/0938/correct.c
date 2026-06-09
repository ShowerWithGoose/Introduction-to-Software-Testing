#include <stdio.h>
int read();
int n, a[200004], root;
int ls[200004], rs[200004], d[200004];

void ins(int *x, int p) {
    ++d[p];
    if (!*x) {
        *x = p;
        return;
    }
    a[p] < a[*x] ? ins(&ls[*x], p) : ins(&rs[*x], p);
}

void prt(int x) {
    if (!x) return;
    if (!ls[x] && !rs[x]) printf("%d %d\n", a[x], d[x]);
    prt(ls[x]), prt(rs[x]);
}

int main() {
    n = read();
    for (int i = 1; i <= n; ++i) a[i] = read(), ins(&root, i);
    prt(1);
    return 0;
}

int read() {
    int x = 0, f = 1, c = getchar();
    while (c < '0' || c > '9') (c == '-') ? (f = -1) : 0, c = getchar();
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
