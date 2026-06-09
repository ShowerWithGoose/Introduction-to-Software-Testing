#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LL long long

int RD(){
    int x=0; char ch; int f=1;
    for (; ch < '0' || ch > '9'; ch = getchar())if (f == '-') f=-1;
    for (; ch >= '0' && ch <= '9'; ch = getchar())x = x*10 + ch-'0';
    return x*f;
}

LL RDL(){
    LL x=0; char ch; int f=1;
    for (; ch < '0' || ch > '9'; ch = getchar())if (f == '-') f=-1;
    for (; ch >= '0' && ch <= '9'; ch = getchar())x = x*10 + ch-'0';
    return x*f;
}

int size, pos, used[11], cur[11];

void ppp(){
    if (pos == size){
        for (int i = 0; i < size; i++)printf("%d ", cur[i]);
        putchar('\n');
    }
    for (int i = 1; i <= size; i++){
        if (used[i])continue;
        used[i] = 1;
        cur[pos++] = i;
        ppp();
        pos--;
        used[i] = 0;
    }
}

int main(){
    pos = 0;
    scanf("%d",&size);
    ppp();
    return 0;
}

