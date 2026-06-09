#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

#define max(x,y) ((x) > (y) ? (x) : (y))
#define MAXN 1024

typedef struct POS{
    int stx,sty;
    int edx,edy;
} pos;

int sty, maxw;
pos l[MAXN];
// int nxt[MAXN], hed[MAXN], tow[MAXN], tai = 0; 
// int wei[MAXN], end[MAXN];

pos makePos(int a,int b,int x,int y) {
    pos ret = {a,b,x,y};
    return ret;
}

pos readPos() {
    int a,b,x,y;
    scanf("%d%d%d%d",&a,&b,&x,&y);
    return makePos(a,b,x,y);
}

// void add(int u,int v) {
//     tow[++tai] = v, nxt[tai] = hed[u], hed[u] = tai; 
// }

int isAdj(pos a,pos b){
    if(a.edx == b.stx && a.edy == b.sty) {
        return 1;
    }
    return 0;
}

// int dfs(int x) {
//     int i,j;
//     for(i=hed[x]; i; i = nxt[i]) {
//         j =  tow[i];
//         if(wei[j]) 
//     }
//     return 0;
// }

int cmp(const void *a, const void *b) {
    pos *x = (pos*) a, *y = (pos *) b;
    if(x->stx > y->stx) return 1;
    else return -1;
}

int ret[MAXN];

int main() {
    scanf("%d",&sty);
    for(int i=1;i<=sty;i++) {
        l[i] = readPos();
    }
    // for(int i=1;i<=n;i++) {
    //     for(int j=i+1;j<=n;j++) {
    //         if(isAdj(six[i], six[j])) add(i,j);
    //         if(isAdj(six[j], six[i])) add(j,i);
    //     }
    // }
    // memset(wei,0,sizeof(wei));
    // pos ans;
    // for(int i=1, j;i<=n;i++) {
    //     if(j = dfs(i)) {
    //         ans.m = six[i].m;
    //         ans.n = six[i].n;
    //         ans.p = six[j].p;
    //         ans.q = six[j].q;
    //     }
    // }
    // printf("%d %d %d",maxw, ans.m, ans.n);

    qsort(l+1,sty,sizeof(l[1]),cmp);
    int i, ans = 0;
    for(int i=1;i<=sty;i++) {
        if(ret[i]) continue;
        int cnt = 1, las = i;
        for(int j=i+1;j<=sty;j++) {
            if(isAdj(l[las], l[j])) {
                ret[j] = 1;
                cnt++;
                las = j;
            }
        }
        if(cnt > ans) {
            ans = cnt;
            i = i;
        }
    }
    printf("%d %d %d", ans, l[i].stx, l[i].sty);
    


    return 0;
}


/*
10

80 75 125 75

60 40 80 55

80 55 90 20

140 120 195 205

10 111 70 165

22 35 43 43

22 175 80 205

43 43 60 40

90 20 125 60

70 165 140 120
*/
