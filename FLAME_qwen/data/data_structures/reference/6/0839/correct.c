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
int s[200];
int main() {
    int n=0;
    LL i, j;
    int in=read();
    while(in!=-1){
        if(in==0){
            if(n==0)printf("error ");
            else {
                printf("%d ",s[n]);
                n--;
            }
        }
        else{
            if(n==100)printf("error ");
            else{
                n++;
                scanf("%d",&s[n]);
            }
        }
        in=read();
    }
    return 0;
}
