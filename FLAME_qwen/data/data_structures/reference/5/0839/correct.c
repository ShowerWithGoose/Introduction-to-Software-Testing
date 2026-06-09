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

int a[2000][2], b[2000][2];
int ans[200000][2];

int cmp(const void* a1,const void *b1){
    int* k1=(int *)a1,*k2=(int *)b1;
    return k2[1]-k1[1];
}

int main() {
    FOR(i, 1, 1999) {
        scanf("%d%d", &a[i][0], &a[i][1]);
        if (getchar() == '\n')
            break;
    }
    FOR(i, 1, 1999) {
        scanf("%d%d", &b[i][0], &b[i][1]);
        if (getchar() != ' ')
            break;
    }
    int p = 1;
    FOR(i, 1, 1999) {
        FOR(j, 1, 1999) {
            ans[p][0] = a[i][0] * b[j][0];
            ans[p++][1] = a[i][1] + b[j][1];
            if (b[j][0] == 0)
                break;
        }
        if (a[i][0] == 0)
            break;
    }
    qsort(ans+1,p-1,sizeof(ans[0]),cmp);
    FOR(i,1,p-1){
        if(i==p-1){
            if(ans[i][0]!=0)printf("%d %d ",ans[i][0],ans[i][1]);
        }
        else if(ans[i][1]!=ans[i+1][1]){
            if(ans[i][0]!=0)printf("%d %d ",ans[i][0],ans[i][1]);
        }
        else {
            ans[i+1][0]+=ans[i][0];
        }
    }
    return 0;
}
