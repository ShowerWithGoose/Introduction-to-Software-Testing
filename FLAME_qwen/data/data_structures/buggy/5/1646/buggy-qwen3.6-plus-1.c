#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ll long long
#define rep(i, l, r) for(ll i = l; i <= r; ++i)
#define nep(i, r, l) for(ll i = r; i >= l; --i)
#define eep(i, u) for(ll i = head[u]; i; i = e[i].nxt)
ll max(ll x, ll y) {return (x > y)?x:y;}
ll min(ll x, ll y) {return (x < y)?x:y;}
ll jdz(ll x) {return (x > 0)?x:(-x);}
ll gcd(ll x, ll y) {return (x % y)?gcd(y, x % y):y;}
ll sgn(ll x) {return x?((x > 0)?1:-1):0;}
void swp(int *x, int *y) {ll t = *x; *x = *y; *y = t;}
#define MAXN 1111111

ll Len, pos;
ll len[3];

char buf[MAXN];

struct node {ll x, y;} w[3][MAXN];

ll read() {
    ll X = 0, F = 1; char C = buf[++pos];
    while(pos <= Len &&(C < '0' || C > '9')) {if(C == '-')F=-1; C = buf[++pos];}
    while(pos <= Len && C >= '0' && C <= '9') {X = X*10+C-'0'; C = buf[++pos];}
    return X * F;
}

ll init(ll* p, ll* q) {
    if(pos > Len) return 0;
    *p = read();
    *q = read();
    return 1;
}

void Init() {
    ll x, y;
    rep(i, 0, 1) {
        gets(buf + 1); // @@ gets is removed in the C11 standard and causes a compilation error in modern environments. Use fgets instead.
        pos = 0;
        Len = strlen(buf + 1);
        while(init(&x, &y)) {
            ++len[i];
            w[i][len[i]].x = x;
            w[i][len[i]].y = y;
        }
    }
        
}

int cmp(const void* X, const void* Y) {
    return ((*(struct node*)Y).y > (*(struct node*)X).y)?1:-1;
}

void work() {
    rep(i, 1, len[0])
        rep(j, 1, len[1]) {
            ++len[2];
            w[2][len[2]].x = w[0][i].x * w[1][j].x;
            w[2][len[2]].y = w[0][i].y + w[1][j].y;
        }
    qsort(w[2] + 1, len[2] + 1, sizeof(struct node), cmp);
}

int main() {
    Init();
    work();
    rep(i, 1, len[2] + 1) {
        if(i <= len[2] && w[2][i].y == w[2][i + 1].y)
            w[2][i + 1].x += w[2][i].x;
        else printf("%lld %lld ", w[2][i].x, w[2][i].y);
    }
    return 0;
}