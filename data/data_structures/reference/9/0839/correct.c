#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define cL while (getchar() != '\n')  // clear line
#define fi(x) for (i = 0; i < x; i++)
#define fj(x) for (j = 0; j < x; j++)
#define FOR(a, b, c) for (int(a) = (b); (b) < (c) ? (a) <= (c) : (a) >= (c); (b) < (c) ? (a)++ : (a)--)
#define LL long long
#define min(a, b) (a > b ? b : a)
#define max(a, b) (a < b ? b : a)
#define pf printf
#define sf scanf

int read() {
    int X = 0, S = 1, R = getchar();
    while (R < '0' || R > '9')
        (R == '-') ? (S = -1) : 0, R = getchar();
    while (R >= '0' && R <= '9')
        X = X * 10 + R - '0', R = getchar();
    return X * S;
}
struct line {
    int x1, y1, x2, y2;
    int count, father;
} a[1000];

int n;

int cmp(const void* r, const void* l) {
    int r1 = ((struct line*)r)->x1;
    int l1 = ((struct line*)l)->x1;
    return r1-l1;
}
int main() {
    LL i, j;
    n = read();
    FOR(i, 1, n) {
        a[i].x1 = read();
        a[i].y1 = read();
        a[i].x2 = read();
        a[i].y2 = read();
        a[i].count = 1;
        a[i].father = 0;
    }
    qsort(a + 1, n, sizeof(a[0]), cmp);
    FOR(i, 1, n - 1) {
        if (a[i].father == 0)
            a[i].father = i;
        FOR(j, i + 1, n) {
            if (a[i].x2 == a[j].x1 && a[i].y2 == a[j].y1)
                if (a[i].count + 1 >= a[j].count) {
                    a[j].count = a[i].count + 1;
                    a[j].father = a[i].father;
                }
        }
    }
    int max=0,maxp=0;
    FOR(i,1,n)if(a[i].count>max){
        max=a[i].count;
        maxp=a[i].father;
    }
    printf("%d %d %d",max,a[maxp].x1,a[maxp].y1);
    return 0;
}
