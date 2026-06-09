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

int vmap[200][200];

int que[200],p,rear;
int flag[200];
int c;
int v,e;

void dep(int s){
    if(s==0)FOR(i,0,199)flag[i]=0;
    if(s==0)FOR(i,0,199)que[i]=0;
    printf("%d ",s);flag[s]=1;
    FOR(i,1,v)if(vmap[s][i]>=c)if(flag[i]==0)dep(i);
    return;
}
void wid(int s){
    if(s==0)FOR(i,0,199)flag[i]=0;
    if(s==0)FOR(i,0,199)que[i]=0;
    if(s==0)p=0,rear=0;
    printf("%d ",s);
    FOR(i,1,v)if(vmap[s][i]>=c)if(flag[i]==0)que[++p]=i,flag[i]=1;
    if(p>rear)wid(que[++rear]);
    return;
}

int main() {
    v=read();e=read();
    FOR(i,1,e){
        int l=read();int r=read();
        vmap[l][r]=vmap[r][l]=2;
    }
    int del=read();
    FOR(i,0,v-1){
        if(vmap[i][del])vmap[i][del]=1;
        if(vmap[del][i])vmap[del][i]=1;
    }
    c=1;
    dep(0);printf("\n");
    wid(0);printf("\n");
    c=2;
    dep(0);printf("\n");
    wid(0);printf("\n");

    return 0;
}
