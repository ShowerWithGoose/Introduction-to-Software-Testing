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
int n,x[12],p[12];
void find(int a, int b);
int main() {
    scanf("%d", &n);
    find(0, n);
    return 0;
}
void find(int a, int b) {
    if(a==b){
        FOR(i,1,n)printf("%d ",x[i]);
        putchar('\n');
        return;
    }
    FOR(i,1,n)if(p[i]==0){
        x[a+1]=i,p[i]=1;
        find(a+1,b);
        p[i]=0;
    }
    return;
}


