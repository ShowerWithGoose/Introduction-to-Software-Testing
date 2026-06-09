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

int tree[20000];

void con(int p,int amount){
    if(tree[p]==-1)tree[p]=amount;
    else if(tree[p]>amount)con(p*2,amount);
    else con(p*2+1,amount);
}
void out(int p,int d){
    if(tree[p]==-1)return;
    if(tree[p*2]==-1&&tree[p*2+1]==-1)printf("%d %d\n",tree[p],d);
    else{
        out(p*2,d+1);
        out(p*2+1,d+1);
    }
}

int main() {
    int n=read();
    FOR(i,0,19999)tree[i]=-1;
    FOR(i,1,n){
        con(1,read());
    }
    out(1,1);

    return 0;
}
