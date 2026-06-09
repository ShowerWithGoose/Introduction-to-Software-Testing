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

int hash[20000000];

char voc[200000][80];
char art[10000000];  // article

int cmp(const void*a1,const void *b1){
    char *a=(char*)a1,*b=(char*)b1;
    return strcmp(a,b);
}

int main() {
    FILE* in = fopen("article.txt", "r");
    int xx = 0, vp = 0;
    while (fscanf(in, "%c", &art[xx++]) >= 0)
        ;
    int ln = strlen(art);
    FOR(i, 0, ln - 1) {
        if (art[i] >= 'A' && art[i] <= 'Z')
            art[i] -= 'A', art[i] += 'a';
    }
    FOR(i, 0, ln - 1) {
        int l, r, j = i;
        if (art[i] >= 'a' && art[i] <= 'z') {
            l = i;
            while (art[j] >= 'a' && art[j] <= 'z')
                j++;
            r = j - 1;
            int tmp = 0;
            FOR(k, l, r)
            tmp = (tmp * 26 + art[k] - 'a') % 19260817;
            if (hash[tmp] == 0) {
                FOR(k, l, r)
                voc[vp][k-l]=art[k];
                vp++;
            }
            hash[tmp]++;
            i=r;
        }
    }
    qsort(voc,vp,sizeof(voc[0]),cmp);
    FOR(i,0,vp-1){
        int hx=0,lx=strlen(voc[i]);
        FOR(k,0,lx-1)hx = (hx * 26 + voc[i][k] - 'a') % 19260817;
        printf("%s %d\n",voc[i],hash[hx]);
    }
    return 0;
}
