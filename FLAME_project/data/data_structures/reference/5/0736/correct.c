#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

#define N 100086
#define ll long long

typedef struct ITM{
    ll k, n;
} itm;

itm fir[N], sec[N], ans[N];
int lf, ls, la;
char inp[10086];

int cmp(const void *a, const void *b) {
    itm *x = (itm * )a, *y = (itm *) b;
    if(x->n > y->n) return -1;
    else return 1;
}

ll sgeti(char *p, char **cge) {
    ll ret = 0;
    while(!isdigit(*p)) {
        if(*p == '\n' || *p == '\0') {
            *cge = p+1;
            return -1;
        }
        p++;
    }
    while(isdigit(*p)) {
        ret = ret*10 + *p -'0';
        p++;
    }
    *cge = p;
    return ret;
}

int main() {
    ll t1,t2;
    char *p;
    gets(inp);
    p=inp;
    while(1) {
        t1 = sgeti(p, &p);
        t2 = sgeti(p, &p);
        if(t1 == -1 || t2==-1) break;
        fir[++lf] .k=t1, fir[lf].n=t2;
    }
    memset(inp,0,sizeof(inp));
    gets(inp);
    p=inp;
    while(1) {
        t1 = sgeti(p, &p);
        t2 = sgeti(p, &p);
        if(t1 == -1 || t2==-1) break;
        sec[++ls] .k=t1, sec[ls].n=t2;
    }
    for(int i=1;i<=lf;i++) {
        for(int j=1;j<=ls;j++) {
            la++;
            ans[la].k = fir[i].k * sec[j].k;
            ans[la].n = fir[i].n + sec[j].n;
        }
    }
    qsort(ans+1, la, sizeof(itm), cmp);
    for(int i=1;i<=la;i++) {
        if(ans[i].n && ans[i].n == ans[i+1].n) {
            ans[i+1].k += ans[i].k;
        }else {
            if(ans[i].k == 0) continue;
            printf("%lld %lld ",ans[i].k, ans[i].n);
        }
    }


    return 0;
}

/*
30 86000 50 80020 80 80010 60 80000 6 12000 21 6300 10 6020 31 6010 66 6000 35 320 56 310 42 300 25 30 130 20 174 10 108 0
30 86000 50 80020 80 80010 60 80000 6 12000 21 6300 10 6020 31 6010 66 6000 35 320 56 310 42 300 25 30 130 20 174 10 108 0


*/
