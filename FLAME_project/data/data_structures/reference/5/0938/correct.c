#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int read();

struct P {
    long long a, x;
} p[200005], A[200005], B[200005];

char s[200005];
int ls, ts;
int nA, nB, cnt;
int cmp(const void *a, const void *b) {
    struct P *_a = (struct P *)a;
    struct P *_b = (struct P *)b;
    return _a->x > _b->x ? -1 : 1;
}
int main() {
    ts = 0, gets(s), ls = strlen(s);
    while (ts + 2 <= ls) ++nA, A[nA].a = read(), A[nA].x = read();
    ts = 0, gets(s), ls = strlen(s);
    while (ts + 2 <= ls) ++nB, B[nB].a = read(), B[nB].x = read();
    int i, j, k;
    for (i = 1; i <= nA; ++i) {
        for (j = 1; j <= nB; ++j) {
            int flg = 0;
            long long ta = A[i].a * B[j].a, tx = A[i].x + B[j].x;
            for (k = 1; k <= cnt; ++k)
                if (tx == p[k].x) {
                    flg = 1, p[k].a += ta;
                    break;
                }

            if (!flg) p[++cnt] = (struct P){ta, tx};
        }
    }

    qsort(p + 1, cnt, sizeof(p[0]), cmp);

    for (i = 1; i <= cnt; ++i) printf("%d %d ", p[i].a, p[i].x);
    return 0;
}

int read() {
    int x = 0, f = 1, c = s[ts++];
    while (c < '0' || c > '9') (c == '-') ? (f = -1) : 0, c = s[ts++];
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = s[ts++];
    return x * f;
}


